/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/18 11:06:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED 42
#define TRUE 1
#define FALSE 0
#define A 0
#define B 1
#define C 2

void	intersection_and_distance(t_intersect *intersection_data, \
double quadratic_solution, t_ray_cylinder *t, t_ray *ray)
{
	intersection_data->point = get_intersection_point(ray, \
	quadratic_solution);
	t->distance_from_base = vector_dot(t->vector_ray, \
	t->vector_cylinder) * quadratic_solution + \
	vector_dot(t->origin_base_center, t->vector_cylinder);
}

//Function that determines distance from base to point of intersection
void	measure_distance(t_ray *ray, t_ray_cylinder *t, \
t_intersect *i_data)
{
	if (t->quadratic_solutions[0] == 1 && t->quadratic_solutions[1] >= \
	t->quadratic_solutions[2])
		intersection_and_distance(i_data, t->quadratic_solutions[2], t, ray);
	else if (t->quadratic_solutions[0] == 1 && t->quadratic_solutions[2] >= \
	t->quadratic_solutions[1])
		intersection_and_distance(i_data, t->quadratic_solutions[1], t, ray);
	else if (t->quadratic_solutions[0] == 2)
	{
		i_data->point = get_intersection_point(ray, \
		t->quadratic_solutions[1]);
		t->distance_from_base = vector_dot(t->vector_ray, \
		t->vector_cylinder) * t->quadratic_solutions[1] + \
		vector_dot(t->origin_base_center, t->vector_cylinder);
	}
}

//
t_point	*get_top_center(t_ray_cylinder *t, t_cylinder *cylinder)
{
	t->reverse_cylinder_orientation = \
	reverse_direction(cylinder->orientation);
	t->base_to_top = vector_scale_direction(cylinder->height, \
	t->reverse_cylinder_orientation);
	return (point_point_vector(cylinder->centre, t->base_to_top));
}

//
static void	check_cap_intersection(t_ray *ray, t_cylinder *c, \
t_intersect *intersection_data, t_ray_cylinder *t)
{
	if (t->distance_from_base < 0)
	{
		t->base_intersection = intersection_cylinder_cap(ray, c->centre, c);
		if (t->base_intersection->state != 1)
			intersection_data->state = FALSE;
		free_intersection(t->base_intersection);
	}
	if (t->distance_from_base > c->height)
	{
		t->top_center = get_top_center(t, c);
		t->top_intersection = intersection_cylinder_cap(ray, t->top_center, c);
		if (t->top_intersection->state != 1)
			intersection_data->state = FALSE;
		free_intersection(t->top_intersection);
		free_point(t->top_center);
	}
}

//
t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *c)
{
	t_intersect		*intersection_data;
	t_ray_cylinder	*t;

	intersection_data = return_data_init();
	t = t_ray_cylinder_init(ray, c);
	if (t->quadratic_solutions[0] == 0)
		intersection_data->state = FALSE;
	measure_distance(ray, t, intersection_data);
	check_cap_intersection(ray, c, intersection_data, t);
	if (intersection_data->state == UNDEFINED)
		intersection_data->state = TRUE;
	free_cylinder_values(t);
	return (intersection_data);
}
