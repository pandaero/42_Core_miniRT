/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:38:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/23 12:07:35 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>
//for tests
#include <stdio.h>

//Reallocate point add distance
static void	get_distance(t_intersect *cylinder_intersect, \
									t_intersect *cap_intersection_data, t_ray_cylinder *t)
{
	t->point_cap = point_copy(cap_intersection_data->point);
	t->dist_cap = cap_intersection_data->distance;
}

//Determining render, getting point and distance to cylinder_intersect
static void	determine_cap_distance(t_intersect *intersect_base_plane, \
			t_intersect *intersect_top_plane, t_intersect *cylinder_intersect, t_ray_cylinder *t)
{
	// printf("base dist: %f | ", intersect_base_plane->distance);
	// printf("top dist: %f | ", intersect_top_plane->distance);
	// if (intersect_base_plane->distance < 0 && intersect_top_plane->distance < 0)
	// {
	// 	cylinder_intersect->state = MISSED;
	// }
	// else if (intersect_base_plane->distance >= 0 && \
	// intersect_top_plane->distance < 0 && cylinder_intersect->state == INTERSECTED)
	// {
	// 	get_distance(cylinder_intersect, intersect_base_plane, t);
	// }
	// else if (intersect_top_plane->distance >= 0 && \
	// intersect_base_plane->distance < 0 && cylinder_intersect->state == INTERSECTED)
	// {
		// get_distance(cylinder_intersect, intersect_top_plane, t);
	// }
	// else if (intersect_base_plane->distance >= 0 && \
	// intersect_base_plane->distance < intersect_top_plane->distance)
	// {
		get_distance(cylinder_intersect, intersect_base_plane, t);
	// }
	// else if (intersect_top_plane->distance >= 0 && \
	// intersect_top_plane->distance < intersect_base_plane->distance)
	// {
	// 	get_distance(cylinder_intersect, intersect_top_plane, t);
	// }
}

//Frees variables in intersect cylinder helper func.
static void	free_cylinder_mantle_caps(t_intersect *intersect_base_plane, \
			t_intersect *intersect_top_plane, t_intersect *cylinder_intersect)
{
	free_intersection(intersect_base_plane);
	free_intersection(intersect_top_plane);
}

//Function that shows which cap is intersected
static void	cap_intersection_handle(t_ray *ray, t_cylinder *cylinder, \
t_intersect *cylinder_intersect, t_ray_cylinder *t)
{
	t_intersect	*intersect_base_plane;
	t_intersect	*intersect_top_plane;

	// intersect_base_plane->distance = DBL_MAX - 100;
	// intersect_top_plane->distance = DBL_MAX - 100;
	intersect_base_plane = base_cap_intersection(cylinder, ray, \
	cylinder_intersect);
	intersect_top_plane = top_cap_intersection(cylinder, ray \
	, cylinder_intersect);
	determine_cap_distance(intersect_base_plane, \
	intersect_top_plane, cylinder_intersect, t);
	free_cylinder_mantle_caps(intersect_base_plane, \
	intersect_top_plane, cylinder_intersect);
}

//Shapes an infinite cylinder and shapes finite cylinder with caps
void	cylinder_mantle_caps(t_ray_cylinder *t, \
			t_intersect *cylinder_intersect, t_ray *ray, t_cylinder *cylinder)
{
	t->distance_cylinder_axis = 2 * sqrt(fabs((pow(cylinder->radius, 2) - \
	pow(distance_two_points(cylinder->centre, t->point_infinite_cylinder), 2))));
	if (t->distance_cylinder_axis >= 0)
	{
		if (t->distance_cylinder_axis <= cylinder->height)
		{
			cylinder_intersect->state = MISSED;
			// cylinder_intersect->state = INTERSECTED;
			// t->dist_infinite_cylinder = distance_two_points(ray->ray_orig, \
			// t->point_infinite_cylinder);
		}
		else
			cap_intersection_handle(ray, cylinder, cylinder_intersect, t);
	}
}
