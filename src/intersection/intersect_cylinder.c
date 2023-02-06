/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/06 21:38:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect	*intersection_data;
	t_vector	*vector_ray;
	t_vector	*vector_cylinder;
	t_vector	*origin_base_center;
	double		coefficient_a;
	double		coefficient_b;
	double		coefficient_c;
	double		*quadratic_solutions;
	double		distance_from_base;

	distance_from_base = 0;
	intersection_data = (t_intersect*)malloc(sizeof(t_intersect));
	intersection_data->point = (t_point*)malloc(sizeof(t_point));
	intersection_data->point->x_co = 0;
	intersection_data->point->y_co = 0;
	intersection_data->point->z_co = 0;
	vector_ray = vector_scale_direction(1, ray->ray_dir);
	vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	origin_base_center = vector_two_points(ray->ray_orig, cylinder->centre);
	coefficient_a = vector_dot(vector_ray, vector_ray) -\
	pow(vector_dot(vector_ray, vector_cylinder), 2);
	coefficient_b = 2 * (vector_dot(vector_ray, origin_base_center) - (vector_dot(vector_ray, vector_cylinder) * vector_dot(origin_base_center, vector_cylinder)));
	coefficient_c = vector_dot(origin_base_center, origin_base_center) - pow(vector_dot(origin_base_center, vector_cylinder),2) - pow(cylinder->radius, 2);
	quadratic_solutions = solve_quadratic_real(coefficient_a, coefficient_b, coefficient_c);
	if(quadratic_solutions[0] == 0)
	{
		intersection_data->state = 0;
		return(intersection_data);
	}
	else if(quadratic_solutions[0] == 1 && quadratic_solutions[1] > quadratic_solutions[2])
	{
		intersection_data->point = get_intersection_point(ray, quadratic_solutions[1]);
		distance_from_base = vector_dot(vector_ray, vector_cylinder) * quadratic_solutions[1] + vector_dot(origin_base_center, vector_cylinder);
	}
	else if(quadratic_solutions[0] == 1 && quadratic_solutions[2] > quadratic_solutions[1])
	{
		intersection_data->point = get_intersection_point(ray, quadratic_solutions[2]);
		distance_from_base = vector_dot(vector_ray, vector_cylinder) * quadratic_solutions[2] + vector_dot(origin_base_center, vector_cylinder);
	}
	else if(quadratic_solutions[0] == 2)
	{
		intersection_data->point = get_intersection_point(ray, quadratic_solutions[1]);
		distance_from_base = vector_dot(vector_ray, vector_cylinder) * quadratic_solutions[1] + vector_dot(origin_base_center, vector_cylinder);
	}
	if (distance_from_base < 0)
	{
	 	// base cap
		t_plane		*lower_cap = plane_col_point_normal_dir(0x00FF00, cylinder->centre, cylinder->orientation); // direction could be inverted
		t_intersect	*cap_intersection = intersection_ray_plane(ray, lower_cap);
		if (cap_intersection->state != 0)
		{
			t_vector	*disc_center_to_point_plane = vector_two_points(cylinder->centre, cap_intersection->point);
			double		distance_center_point2 = vector_dot(disc_center_to_point_plane, disc_center_to_point_plane);
			double		radius2 = cylinder->radius * cylinder->radius;
			if (distance_center_point2 > radius2)
			{
				free(intersection_data->point);
				free(intersection_data);
				cap_intersection->state = 0;
				return(cap_intersection);
			}
		}
		if (cap_intersection->state == 0)
		{
			free(cap_intersection->point);
			free(cap_intersection);
			intersection_data->state = 0;
			return(intersection_data);
		}
		// base cap
	}
	if (distance_from_base > cylinder->height)
	{
		intersection_data->state = 0;
		return (intersection_data);
	}
	intersection_data->state = 1;
	free(quadratic_solutions);
	free(vector_ray);
	free(vector_cylinder);
	free(origin_base_center);
	return(intersection_data);
}
