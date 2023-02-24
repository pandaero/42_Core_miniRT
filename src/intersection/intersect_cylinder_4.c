/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:12:58 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/24 11:12:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
//tests 
#include <stdio.h>

//Checks for intersection with top cap
static t_top_cap_intersection	*top_cap_intersection_init(t_cylinder *cylinder)
{
	t_top_cap_intersection	*v;

	v = (t_top_cap_intersection *)malloc(sizeof(t_top_cap_intersection));
	v->vector_top_intersection = NULL;
	v->vector_centroid_top = vector_scale_direction(\
	(cylinder->height / 2), cylinder->orientation);
	v->point_center_top = point_point_vector \
	(cylinder->centre, v->vector_centroid_top);
	v->plane_top_cylinder = plane_col_point_normal_dir \
	(cylinder->colour, v->point_center_top, cylinder->orientation);
	return (v);
}

//Function that frees the intersection of a top cap
static void	free_top_cap_intersection(t_top_cap_intersection *v)
{
	free_plane(v->plane_top_cylinder);
	free_point(v->point_center_top);
	free_vector(v->vector_centroid_top);
	free(v);
}

//Intersect check with top cap.
t_intersect	*top_cap_intersection(t_cylinder *cylinder, \
									t_ray *ray, t_intersect *cylinder_intersect)
{
	t_top_cap_intersection	*v;
	t_intersect				*intersect_top_plane;

	v = top_cap_intersection_init(cylinder);
	intersect_top_plane = intersection_ray_plane(ray, v->plane_top_cylinder);
	if (intersect_top_plane->state == INTERSECTED)
	{
		v->vector_top_intersection = vector_two_points(v->point_center_top, \
		intersect_top_plane->point);
		v->d_sq = vector_dot(v->vector_top_intersection, \
		v->vector_top_intersection);
		free_vector(v->vector_top_intersection);
		v->radius_sq = pow(cylinder->radius, 2);
		if (v->d_sq <= v->radius_sq)
		{
			printf("top ");
			cylinder_intersect->state = INTERSECTED;
		}
	}
	free_top_cap_intersection(v);
	return (intersect_top_plane);
}
