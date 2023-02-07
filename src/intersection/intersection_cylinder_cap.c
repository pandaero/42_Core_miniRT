/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder_cap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:58 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/07 17:52:01 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

void	free_cylinder_plane(t_cylinder_cap *t)
{
	free_plane(t->cap_plane);
	free(t);
}

void	free_cylinder_cap(t_cylinder_cap *t)
{
	free_vector(t->disc_center_to_point_plane);
	free_plane(t->cap_plane);
	free(t);
}

t_intersect	*intersection_cylinder_cap(t_ray *ray, \
t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_intersect		*cap_intersection;

	t = (t_cylinder_cap *)malloc(sizeof(t_cylinder_cap));
	t->cap_plane = plane_col_point_normal_dir(0x00FF00, \
	center, cylinder->orientation);
	cap_intersection = intersection_ray_plane(ray, t->cap_plane);
	t->disc_center_to_point_plane = NULL;
	if (cap_intersection->state == 0)
	{
		free_cylinder_plane(t);
		return (cap_intersection);
	}
	if (cap_intersection->state != 0)
	{
		t->disc_center_to_point_plane = vector_two_points(center, \
		cap_intersection->point);
		t->distance_center_point_sq = vector_dot(t->disc_center_to_point_plane, \
		t->disc_center_to_point_plane);
		t->radius_sq = cylinder->radius * cylinder->radius;
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
