/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 00:36:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

//Function assigns the intersection point and surface normal for the point.
static void	sphere_intersection_point_normal(t_ray ray, t_sphere sphere, \
															t_intersect *itsct)
{
	itsct->point = point_ray_distance(ray, itsct->distance);
	itsct->normal = direction_two_points(sphere.centre, itsct->point);
	if (direction_dot(itsct->normal, ray.ray_dir) > 0)
		itsct->normal = direction_reverse(itsct->normal);
}

//Function handles the case where there are two solutions for ray-sphere itsct.
static void	sphere_intersection_two(t_ray ray, t_sphere sphere, \
										t_itsct_sphere *is, t_intersect *itsct)
{
	if (is->soln.first < 0 && is->soln.second < 0)
	{
		itsct->state = MISSED;
		return ;
	}
	else if ((is->soln.first > 0 || is->soln.second > 0) && \
			(is->soln.first < 0 || is->soln.second < 0))
	{
		itsct->state = INTERSECTED;
		itsct->distance = fmax(is->soln.first, is->soln.second);
	}
	else
	{
		itsct->state = INTERSECTED;
        itsct->distance = fmin(is->soln.first, is->soln.second);
	}
	sphere_intersection_point_normal(ray, sphere, itsct);
}

// //Function performs a sign change and assigns solutions to intersect solution.
// static void	modify_sphere_quad(t_quad_sol *sol, t_itsct_sphere *is)
// {
// 	sol->first *= -1;
// 	sol->second *= -1;
// }

//Function works out the intersection between a ray and a sphere.
t_intersect	intersection_ray_sphere(t_ray ray, t_sphere sphere)
{
	t_itsct_sphere	is;
	t_quad_cof		quad;
	t_quad_sol		soln;
    t_intersect     itsct;

	is.ray_to_ctr = vector_two_points(ray.ray_orig, sphere.centre);
	is.vec_ray_dir = vector_scale_direction(1, ray.ray_dir);
	quad.squared = vector_dot(is.vec_ray_dir, is.vec_ray_dir);
	quad.linear = 2 * vector_dot(is.vec_ray_dir, is.ray_to_ctr);
	quad.constant = fabs(vector_dot(is.ray_to_ctr, is.ray_to_ctr)) - pow(sphere.radius, 2);
	soln = solve_quadratic(quad);
	soln.first *= -1;
	soln.second *= -1;
	if (soln.sol == NO_REAL)
		itsct.state = MISSED;
	else if (soln.sol == ONE)
	{
		itsct.state = INTERSECTED;
		itsct.distance = soln.first;
		sphere_intersection_point_normal(ray, sphere, &itsct);
	}
	else
		sphere_intersection_two(ray, sphere, &is, &itsct);
	return (itsct);
}
