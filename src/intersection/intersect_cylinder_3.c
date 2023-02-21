/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:12:00 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/21 15:45:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Checks for intersection with base cap
static t_base_cap_intersection	*base_cap_intersection_init(t_cylinder \
*cylinder)
{
	t_base_cap_intersection	*v;

	v = (t_base_cap_intersection *)malloc(sizeof(t_base_cap_intersection));
	v->vector_base_intersection = NULL;
	v->vector_centroid_base = vector_scale_direction((-1) * \
	(cylinder->height / 2), cylinder->orientation);
	v->point_center_base = point_point_vector \
	(cylinder->centre, v->vector_centroid_base);
	v->plane_base_cylinder = plane_col_point_normal_dir \
	(cylinder->colour, v->point_center_base, cylinder->orientation);
	return (v);
}

//Function that frees the intersection of a base cap
static void	free_base_cap_intersection(t_base_cap_intersection *v)
{
	free_plane(v->plane_base_cylinder);
	free_point(v->point_center_base);
	free_vector(v->vector_centroid_base);
	free(v);
}

//Function determines if there is an intersection with a base cap
t_intersect	*base_cap_intersection(t_cylinder *cylinder, \
t_ray *ray, t_intersect *cylinder_intersect)
{
	t_base_cap_intersection	*v;
	t_intersect				*intersect_base_plane;

	v = base_cap_intersection_init(cylinder);
	intersect_base_plane = intersection_ray_plane(ray, v->plane_base_cylinder);
	if (intersect_base_plane->state == 1)
	{
		v->vector_base_intersection = vector_two_points \
		(v->point_center_base, intersect_base_plane->point);
		v->d_sq = vector_dot(v->vector_base_intersection, \
		v->vector_base_intersection);
		free_vector(v->vector_base_intersection);
		v->radius_sq = pow(cylinder->radius, 2);
		if (v->d_sq <= v->radius_sq)
		{
			cylinder_intersect->state = 1;
		}
	}
	free_base_cap_intersection(v);
	return (intersect_base_plane);
}
