/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:38:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/20 17:11:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
// #include <stdio.h>

#define A 0
#define B 1
#define C 2

//Function creates variables for cylinder intersection test
t_ray_cylinder	*cylinder_init(t_ray *ray, t_cylinder *cylinder)
{
	t_ray_cylinder	*t;

	t = (t_ray_cylinder *)malloc(sizeof(t_ray_cylinder));
	t->vector_ray = vector_scale_direction(1, ray->ray_dir);
	t->vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	t->vector_ray_origin_base_center = \
	vector_two_points(cylinder->centre, ray->ray_orig);
	t->distance_cylinder_axis = -1;
	t->coefficient[0] = 0;
	t->coefficient[1] = -1;
	t->coefficient[2] = -1;
	t->quadratic_result = NULL;
	return (t);
}

//Calculates coefficients for the cylinder ray intersection and solves quadratic
double	*employ_quadratic_equation(t_ray_cylinder *t, t_cylinder *cylinder)
{
	t->coefficient[A] = vector_dot(t->vector_ray, t->vector_ray) - \
	pow(vector_dot(t->vector_ray, t->vector_cylinder), 2);
	t->coefficient[B] = 2 * \
	(vector_dot(t->vector_ray, t->vector_ray_origin_base_center) - \
	(vector_dot(t->vector_ray, t->vector_cylinder) * \
	vector_dot(t->vector_ray_origin_base_center, t->vector_cylinder)));
	t->coefficient[C] = vector_dot(t->vector_ray_origin_base_center, \
	t->vector_ray_origin_base_center) - \
	pow(vector_dot(t->vector_ray_origin_base_center, \
	t->vector_cylinder), 2) - pow(cylinder->radius, 2);
	return (solve_quadratic_real(t->coefficient));
}

void	infinite_cylinder_intersection(t_ray_cylinder *t, \
							t_intersect *cylinder_intersect, t_ray *ray)
{
	if (t->quadratic_result[0] == 2 && \
	t->quadratic_result[1] > 0 && t->quadratic_result[2] > 0)
		cylinder_intersect->point = \
		get_intersection_point(ray, t->quadratic_result[1]);
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[1] > 0 && \
	t->quadratic_result[2] < 0)
		cylinder_intersect->point = \
		get_intersection_point(ray, t->quadratic_result[1]);
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[1] > 0 && \
	t->quadratic_result[2] < 0)
		cylinder_intersect->point = \
		get_intersection_point(ray, t->quadratic_result[1]);
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[2] < t->quadratic_result[1] && \
	t->quadratic_result[2] > 0)
		cylinder_intersect->point = \
		get_intersection_point(ray, t->quadratic_result[2]);
	else if ((t->quadratic_result[0] == 1) && \
	(t->quadratic_result[1] < t->quadratic_result[2]) && \
	(t->quadratic_result[1] > 0))
		cylinder_intersect->point = \
		get_intersection_point(ray, t->quadratic_result[1]);
}

/*Function determines if there is an 
intersection with a base cap of the cylinder*/
t_intersect	*base_cap_intersection(t_cylinder *cylinder, \
t_ray *ray, t_intersect *cylinder_intersect)
{
	t_vector	*vector_centroid_base = vector_scale_direction((-1) * (cylinder->height / 2), cylinder->orientation);
	t_point		*point_center_base = point_point_vector(cylinder->centre, vector_centroid_base);
	t_plane		*plane_base_cylinder = plane_col_point_normal_dir(cylinder->colour, point_center_base, cylinder->orientation);
	t_intersect	*intersect_base_plane = intersection_ray_plane(ray, plane_base_cylinder);
	
	
	
	
	
	if (intersect_base_plane->state == 1)
	{
		t_vector	*vector_base_intersection = vector_two_points(point_center_base, intersect_base_plane->point);
		double		d_sq = vector_dot(vector_base_intersection, vector_base_intersection);
		free_vector(vector_base_intersection);
		double		radius_sq = pow(cylinder->radius, 2);
		if (d_sq <= radius_sq)
		{
			cylinder_intersect->state = 1;
			cylinder_intersect->distance = distance_two_points(ray->ray_orig, cylinder_intersect->point);
		}
	}
	free_plane(plane_base_cylinder);
	free_point(point_center_base);
	free_vector(vector_centroid_base);
	return (intersect_base_plane);
}

