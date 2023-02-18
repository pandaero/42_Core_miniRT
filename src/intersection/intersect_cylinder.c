/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:14 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/18 10:10:16 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

#define A 0
#define B 1
#define C 2
#define UNDEFINED 42

//Function that initializes values for the intersection ray cylinder function
t_ray_cylinder	*t_ray_cylinder_init(t_ray *ray, t_cylinder *cylinder)
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
		return (t);
	}
	t->quadratic_solutions = solve_quadratic_real(t->coefficient);
	return (t);
}

//Initialize struct for cylinder intersection
t_intersect	*cylinder_intersection_creator(void)
{
	t_intersect	*intersection_data;

	intersection_data = (t_intersect *)malloc(sizeof(t_intersect));
	intersection_data->point = (t_point *)malloc(sizeof(t_point));
	intersection_data->state = UNDEFINED;
	intersection_data->point = NULL;
	return (intersection_data);
}
