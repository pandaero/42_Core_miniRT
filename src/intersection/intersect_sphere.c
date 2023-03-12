/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/12 02:45:13 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

//Function assigns the intersection point and surface normal for the point.
static void	sphere_intersection_point_normal(t_ray *ray, t_sphere *sphere, \
											t_intersect *itsct)
{
	t_direction	*temp;

	itsct->point = point_ray_distance(ray, itsct->distance);
	itsct->normal = direction_two_points(sphere->centre, itsct->point);
	if (direction_dot(itsct->normal, ray->ray_dir) > 0)
	{
		temp = itsct->normal;
		itsct->normal = direction_reverse(temp);
		free(temp);
	}
}

//Function handles the case where there are two solutions for ray-sphere itsct.
static void	sphere_intersection_two(t_ray *ray, t_sphere *sphere, \
									t_itsct_sphere *is, t_intersect *itsct)
{
	if (is->soln->first < 0 && is->soln->second < 0)
	{
		itsct->state = MISSED;
		return ;
	}
	else if ((is->soln->first > 0 || is->soln->second > 0) && \
			(is->soln->first < 0 || is->soln->second < 0))
	{
		itsct->state = INTERSECTED;
		itsct->distance = fmax(is->soln->first, is->soln->second);
	}
	else
	{
		itsct->state = INTERSECTED;
        itsct->distance = fmin(is->soln->first, is->soln->second);
	}
	sphere_intersection_point_normal(ray, sphere, itsct);
}

//Function performs a sign change and assigns solutions to intersect solution.
static void	modify_sphere_quad(t_quad_cof *quad, t_quad_sol *sol, \
								t_itsct_sphere *is)
{
	sol->first *= -1;
	sol->second *= -1;
	is->quad = quad;
	is->soln = sol;
}

//Function works out the intersection between a ray and a sphere.
t_intersect	*intersection_ray_sphere(t_ray *ray, t_sphere *sphere)
{
	t_itsct_sphere	*is;
	t_quad_cof		*quad;
	t_quad_sol		*soln;
    t_intersect     *itsct;

	is = (t_itsct_sphere *)malloc(sizeof(t_itsct_sphere));
	is->ray_to_ctr = vector_two_points(ray->ray_orig, sphere->centre);
	is->vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	quad = (t_quad_cof *)malloc(sizeof(t_quad_cof));
	quad->squared = vector_dot(is->vec_ray_dir, is->vec_ray_dir);
	quad->linear = 2 * vector_dot(is->vec_ray_dir, is->ray_to_ctr);
	quad->constant = fabs(vector_dot(is->ray_to_ctr, is->ray_to_ctr)) - \
						pow(sphere->radius, 2);
	soln = solve_quadratic(quad);
	modify_sphere_quad(quad, soln, is);
	itsct = intersect_create();
	if (soln->sol == NO_REAL)
		itsct->state = MISSED;
	else if (soln->sol == ONE)
	{
		itsct->state = INTERSECTED;
		itsct->distance = -quad->linear / (2 * quad->squared);
		sphere_intersection_point_normal(ray, sphere, itsct);
	}
	else
		sphere_intersection_two(ray, sphere, is, itsct);
	free(quad);
	free(soln);
	free_is(is);
	return (itsct);
}
