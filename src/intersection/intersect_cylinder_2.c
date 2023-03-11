/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:18:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 22:34:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>

//Function works out the intersection between a ray and a cylinder shaft.
t_intersect	*intersection_ray_shaft(t_ray *ray, t_cylinder *cyl, \
									t_itsct_cyl *ic)
{
	t_quad_cof	quad_shaft;
	t_quad_sol	quad_soln;
	
	ic->itsct_shaft = intersect_create();
	ic->ray_orig_trans = point_subtract(ray->ray_orig, cyl->centre);
	ic->vec_ray = vector_mag_dir(1, ray->ray_dir);
	ic->vec_orig_trans = vector_point(ic->ray_orig_trans);
	ic->vec_cyl_axis = vector_mag_dir(1, cyl->orientation);
	quad_shaft.squared = vector_dot(ic->vec_ray, ic->vec_ray) - pow(vector_dot(ic->vec_ray, ic->vec_cyl_axis), 2);
	quad_shaft.linear = 2 * (vector_dot(ic->vec_orig_trans, ic->vec_ray) - vector_dot(ic->vec_ray, ic->vec_cyl_axis) * vector_dot(ic->vec_orig_trans, ic->vec_cyl_axis));
	quad_shaft.constant = vector_dot(ic->vec_orig_trans, ic->vec_orig_trans) - pow(vector_dot(ic->vec_orig_trans, ic->vec_cyl_axis), 2) - pow(cyl->radius, 2);
	quad_soln = solve_quadratic(quad_shaft);
	if (quad_soln.sol == NO_REAL)
		ic->itsct_shaft->state = MISSED;
	else if (quad_soln.sol == ONE)
	{
		ic->itsct_shaft->state = INTERSECTED;
		ic->vec_itsct = vector_mag_dir(quad_soln.first, ray->ray_dir);
	}
	else // (quad_soln.sol == TWO)
	{
		ic->itsct_shaft->state = INTERSECTED;
		if (quad_soln.first > 0 && quad_soln.second < 0)
			ic->itsct_shaft->distance = quad_soln.first;
		else if (quad_soln.first < 0 && quad_soln.second > 0)
			ic->itsct_shaft->distance = quad_soln.second;
		else if (quad_soln.first > 0 && quad_soln.second > 0)
			ic->itsct_shaft->distance = fmin(quad_soln.first, quad_soln.second);
		else
			ic->itsct_shaft->state = MISSED;
	}
	if (ic->itsct_shaft->state != MISSED)
	{
		ic->vec_itsct = vector_mag_dir(ic->itsct_shaft->distance, ray->ray_dir);

		ic->itsct_shaft->point = point_point_vector(ray->ray_orig, ic->vec_itsct);
		
		t_vector	*vec_cyl_to_pt = vector_two_points(cyl->centre, ic->itsct_shaft->point);
		
		double proj_height = vector_dot(vec_cyl_to_pt, ic->vec_cyl_axis) / vector_dot(ic->vec_cyl_axis, ic->vec_cyl_axis);

		if (fabs(proj_height) > cyl->height / 2)
		{
			ic->itsct_shaft->state = MISSED;
			return (ic->itsct_shaft);
		}
		if (proj_height == 0)
		{
			ic->itsct_shaft->normal = direction_two_points(cyl->centre, ic->itsct_shaft->point);
		}
		else
		{
			t_vector	*proj_centre = vector_scale_direction(proj_height, cyl->orientation);
			t_point		*proj_cent = point_point_vector(cyl->centre, proj_centre);
			ic->itsct_shaft->normal = direction_two_points(proj_cent, ic->itsct_shaft->point);
		}
		if (direction_dot(ic->itsct_shaft->normal, ray->ray_dir) > 0)
		{
			t_direction	*temp = ic->itsct_shaft->normal;
			ic->itsct_shaft->normal = direction_reverse(temp);
			free(temp);
		}
	}
	return (ic->itsct_shaft);
}
