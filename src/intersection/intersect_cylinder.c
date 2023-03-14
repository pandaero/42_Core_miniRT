/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:14 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/14 20:06:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>

//Function works out the surface normal corresponding to the ray-disc intersect.
static void	disc_normal(t_ray ray, t_disc disc, t_intersect *itsct)
{
	t_vector	vec_ray;
	t_vector	vec_normal;

	vec_ray = vector_mag_dir(1, ray.ray_dir);
	vec_normal = vector_mag_dir(1, disc.normal);
	if (vector_dot(vec_ray, vec_normal) > 0)
		itsct->normal = direction_reverse(disc.normal);
	else
		itsct->normal = direction_copy(disc.normal);
}

//Function determines the intersection between a ray and a disc.
static t_intersect	intersection_ray_disc(t_ray ray, t_disc disc)
{
	t_intersect	itsct;
	t_intersect	itsct_plane;
	t_plane		disc_plane;

	itsct.state = UNCALCULATED;
	itsct.distance = DBL_MAX;
	disc_plane = plane_col_point_normal_dir(disc.colour, disc.centre, \
											disc.normal);
	itsct_plane = intersection_ray_plane(ray, disc_plane);
	if (itsct_plane.state == MISSED || \
		distance_two_points(itsct_plane.point, disc.centre) > disc.radius)
		itsct.state = MISSED;
	else
	{
		itsct.point = point_copy(itsct_plane.point);
		itsct.distance = distance_two_points(itsct_plane.point, \
												ray.ray_orig);
		disc_normal(ray, disc, &itsct);
		itsct.state = INTERSECTED;
	}
	return (itsct);
}

//Function assigns the intersections for the disc cases.
static void	assign_intersection_disc(t_itsct_cyl *ic)
{
	if (ic->itsct.state == INTERSECTED)
		ic->distance = ic->itsct.distance;
	if (ic->itsct_disc_top.state == INTERSECTED && \
		ic->itsct_disc_top.distance < ic->distance)
	{
		ic->distance = ic->itsct_disc_top.distance;
		ic->itsct = intersect_copy(ic->itsct_disc_top);
	}	
	if (ic->itsct_disc_base.state == INTERSECTED && \
		ic->itsct_disc_base.distance < ic->distance)
	{
		ic->distance = ic->itsct_disc_base.distance;
		ic->itsct = intersect_copy(ic->itsct_disc_base);
	}
	if (ic->itsct_disc_base.state == INTERSECTED && \
		ic->itsct_disc_top.state == INTERSECTED)
	{
		ic->distance = fmin(ic->itsct_disc_base.distance, \
												ic->itsct_disc_top.distance);
		if (ic->itsct_disc_base.distance < ic->itsct_disc_top.distance)
			ic->itsct = intersect_copy(ic->itsct_disc_base);
		else
			ic->itsct = intersect_copy(ic->itsct_disc_top);
	}
}

//Function determines the intersection between a ray and a cylinder.
t_intersect	intersection_ray_cylinder(t_ray ray, t_cylinder cylinder)
{
	t_itsct_cyl	ic;
	t_intersect	itsct;

	ic.itsct = intersection_ray_shaft(ray, cylinder, &ic);
	ic.itsct_disc_top = intersection_ray_disc(ray, cylinder.top_cap);
	ic.itsct_disc_base = intersection_ray_disc(ray, cylinder.base_cap);
	ic.distance = DBL_MAX;
	assign_intersection_disc(&ic);
	if (ic.itsct.state != INTERSECTED)
	{
		itsct.state = MISSED;
		itsct.distance = DBL_MAX;
	}
	else
		itsct = ic.itsct;
	return (itsct);
}
