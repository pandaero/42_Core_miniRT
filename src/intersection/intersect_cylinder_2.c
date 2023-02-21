/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:38:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/21 15:12:55 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>




//Determining render, getting point and distance to cylinder_intersect
static void determine_cap_distance(t_intersect *intersect_base_plane, \
t_intersect *intersect_top_plane, t_intersect *cylinder_intersect)
{
	if (intersect_base_plane->distance >= 0 && \
	intersect_top_plane->distance < 0 && cylinder_intersect->state == 1)
	{
		free_point(cylinder_intersect->point);
		cylinder_intersect->point = point_copy(intersect_base_plane->point);
		cylinder_intersect->distance = intersect_base_plane->distance;
	}
	else if (intersect_top_plane->distance >= 0 && \
	intersect_base_plane->distance < 0 && cylinder_intersect->state == 1)
	{
		free_point(cylinder_intersect->point);
		cylinder_intersect->point = point_copy(intersect_top_plane->point);
		cylinder_intersect->distance = intersect_top_plane->distance;
	}
	else if (intersect_base_plane->distance >= 0 && \
	intersect_base_plane->distance < intersect_top_plane->distance && \
	cylinder_intersect->state == 1)
	{
		free_point(cylinder_intersect->point);
		cylinder_intersect->point = point_copy(intersect_base_plane->point);
		cylinder_intersect->distance = intersect_base_plane->distance;
	}
	else if (intersect_top_plane->distance >= 0 && \
	intersect_top_plane->distance < intersect_base_plane->distance && \
	cylinder_intersect->state == 1)
	{
		free_point(cylinder_intersect->point);
		cylinder_intersect->point = point_copy(intersect_top_plane->point);
		cylinder_intersect->distance = intersect_top_plane->distance;
	}
}

static void	free_cylinder_mantle_caps(t_intersect *intersect_base_plane, t_intersect *intersect_top_plane, t_intersect *cylinder_intersect)
{
	free_intersection(intersect_base_plane);
	free_intersection(intersect_top_plane);
	if (cylinder_intersect->state != 1)
	{
		free_point(cylinder_intersect->point);
		cylinder_intersect->point = NULL;
	}
}

//Shapes an infinite cylinder and shapes finite cylinder with caps
void cylinder_mantle_caps(t_ray_cylinder *t, \
t_intersect *cylinder_intersect, t_ray *ray, t_cylinder *cylinder)
{
	t_intersect *intersect_base_plane;
	t_intersect *intersect_top_plane;

	intersect_base_plane = NULL;
	intersect_top_plane = NULL;
	t->distance_cylinder_axis = 2 * sqrt(fabs((pow(cylinder->radius,2) - pow(distance_two_points(cylinder->centre, cylinder_intersect->point),2))));
	if (t->distance_cylinder_axis >= 0)
	{
		if (t->distance_cylinder_axis <= cylinder->height)
		{
			cylinder_intersect->state = 1;
			cylinder_intersect->distance = distance_two_points(ray->ray_orig, cylinder_intersect->point);
		}
		else
		{
			intersect_base_plane = base_cap_intersection(cylinder, ray, \
			cylinder_intersect);
			intersect_top_plane = top_cap_intersection(cylinder, ray \
			, cylinder_intersect);
			determine_cap_distance(intersect_base_plane, \
			intersect_top_plane, cylinder_intersect);
			free_cylinder_mantle_caps(intersect_base_plane, intersect_top_plane, cylinder_intersect);
		}
	}
}
