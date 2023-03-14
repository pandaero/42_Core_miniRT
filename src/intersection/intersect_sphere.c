/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 20:01:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

//Function works out an intersection in the case of a single solution.
static void	sphere_single(t_ray ray, t_sphere sphere, t_intersect *itsct, \
																t_quad_sol soln)
{
	itsct->state = INTERSECTED;
	itsct->distance = soln.first;
	itsct->point = point_ray_distance(ray, itsct->distance);
	itsct->normal = direction_two_points(sphere.centre, itsct->point);
	if (direction_dot(itsct->normal, ray.ray_dir) > 0)
		itsct->normal = direction_reverse(itsct->normal);
}

//Function works out an intersection in the case of two solutions.
static void	sphere_single(t_ray ray, t_sphere sphere, t_intersect *itsct, \
																t_quad_sol soln)
{
	if (soln.first < 0 && soln.second < 0)
		itsct->state = MISSED;
	else if ((soln.first > 0 || soln.second > 0) && \
				(soln.first < 0 || soln.second < 0))
	{
		itsct->state = INTERSECTED;
		itsct->distance = fmax(soln.first, soln.second);
	}
	else
	{
		itsct->state = INTERSECTED;
		itsct->distance = fmin(soln.first, soln.second);
	}
	itsct->point = point_ray_distance(ray, itsct->distance);
	itsct->normal = direction_two_points(sphere.centre, itsct->point);
	if (direction_dot(itsct->normal, ray.ray_dir) > 0)
		itsct->normal = direction_reverse(itsct->normal);
}												

//Function works out the intersection between a ray and a sphere.
t_intersect	intersection_ray_sphere(t_ray ray, t_sphere sphere)
{
	t_itsct_sphere	is;
	t_quad_cof		quad;
	t_quad_sol		soln;
	t_intersect		itsct;

	is.ray_to_ctr = vector_two_points(ray.ray_orig, sphere.centre);
	is.vec_ray_dir = vector_scale_direction(1, ray.ray_dir);
	quad.squared = vector_dot(is.vec_ray_dir, is.vec_ray_dir);
	quad.linear = 2 * vector_dot(is.vec_ray_dir, is.ray_to_ctr);
	quad.constant = fabs(vector_dot(is.ray_to_ctr, is.ray_to_ctr)) - \
														pow(sphere.radius, 2);
	soln = solve_quadratic(quad);
	soln.first *= -1;
	soln.second *= -1;
	itsct.state = UNCALCULATED;
	itsct.distance = -DBL_MAX;
	if (soln.sol == NO_REAL)
		itsct.state = MISSED;
	else if (soln.sol == ONE)
		sphere_single(ray, sphere, &itsct, soln);
	else
		sphere_double(ray, sphere, &itsct, soln);
	return (itsct);
}
