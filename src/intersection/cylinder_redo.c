/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_redo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:38:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/18 19:49:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

#define A 0
#define B 1
#define C 2

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect	*cylinder_intersect;
	t_vector 	*vector_ray;
	t_vector	*vector_cylinder;
	t_vector	*vector_ray_origin_base_center;
	double		coefficient[3];
	double		*quadratic_result;
	
	cylinder_intersect = intersect_create();
	vector_ray = vector_scale_direction(1, ray->ray_dir);
	vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	vector_ray_origin_base_center = vector_two_points(cylinder->centre, ray->ray_orig);
	coefficient[A] = vector_dot(vector_ray, vector_ray) - pow(vector_dot(vector_ray, vector_cylinder), 2);
	coefficient[B] = 2 * (vector_dot(vector_ray, vector_ray_origin_base_center) - (vector_dot(vector_ray, vector_cylinder) * vector_dot(vector_ray_origin_base_center, vector_cylinder)));
	coefficient[C] = vector_dot(vector_ray_origin_base_center, vector_ray_origin_base_center) - pow(vector_dot(vector_ray_origin_base_center, vector_cylinder), 2) - pow(cylinder->radius, 2);
	quadratic_result = malloc(3 * sizeof(double));
	quadratic_result = solve_quadratic_real(coefficient);
	printf ("q_result [%f, %f, %f]\n", quadratic_result[0], quadratic_result[1], quadratic_result[2]);
	if ((quadratic_result[0] == 1) && (quadratic_result[2] < quadratic_result[1] )&& (quadratic_result[2] > 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[2]);
		// printf("cylinder points: [%f, %f, %f]", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);
		cylinder_intersect->state = 1;
		return(cylinder_intersect);
		
	}
	if ((quadratic_result[0] == 1) && (quadratic_result[1] < quadratic_result[2]) && (quadratic_result[1] > 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[2]);
		// printf("cylinder points: [%f, %f, %f]", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);
		cylinder_intersect->state = 1;
		return(cylinder_intersect);
	}
	cylinder_intersect->state = 0;
	return(cylinder_intersect);
	
	
}