/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:51:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/19 18:06:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <limits.h>

//Function creates and initialises an intersection.
t_intersect	*intersect_create(void)
{
	t_intersect	*new;

	new = (t_intersect *)malloc(sizeof(t_intersect));
	new->state = UNCALCULATED;
	new->colour = NULL;
	new->distance = __DBL_MAX__;
	new->point = NULL;
	return (new);
}

//Function copies an intersection.
t_intersect	*intersect_copy(t_intersect *intersect)
{
	t_intersect	*new;

	new = intersect_create();
	new->state = intersect->state;
	new->colour = colour_copy(intersect->colour);
	new->distance = intersect->distance;
	new->point = point_copy(intersect->point);
	return (new);
}

//Function creates an intersection from colour, state, ditance, and a point.
t_intersect	*intersection_input(t_colour *colour, int state, double dist, \
								t_point *point)
{
	t_intersect	*intersection;

	intersection = intersect_create();
	intersection->state = state;
	intersection->colour = colour_copy(colour);
	intersection->distance = dist;
	intersection->point = point_copy(point);
	return (intersection);
}

//Function works out the intersection between a ray and an object.
t_intersect	*intersection_ray_obj(t_ray *ray, t_obj *obj)
{
	t_intersect	*out;

	if (obj->elem == PLANE)
		out = intersection_ray_plane(ray, obj->plane);
	if (obj->elem == SPHERE)
		out = intersection_ray_sphere(ray, obj->sphere);
	if (obj->elem == CYLINDER)
		out = intersection_ray_cylinder(ray, obj->cylinder);
	out->object = obj;
	return (out);
}

//Produces the distance between the point of origin to the point of intersection
t_point	*get_intersection_point(t_ray *ray, double distance)
{
	t_point	*point;

	point = point_coords \
			(ray->ray_orig->x_co + distance * ray->ray_dir->x_comp, \
			ray->ray_orig->y_co + distance * ray->ray_dir->y_comp, \
			ray->ray_orig->z_co + distance * ray->ray_dir->z_comp);
	return (point);
}
