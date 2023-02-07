/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/07 14:03:22 by pbiederm         ###   ########.fr       */
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

static t_intersect	*intersection_cylinder_cap(t_ray *ray, \
t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_intersect		*cap_intersection;

	t = (t_cylinder_cap *)malloc(sizeof(t_cylinder_cap));
	t->cap_plane = plane_col_point_normal_dir(0x00FF00, \
	center, cylinder->orientation);
	cap_intersection = intersection_ray_plane(ray, t->cap_plane);
	t->disc_center_to_point_plane = NULL;
	if (cap_intersection->state == 0)
		return (cap_intersection);
	if (cap_intersection->state != 0)
	{
		t->disc_center_to_point_plane = vector_two_points(center, \
		cap_intersection->point);
		t->distance_center_point_sq = vector_dot(t->disc_center_to_point_plane, \
		t->disc_center_to_point_plane);
		t->radius_sq = cylinder->radius * cylinder->radius;
		if (t->distance_center_point_sq > t->radius_sq)
		{
			cap_intersection->state = 0;
			return (cap_intersection);
		}
	}
	cap_intersection->state = 1;
	return (cap_intersection);
}

//Function that initializes values for the intersection ray cylinder function
static t_ray_cylinder	*t_ray_cylinder_init(t_ray *ray, t_cylinder *cylinder)
{
	t_ray_cylinder	*t;

	t = (t_ray_cylinder *)malloc(sizeof(t_ray_cylinder));
	t->distance_from_base = 0;
	t->vector_ray = vector_scale_direction(1, ray->ray_dir);
	t->vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	t->origin_base_center = vector_two_points(ray->ray_orig, cylinder->centre);
	t->coefficient = (double *)malloc(3 * sizeof(double));
	t->coefficient[A] = vector_dot(t->vector_ray, t->vector_ray) - \
	pow(vector_dot(t->vector_ray, t->vector_cylinder), 2);
	t->coefficient[B] = 2 * (vector_dot(t->vector_ray, t->origin_base_center) \
	- (vector_dot(t->vector_ray, t->vector_cylinder) * \
	vector_dot(t->origin_base_center, t->vector_cylinder)));
	t->coefficient[C] = vector_dot(t->origin_base_center, \
	t->origin_base_center) - pow(vector_dot(t->origin_base_center, \
	t->vector_cylinder), 2) - pow(cylinder->radius, 2);
	if (t->coefficient[A] == 0)
	{
		t->quadratic_solutions[0] = 0;
		t->quadratic_solutions[1] = 0;
		t->quadratic_solutions[2] = 0;
		return(t);
	}
	t->quadratic_solutions = solve_quadratic_real(t->coefficient);
	return (t);
}

void	free_cylinder_values(t_ray_cylinder *t)
{
	free(t->vector_ray);
	free(t->vector_cylinder);
	free(t->origin_base_center);
	free(t->quadratic_solutions);
	free(t->coefficient);
	free(t);
}

static void	intersection_and_distance(t_intersect *intersection_data, \
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
	if (t->quadratic_solutions[0] == 1 && t->quadratic_solutions[1] > \
	t->quadratic_solutions[2])
		intersection_and_distance(i_data, t->quadratic_solutions[1], t, ray);
	else if (t->quadratic_solutions[0] == 1 && t->quadratic_solutions[2] > \
	t->quadratic_solutions[1])
		intersection_and_distance(i_data, t->quadratic_solutions[2], t, ray);
	else if (t->quadratic_solutions[0] == 2)
	{
		i_data->point = get_intersection_point(ray, \
		t->quadratic_solutions[1]);
		t->distance_from_base = vector_dot(t->vector_ray, \
		t->vector_cylinder) * t->quadratic_solutions[1] + \
		vector_dot(t->origin_base_center, t->vector_cylinder);
	}
}

//Initialize struct for cylinder intersection
static	t_intersect	*return_data_init(void)
{
	t_intersect	*intersection_data;

	intersection_data = (t_intersect *)malloc(sizeof(t_intersect));
	intersection_data->point = (t_point *)malloc(sizeof(t_point));
	intersection_data->state = UNDEFINED;
	intersection_data->point->x_co = 0;
	intersection_data->point->y_co = 0;
	intersection_data->point->z_co = 0;
	return (intersection_data);
}

static t_direction *reverse_direction(t_direction *direction)
{
	t_direction	*reverse_direction;

	reverse_direction = direction_components(\
	-direction->x_comp, \
	-direction->y_comp, \
	-direction->z_comp);
	return (reverse_direction);
}

t_point *get_top_center(t_ray_cylinder *t, t_cylinder* cylinder)
{
	t->reverse_cylinder_orientation = \
	reverse_direction(cylinder->orientation);
	t->base_to_top = vector_scale_direction(cylinder->height, \
	t->reverse_cylinder_orientation);
	return (point_point_vector(cylinder->centre, t->base_to_top));
}

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *c)
{
	t_intersect		*intersection_data;
	t_ray_cylinder	*t;

	intersection_data = return_data_init();
	t = t_ray_cylinder_init(ray, c);
	if (t->quadratic_solutions[0] == 0)
		intersection_data->state = FALSE;
	measure_distance(ray, t, intersection_data);
	if (t->distance_from_base < 0)
	{
		t->base_intersection = intersection_cylinder_cap(ray, c->centre, c);
		if (t->base_intersection->state != 1)
			intersection_data->state = FALSE;
	}
	if (t->distance_from_base > c->height)
	{
		t->top_center = get_top_center(t, c);
		t->top_intersection = intersection_cylinder_cap(ray, t->top_center, c);
		if (t->top_intersection->state != 1)
			intersection_data->state = FALSE;
	}
	if (intersection_data->state == UNDEFINED)
		intersection_data->state = TRUE;
	free_cylinder_values(t);
	return (intersection_data);
}
