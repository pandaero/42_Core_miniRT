/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:14 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/24 12:01:30 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>
#define A 0
#define B 1
#define C 2
//tests
#include <stdio.h>

//Function checks for a ray intersection with an infinite cylinder.
static void	infinite_cylinder_intersection(t_ray_cylinder *t, \
								t_intersect *cylinder_intersect, t_ray *ray)
{
	if ((t->quadratic_result[0] == 2 || t->quadratic_result[0] == 2)&& \
	t->quadratic_result[1] < 0 && t->quadratic_result[2] < 0)
		cylinder_intersect->state = MISSED;
	else if (t->quadratic_result[0] == 2 && \
	t->quadratic_result[1] > 0 && t->quadratic_result[2] > 0)
	{
		t->point_infinite_cylinder = \
		get_intersection_point(ray, t->quadratic_result[1]);
	}
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[1] < 0 && \
	t->quadratic_result[2] > 0)
	{
		t->point_infinite_cylinder = \
		get_intersection_point(ray, t->quadratic_result[2]);
	}
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[1] > 0 && \
	t->quadratic_result[2] < 0)
	{
		t->point_infinite_cylinder = \
		get_intersection_point(ray, t->quadratic_result[1]);
	}
	else if (t->quadratic_result[0] == 1 && \
	t->quadratic_result[2] < t->quadratic_result[1] && \
	t->quadratic_result[2] > 0)
	{
		t->point_infinite_cylinder = \
		get_intersection_point(ray, t->quadratic_result[2]);
		// cylinder_intersect->distance = t->quadratic_result[2];
	}
	else if ((t->quadratic_result[0] == 1) && \
	(t->quadratic_result[1] < t->quadratic_result[2]) && \
	(t->quadratic_result[1] > 0))
	{
		t->point_infinite_cylinder = \
		get_intersection_point(ray, t->quadratic_result[1]);
		// cylinder_intersect->distance = t->quadratic_result[1];
	}
}

//Calculates coefficients for the cylinder ray intersection and solves quadratic
static double	*employ_quadratic_equation(t_ray_cylinder *t, \
											t_cylinder *cylinder)
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

//Function creates variables for cylinder intersection test
static t_ray_cylinder	*cylinder_init(t_ray *ray, t_cylinder *cylinder)
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
	t->point_infinite_cylinder = NULL;
	t->point_cap = NULL;
	t->point_infinite_cylinder = NULL;
	t->dist_cap = DBL_MAX;
	t->dist_infinite_cylinder = DBL_MAX;
	return (t);
}

//Frees a struct of function cylinder ray intersection
static void	free_t_ray_cylinder(t_ray_cylinder *t)
{
	if (t->point_cap != NULL)
		free_point(t->point_cap);
	if (t->point_infinite_cylinder != NULL)
		free_point(t->point_infinite_cylinder);
	free_vector(t->vector_ray_origin_base_center);
	free_vector(t->vector_cylinder);
	free_vector(t->vector_ray);
	free(t->quadratic_result);
	free(t);
}

static void	determine_point(t_ray_cylinder *t, t_intersect *cylinder_intersect)
{
	if (t->dist_infinite_cylinder < t->dist_cap)
	{
		cylinder_intersect->point = point_copy(t->point_infinite_cylinder);
		// printf("inf_cyl_dist: [%f] ", t->dist_infinite_cylinder);
		// printf("dist_cap: [%f] ", t->dist_cap);
		// printf("mantle point: [%f, %f, %f]\n", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);
		cylinder_intersect->distance = t->dist_infinite_cylinder;
	}
	else if(t->dist_cap < t->dist_infinite_cylinder)
	{
		cylinder_intersect->point = point_copy(t->point_cap);
		// printf("cap point: [%f, %f, %f]\n", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);
		cylinder_intersect->distance = t->dist_cap;
	}
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
	if (t->point_infinite_cylinder != NULL)
	{
		cylinder_mantle_caps(t, cylinder_intersect, ray, cylinder);
	}
	if (cylinder_intersect->state == INTERSECTED)
	{
		determine_point(t, cylinder_intersect);
		free_t_ray_cylinder(t);
		return (cylinder_intersect);
	}
	cylinder_intersect->state = MISSED;
	free_t_ray_cylinder(t);
	return (cylinder_intersect);
}
