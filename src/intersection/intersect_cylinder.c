/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/07 08:51:57 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

// static void print_point(char *name, t_point *to_print)
// {
// 	printf("%s: ", name);
// 	printf("[%f, %f, %f]\n", to_print->x_co, to_print->y_co, to_print->z_co);
// }

static t_intersect *intersection_cylinder_cap(t_ray *ray, t_point *center, t_cylinder *cylinder)
{
	t_plane		*cap_plane = plane_col_point_normal_dir(0x00FF00, center, cylinder->orientation); // direction could be inverted
	t_intersect	*cap_intersection = intersection_ray_plane(ray, cap_plane);
	if (cap_intersection->state == 0)
	{
		return(cap_intersection);
	}
	if (cap_intersection->state != 0)
	{
		t_vector	*disc_center_to_point_plane = vector_two_points(center, cap_intersection->point);
		double		distance_center_point2 = vector_dot(disc_center_to_point_plane, disc_center_to_point_plane);
		double		radius2 = cylinder->radius * cylinder->radius;
		if (distance_center_point2 > radius2)
		{
			cap_intersection->state = 0;
			return(cap_intersection);
		}
	}
	cap_intersection->state = 1;
	return(cap_intersection);
}

// Typedef of ray cylinder intersection
typedef struct s_ray_cylinder
{
	t_intersect	*base_intersection;
	t_direction	*reverse_cylinder_orientation;
	t_intersect	*top_cap_intersection;
	t_vector	*vector_ray;
	t_vector	*vector_cylinder;
	t_vector	*origin_base_center;
	t_vector	*base_to_top;
	t_point		*top_center;
	double		*quadratic_solutions;
	double		coefficient_a;
	double		coefficient_b;
	double		coefficient_c;
	double		distance_from_base;
}t_ray_cylinder;

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect	*intersection_data;

	t_ray_cylinder *t;
	// t_intersect	*base_intersection;
	// t_direction	*reverse_cylinder_orientation;
	// t_intersect	*top_cap_intersection;
	// t_vector	*vector_ray;
	// t_vector	*vector_cylinder;
	// t_vector	*origin_base_center;
	// t_vector	*base_to_top;
	// t_point		*top_center;
	// double		coefficient_a;
	// double		coefficient_b;
	// double		coefficient_c;
	// double		*quadratic_solutions;
	// double		distance_from_base;
	t = (t_ray_cylinder*)malloc(sizeof(t_ray_cylinder));
	intersection_data = (t_intersect*)malloc(sizeof(t_intersect));
	intersection_data->point = (t_point*)malloc(sizeof(t_point));
	t->distance_from_base = 0;
	intersection_data->point->x_co = 0;
	intersection_data->point->y_co = 0;
	intersection_data->point->z_co = 0;
	t->vector_ray = vector_scale_direction(1, ray->ray_dir);
	t->vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	t->origin_base_center = vector_two_points(ray->ray_orig, cylinder->centre);
	t->coefficient_a = vector_dot(t->vector_ray, t->vector_ray) -\
	pow(vector_dot(t->vector_ray, t->vector_cylinder), 2);
	t->coefficient_b = 2 * (vector_dot(t->vector_ray, t->origin_base_center) - (vector_dot(t->vector_ray, t->vector_cylinder) * vector_dot(t->origin_base_center, t->vector_cylinder)));
	t->coefficient_c = vector_dot(t->origin_base_center, t->origin_base_center) - pow(vector_dot(t->origin_base_center, t->vector_cylinder),2) - pow(cylinder->radius, 2);
	t->quadratic_solutions = solve_quadratic_real(t->coefficient_a, t->coefficient_b, t->coefficient_c);
	if(t->quadratic_solutions[0] == 0)
	{
		intersection_data->state = 0;
		return(intersection_data);
	}
	else if(t->quadratic_solutions[0] == 1 && t->quadratic_solutions[1] > t->quadratic_solutions[2])
	{
		intersection_data->point = get_intersection_point(ray, t->quadratic_solutions[1]);
		t->distance_from_base = vector_dot(t->vector_ray, t->vector_cylinder) * t->quadratic_solutions[1] + vector_dot(t->origin_base_center, t->vector_cylinder);
	}
	else if(t->quadratic_solutions[0] == 1 && t->quadratic_solutions[2] > t->quadratic_solutions[1])
	{
		intersection_data->point = get_intersection_point(ray, t->quadratic_solutions[2]);
		t->distance_from_base = vector_dot(t->vector_ray, t->vector_cylinder) * t->quadratic_solutions[2] + vector_dot(t->origin_base_center, t->vector_cylinder);
	}
	else if(t->quadratic_solutions[0] == 2)
	{
		intersection_data->point = get_intersection_point(ray, t->quadratic_solutions[1]);
		t->distance_from_base = vector_dot(t->vector_ray, t->vector_cylinder) * t->quadratic_solutions[1] + vector_dot(t->origin_base_center, t->vector_cylinder);
	}
	if (t->distance_from_base < 0)
	{
		t->base_intersection = intersection_cylinder_cap(ray, cylinder->centre, cylinder);
		if (t->base_intersection->state != 1)
		{
			intersection_data->state = 0;
			return(intersection_data);
		}
	}
	if (t->distance_from_base > cylinder->height)
	{
		t->reverse_cylinder_orientation = direction_components(-cylinder->orientation->x_comp, -cylinder->orientation->y_comp, -cylinder->orientation->z_comp);
		t->base_to_top = vector_scale_direction(cylinder->height, t->reverse_cylinder_orientation);
		t->top_center = point_point_vector(cylinder->centre, t->base_to_top);
		t->top_cap_intersection = intersection_cylinder_cap(ray, t->top_center, cylinder);
		if (t->top_cap_intersection->state != 1)
		{
			intersection_data->state = 0;
			return(intersection_data);
		}
	}
	intersection_data->state = 1;
	return(intersection_data);
}
