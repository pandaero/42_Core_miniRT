/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:51:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 14:30:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <limits.h>
#include <float.h>

//Function copies an intersection.
t_intersect	intersect_copy(t_intersect intersect)
{
	t_intersect	new;

	new.state = intersect.state;
	new.distance = intersect.distance;
	new.colour = colour_copy(intersect.colour);
	new.normal = direction_copy(intersect.normal);
	new.point = point_copy(intersect.point);
	new.object = intersect.object;
	return (new);
}

//Function creates an intersection from colour, state, ditance, and a point.
t_intersect	intersection_input(t_colour colour, int state, double dist, \
								t_point point)
{
	t_intersect	intersection;

	intersection.state = state;
	intersection.colour = colour_copy(colour);
	intersection.distance = dist;
	intersection.point = point_copy(point);
	return (intersection);
}

//Function works out the intersection between a ray and an object.
t_intersect	intersection_ray_obj(t_ray ray, t_obj *obj)
{
	t_intersect	out;

	out.state = UNCALCULATED;
	out.distance = -DBL_MIN;
	if (obj->elem == PLANE)
		out = intersection_ray_plane(ray, obj->plane);
	if (obj->elem == SPHERE)
		out = intersection_ray_sphere(ray, obj->sphere);
	if (obj->elem == CYLINDER)
		out = intersection_ray_cylinder(ray, obj->cylinder);
	out.object = obj;
	return (out);
}
