/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/22 19:19:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//Function helps ray sphere get the distance of between ray and sphere.
static double	get_distance(t_vector *vec_ray_dir, \
t_vector *rp, t_sphere *sphere)
{
	double	distance;
	double	tmp;

	distance = (vector_dot(rp, vec_ray_dir)) - \
			sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
			(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
	tmp = (vector_dot(rp, vec_ray_dir)) + \
			sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
			(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
	if (tmp < distance)
		distance = tmp;
	return (distance);
}

double abs_value(double value)
{
	if (value < 0)
		value = value * (-1);
	return (value);
}

//Function works out the intersection between a ray and a sphere.
t_intersect	*intersection_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vector	*vec_ray_dir;
	t_vector	*rp;
	t_rs		rs;
	t_intersect	*intersection;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	rp = vector_two_points(ray->ray_orig, sphere->centre);
	rs.y = pow(vector_dot(rp, vec_ray_dir), 2) - \
	(vector_dot(rp, rp)) + pow(sphere->radius, 2);
	intersection = intersect_create();
	if (rs.y >= 0 && vector_dot(rp, vec_ray_dir) > 0)
	{
		intersection->state = INTERSECTED;
		intersection->distance = get_distance(vec_ray_dir, rp, sphere);
		intersection->point = point_ray_distance(ray, intersection->distance);
		// if(abs_value(intersection->point->x_co < 0.25) && abs_value(intersection->point->z_co < 0.25))
		// {
		// 	printf("sphere point: [%f, %f, %f] | ", intersection->point->x_co, \
		// 	intersection->point->y_co, intersection->point->z_co);
		// 	printf("sphere dist: %f | \n", intersection->distance);
		// }
	}
	if (intersection->state != INTERSECTED)
		intersection->state = MISSED;
	free_vector(rp);
	free_vector(vec_ray_dir);
	return (intersection);
}
