/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:18:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 22:55:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>

//Function determines initial conditions for ray-shaft calculation.
static void	initial_conditions(t_ray *ray, t_cylinder *cyl, t_itsct_cyl *ic)
{
	t_quad_cof	quad_shaft;
	t_quad_sol	quad_soln;

	ic->itsct_shaft = intersect_create();
	ic->ray_orig_trans = point_subtract(ray->ray_orig, cyl->centre);
	ic->vec_ray = vector_mag_dir(1, ray->ray_dir);
	ic->vec_orig_trans = vector_point(ic->ray_orig_trans);
	ic->vec_cyl_axis = vector_mag_dir(1, cyl->orientation);
	quad_shaft.squared = vector_dot(ic->vec_ray, ic->vec_ray) - \
							pow(vector_dot(ic->vec_ray, ic->vec_cyl_axis), 2);
	quad_shaft.linear = 2 * (vector_dot(ic->vec_orig_trans, ic->vec_ray) - \
							vector_dot(ic->vec_ray, ic->vec_cyl_axis) * \
							vector_dot(ic->vec_orig_trans, ic->vec_cyl_axis));
	quad_shaft.constant = vector_dot(ic->vec_orig_trans, ic->vec_orig_trans) - \
					pow(vector_dot(ic->vec_orig_trans, ic->vec_cyl_axis), 2) - \
					pow(cyl->radius, 2);
	quad_soln = solve_quadratic(quad_shaft);
	ic->soln = &quad_soln;
	ic->proj_cent = NULL;
	ic->proj_centre = NULL;
	ic->ray_orig_trans = NULL;
	ic->vec_itsct = NULL;
	ic->vec_cyl_to_pt = NULL;
}

//Function assigns the initial conditions for working out point within shaft.
static void	initial_within_shaft_normal(t_ray *ray, t_cylinder *cyl, \
										t_itsct_cyl *ic)
{
	ic->vec_itsct = vector_mag_dir(ic->itsct_shaft->distance, ray->ray_dir);
	ic->itsct_shaft->point = point_point_vector(ray->ray_orig, ic->vec_itsct);
	ic->vec_cyl_to_pt = vector_two_points(cyl->centre, ic->itsct_shaft->point);
	ic->proj_height = vector_dot(ic->vec_cyl_to_pt, ic->vec_cyl_axis) / \
						vector_dot(ic->vec_cyl_axis, ic->vec_cyl_axis);
}

static void	determine_within_shaft_and_normal(t_ray *ray, t_cylinder *cyl, \
												t_itsct_cyl *ic)
{
	initial_within_shaft_normal(ray, cyl, ic);
	if (fabs(ic->proj_height) > cyl->height / 2)
	{
		ic->itsct_shaft->state = MISSED;
		return ;
	}
	if (ic->proj_height == 0)
	{
		ic->itsct_shaft->normal = direction_two_points(cyl->centre, \
														ic->itsct_shaft->point);
	}
	else
	{
		ic->proj_centre = vector_scale_direction(ic->proj_height, \
													cyl->orientation);
		ic->proj_cent = point_point_vector(cyl->centre, ic->proj_centre);
		ic->itsct_shaft->normal = direction_two_points(ic->proj_cent, \
														ic->itsct_shaft->point);
	}
	if (direction_dot(ic->itsct_shaft->normal, ray->ray_dir) > 0)
	{
		ic->temp = ic->itsct_shaft->normal;
		ic->itsct_shaft->normal = direction_reverse(ic->temp);
		free(ic->temp);
	}
}

//Function works out the intersection between a ray and a cylinder shaft.
t_intersect	*intersection_ray_shaft(t_ray *ray, t_cylinder *cyl, \
									t_itsct_cyl *ic)
{
	initial_conditions(ray, cyl, ic);
	if (ic->soln->sol == NO_REAL)
		ic->itsct_shaft->state = MISSED;
	else if (ic->soln->sol == ONE)
	{
		ic->itsct_shaft->state = INTERSECTED;
		ic->vec_itsct = vector_mag_dir(ic->soln->first, ray->ray_dir);
	}
	else
	{
		ic->itsct_shaft->state = INTERSECTED;
		if (ic->soln->first > 0 && ic->soln->second < 0)
			ic->itsct_shaft->distance = ic->soln->first;
		else if (ic->soln->first < 0 && ic->soln->second > 0)
			ic->itsct_shaft->distance = ic->soln->second;
		else if (ic->soln->first > 0 && ic->soln->second > 0)
			ic->itsct_shaft->distance = fmin(ic->soln->first, ic->soln->second);
		else
			ic->itsct_shaft->state = MISSED;
	}
	if (ic->itsct_shaft->state != MISSED)
		determine_within_shaft_and_normal(ray, cyl, ic);
	return (ic->itsct_shaft);
}
