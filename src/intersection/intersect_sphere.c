/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 17:27:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

//Function assigns the intersection point and surface normal for the point.
static void	sphere_intersection_point_normal(t_ray *ray, t_sphere *sphere, \
											t_itsct_sphere *is)
{
	t_direction	*temp;

	is->itsct->point = point_ray_distance(ray, is->itsct->distance);
	is->itsct->normal = direction_two_points(sphere->centre, is->itsct->point);
	if (direction_dot(is->itsct->normal, ray->ray_dir) > 0)
	{
		temp = is->itsct->normal;
		is->itsct->normal = direction_reverse(temp);
		free(temp);
	}
}

//Function handles the case where there are two solutions for ray-sphere itsct.
static void	sphere_intersection_two(t_ray *ray, t_sphere *sphere, \
									t_itsct_sphere *is)
{
	if (is->soln->first < 0 && is->soln->second < 0)
	{
		is->itsct->state = MISSED;
		return ;
	}
	else if ((is->soln->first > 0 || is->soln->second > 0) && \
			(is->soln->first < 0 || is->soln->second < 0))
	{
		is->itsct->state = INTERSECTED;
		is->itsct->distance = fmax(is->soln->first, is->soln->second);
	}
	else
	{
		is->itsct->state = INTERSECTED;
		is->itsct->distance = fmin(is->soln->first, is->soln->second);
	}
	sphere_intersection_point_normal(ray, sphere, is);
}

//Function works out the intersection between a ray and a sphere.
t_intersect	*intersection_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	t_itsct_sphere	is;
	t_quad_cof		quad;
	t_quad_sol		soln;

	is.ray_to_ctr = vector_two_points(ray->ray_orig, sphere->centre);
	is.vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	quad.squared = vector_dot(is.vec_ray_dir, is.vec_ray_dir);
	quad.linear = 2 * vector_dot(is.vec_ray_dir, is.ray_to_ctr);
	quad.constant = fabs(vector_dot(is.ray_to_ctr, is.ray_to_ctr)) - \
						pow(sphere->radius, 2);
	soln = solve_quadratic(quad);
	is.quad = &quad;
	is.soln = &soln;
	is.itsct = intersect_create();
	if (soln.sol == NO_REAL)
		is.itsct->state = MISSED;
	else if (soln.sol == ONE)
	{
		is.itsct->state = INTERSECTED;
		is.itsct->distance = -quad.linear / (2 * quad.squared);
		sphere_intersection_point_normal(ray, sphere, &is);
	}
	else
		sphere_intersection_two(ray, sphere, &is);
	return (is.itsct);
}
