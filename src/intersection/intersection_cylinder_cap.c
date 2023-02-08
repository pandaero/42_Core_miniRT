/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cylinder_cap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:32:58 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/08 16:50:06 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

//FUNCTION WITHOUT DESCRIPTION
void	free_cylinder_plane(t_cylinder_cap *t)
{
	free_plane(t->cap_plane);
	free(t);
}

//FUNCTION WITHOUT DESCRIPTION
void	free_cylinder_cap(t_cylinder_cap *t)
{
	free_vector(t->disc_center_to_point_plane);
	free_plane(t->cap_plane);
	free(t);
}

//FUNCTION WITHOUT DESCRIPTION
void	is_ray_within_radius(t_cylinder_cap *t, t_point *center, \
t_cylinder *cylinder, t_intersect *cap_intersection)
{
	t->disc_center_to_point_plane = vector_two_points(center, \
	cap_intersection->point);
	t->distance_center_point_sq = vector_dot(t->disc_center_to_point_plane, \
	t->disc_center_to_point_plane);
	t->radius_sq = cylinder->radius * cylinder->radius;
}

//FUNCTION WITHOUT DESCRIPTION
static t_cylinder_cap	*cap_init(t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_colour		*col;

	t = (t_cylinder_cap *)malloc(sizeof(t_cylinder_cap));
	col = colour_str("0,255,0");
	t->cap_plane = plane_col_point_normal_dir(col, \
	center, cylinder->orientation);
	t->disc_center_to_point_plane = NULL;
	return (t);
}

//FUNCTION WITHOUT DESCRIPTION
t_intersect	*intersection_cylinder_cap(t_ray *ray, \
										t_point *center, t_cylinder *cylinder)
{
	t_cylinder_cap	*t;
	t_intersect		*cap_intersection;

	t = cap_init(center, cylinder);
	cap_intersection = intersection_ray_plane(ray, t->cap_plane);
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