t_intersect *top_cap_intersection(t_cylinder *cylinder, t_ray *ray, t_intersect *cylinder_intersect)
{
	t_vector	*vector_centroid_top = vector_scale_direction((cylinder->height / 2), cylinder->orientation);
	t_point		*point_center_top = point_point_vector(cylinder->centre, vector_centroid_top);
	t_plane		*plane_top_cylinder = plane_col_point_normal_dir(cylinder->colour, point_center_top, cylinder->orientation);
	t_intersect	*intersect_top_plane = intersection_ray_plane(ray, plane_top_cylinder);
	if (intersect_top_plane->state == 1)
	{
		t_vector	*vector_top_intersection = vector_two_points(point_center_top, intersect_top_plane->point);
		double		d_sq = vector_dot(vector_top_intersection, vector_top_intersection);
		free_vector(vector_top_intersection);
		double		radius_sq = pow(cylinder->radius, 2);
		if (d_sq <= radius_sq)
		{
			cylinder_intersect->state = 1;
		}
	}
	free_plane(plane_top_cylinder);
	free_point(point_center_top);
	free_vector(vector_centroid_top);
	return (intersect_top_plane);
}

//Determining which cap to render, getting point and distance to cylinder_intersect
void determine_cap_distance(t_intersect *intersect_base_plane, t_intersect *intersect_top_plane, t_intersect *cylinder_intersect)
{
	if(intersect_base_plane->distance >= 0 && intersect_top_plane->distance < 0 && cylinder_intersect->state == 1)
	{
		cylinder_intersect->point = point_copy(intersect_base_plane->point);
		cylinder_intersect->distance = intersect_base_plane->distance;
	}
	else if(intersect_top_plane->distance >= 0 && intersect_base_plane->distance < 0 && cylinder_intersect->state == 1)
	{
		cylinder_intersect->point = point_copy(intersect_top_plane->point);
		cylinder_intersect->distance = intersect_top_plane->distance;
	}
	else if(intersect_base_plane->distance >= 0 && intersect_base_plane->distance < intersect_top_plane->distance && cylinder_intersect->state == 1)
	{
		cylinder_intersect->point = point_copy(intersect_base_plane->point);
		cylinder_intersect->distance = intersect_base_plane->distance;
	}
	else if(intersect_top_plane->distance >= 0 && intersect_top_plane->distance < intersect_base_plane->distance && cylinder_intersect->state == 1)
	{
		cylinder_intersect->point = point_copy(intersect_top_plane->point);
		cylinder_intersect->distance = intersect_top_plane->distance;
	}
}

// Function recieves data of an infinite cylinder and shapes finite cylinder with caps
void cylinder_mantle_caps(t_ray_cylinder *t, t_intersect *cylinder_intersect, t_ray *ray, t_cylinder *cylinder)
{
	t_intersect *intersect_base_plane;
	t_intersect *intersect_top_plane;

	intersect_base_plane = NULL;
	intersect_top_plane = NULL;
	t->distance_cylinder_axis = 2 * sqrt(fabs((pow(cylinder->radius,2) - pow(distance_two_points(cylinder->centre, cylinder_intersect->point),2))));
	if (t->distance_cylinder_axis >= 0)
	{
		if (t->distance_cylinder_axis <= cylinder->height)
		{
			cylinder_intersect->state = 1;
			cylinder_intersect->distance = distance_two_points(ray->ray_orig, cylinder_intersect->point);
		}
		else
		{
			//caps intersection below
			intersect_base_plane = base_cap_intersection(cylinder,ray, cylinder_intersect);
			intersect_top_plane = top_cap_intersection(cylinder,ray ,cylinder_intersect);
			determine_cap_distance(intersect_base_plane, intersect_top_plane, cylinder_intersect);
			free_intersection(intersect_base_plane);
			free_intersection(intersect_top_plane);
			if(cylinder_intersect->state != 1)
			{
				free_point(cylinder_intersect->point);
				cylinder_intersect->point = NULL;
			}	
		}
	}
}

//Frees a struct of function cylinder ray intersection
void free_t_ray_cylinder(t_ray_cylinder *t)
{
	free_vector(t->vector_ray_origin_base_center);
	free_vector(t->vector_cylinder);
	free_vector(t->vector_ray);
	free(t->quadratic_result);
	free(t);
}

//Function that determines ray, cylinder intersection.
t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_ray_cylinder	*t;
	t_intersect		*cylinder_intersect;
	
	t = cylinder_init(ray, cylinder);
	cylinder_intersect = intersect_create();
	t->quadratic_result = employ_quadratic_equation(t, cylinder);
	infinite_cylinder_intersection(t, cylinder_intersect, ray);
	if(cylinder_intersect->point != NULL)
	{		
		cylinder_mantle_caps(t, cylinder_intersect, ray, cylinder);
	}
	if(cylinder_intersect->state == 1)
	{
		free_t_ray_cylinder(t);
		return(cylinder_intersect);
	}
	cylinder_intersect->state = 0;
	free_t_ray_cylinder(t);
	return(cylinder_intersect);
}
