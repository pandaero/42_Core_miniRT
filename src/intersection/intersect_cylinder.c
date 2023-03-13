/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:39:14 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/13 13:19:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>

//Function works out the surface normal corresponding to the ray-disc intersect.
static void	disc_normal(t_ray *ray, t_disc *disc, t_intersect *itsct)
{
	t_vector	*vec_ray;
	t_vector	*vec_normal;

	vec_ray = vector_mag_dir(1, ray->ray_dir);
	vec_normal = vector_mag_dir(1, disc->normal);
	if (vector_dot(vec_ray, vec_normal) > 0)
		itsct->normal = direction_reverse(disc->normal);
	else
		itsct->normal = direction_copy(disc->normal);
	free_vector(vec_ray);
	free_vector(vec_normal);
}

//Function determines the intersection between a ray and a disc.
static t_intersect	*intersection_ray_disc(t_ray *ray, t_disc *disc)
{
	t_intersect	*itsct;
	t_intersect	*itsct_plane;
	t_plane		*disc_plane;

	itsct = intersect_create();
	disc_plane = plane_col_point_normal_dir(disc->colour, disc->centre, \
											disc->normal);
	itsct_plane = intersection_ray_plane(ray, disc_plane);
	if (itsct_plane->state == MISSED || \
		distance_two_points(itsct_plane->point, disc->centre) > disc->radius)
		itsct->state = MISSED;
	else
	{
		itsct->point = point_copy(itsct_plane->point);
		itsct->distance = distance_two_points(itsct_plane->point, \
												ray->ray_orig);
		disc_normal(ray, disc, itsct);
		itsct->state = INTERSECTED;
	}
	free_plane(disc_plane);
	free_intersection(itsct_plane);
	return (itsct);
}

//Function assigns the intersections for the disc cases.
static void	assign_intersection_disc(int sw, t_itsct_cyl *ic)
{
	free_intersection(ic->itsct);
	if (sw == 0)
	{
		ic->distance = ic->itsct_disc_top->distance;
		ic->itsct = ic->itsct_disc_top;
	}
	else
	{
		ic->distance = ic->itsct_disc_base->distance;
		ic->itsct = ic->itsct_disc_base;
	}
}

static t_itsct_cyl	*ic_create(void)
{
	t_itsct_cyl	*ic;

	ic = (t_itsct_cyl *)malloc(sizeof(t_itsct_cyl));
	ic->itsct = NULL;
	ic->itsct_shaft = NULL;
	ic->itsct_disc_base = NULL;
	ic->itsct_disc_top = NULL;
	ic->soln = NULL;
	ic->ray_orig_trans = NULL;
	ic->vec_ray = NULL;
	ic->vec_orig_trans = NULL;
	ic->vec_cyl_axis = NULL;
	ic->vec_itsct = NULL;
	ic->vec_cyl_to_pt = NULL;
	ic->proj_cent = NULL;
	ic->proj_centre = NULL;
	ic->temp = NULL;
	return (ic);
}

//Function determines the intersection between a ray and a cylinder.
t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_itsct_cyl	*ic;
	t_intersect	*itsct;
	
	itsct = intersect_create();
	ic = ic_create();
	ic->itsct = intersection_ray_shaft(ray, cylinder, ic);
	ic->itsct_disc_top = intersection_ray_disc(ray, cylinder->top_cap);
	ic->itsct_disc_base = intersection_ray_disc(ray, cylinder->base_cap);
	ic->distance = DBL_MAX;
	if (ic->itsct->state != MISSED)
		ic->distance = ic->itsct->distance;
	if (ic->itsct_disc_top->distance < ic->distance && \
		ic->itsct_disc_top->state == INTERSECTED)
		assign_intersection_disc(0, ic);
	else if (ic->itsct_disc_base->distance < ic->distance && \
				ic->itsct_disc_base->state == INTERSECTED)
		assign_intersection_disc(1, ic);
	if (ic->itsct == ic->itsct_disc_top)
		free_intersection(ic->itsct_disc_base);
	if (ic->itsct->state != INTERSECTED)
	{
		free_intersection(ic->itsct);
		free_intersection(ic->itsct_disc_base);
		free_intersection(ic->itsct_disc_top);
		itsct->state = MISSED;
		itsct->distance = DBL_MAX;
	}
	else
	{
		free_intersection(ic->itsct_disc_base);
		free_intersection(ic->itsct_disc_top);
		free_intersection(itsct);
		itsct = ic->itsct;
	}
	free_ic(ic);
	return (itsct);
}
