/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:58 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/18 12:09:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//Function checks whether a ray is intersecting within a disc radius.
static void	is_ray_within_radius(t_cylinder_cap *t, t_point *center, \
t_cylinder *cylinder, t_intersect *cap_intersection)
{
	t->disc_center_to_point_plane = vector_two_points(center, \
	cap_intersection->point);
	t->distance_center_point_sq = vector_dot(t->disc_center_to_point_plane, \
	t->disc_center_to_point_plane);
	t->radius_sq = cylinder->radius * cylinder->radius;
}

//Function creates and initialises a cap struct.
static t_cylinder_cap	*cap_init(t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_colour		*col;

	t = (t_cylinder_cap *)malloc(sizeof(t_cylinder_cap));
	col = colour_str("0,255,0");
	t->cap_plane = plane_col_point_normal_dir(col, \
	center, cylinder->orientation);
	t->disc_center_to_point_plane = NULL;
	free(col);
	return (t);
}

//Function works out the intersection between a ray and a cylinder cap.
t_intersect	*intersection_cylinder_cap(t_ray *ray, \
										t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_intersect		*cap_intersection;

	t = cap_init(center, cylinder);
	cap_intersection = intersection_ray_plane(ray, t->cap_plane);
	// t->
	if (cap_intersection->state == 0)
	{
		free_cylinder_plane(t);
		return (cap_intersection);
	}
	if (cap_intersection->state != 0)
	{
		is_ray_within_radius(t, center, cylinder, cap_intersection);
		if (t->distance_center_point_sq > t->radius_sq)
		{
			cap_intersection->state = 0;
			free_cylinder_cap(t);
			return (cap_intersection);
		}
	}
	cap_intersection->state = 1;
	free_cylinder_cap(t);
	return (cap_intersection);
}
