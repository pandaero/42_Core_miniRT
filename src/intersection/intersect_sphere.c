/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/01 14:42:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>

/*Function produces the output point if there 
is an intersection, alocates memory to that point.
Maybe it gets the point. Itdetermines whether a ray
and a sphere intersect.
Nomenclature:
rp - Resulting from subtracting center of sphere from ray origin.
t0 - distance of normalized direction vector to a point of intersection
t1 - distance of normalized direction vector 
		to a different point of intersection
y - the discriminant
*/
/*Function helps ray sphere get the distance of 
between ray and sphere*/
static double	get_distance(t_vector *vec_ray_dir, t_vector *rp, t_sphere *sphere)
{
	double	distance;
	double	tmp;

	distance = (vector_dot(rp, vec_ray_dir)) - \
			sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
			(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
	tmp = (vector_dot(rp, vec_ray_dir)) + \
			sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
			(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
	if (tmp < distance)
		distance = tmp;
	return (distance);
}

//Function that gets the coordinates of intersection between ray and sphere object.
t_intersect	*intersection_ray_sphere(t_objlist *objlist, t_ray *ray, t_obj *obj_sphere)
{
	t_vector	*vec_ray_dir;
	t_vector	*rp;
	t_rs		rs;
	t_intersect	*intersection;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	rp = vector_two_points(ray->ray_orig, obj_sphere->sphere->centre);
	rs.y = pow(vector_dot(rp, vec_ray_dir), 2) - \
	(vector_dot(rp, rp)) + pow(obj_sphere->sphere->radius, 2);
	intersection = intersect_create();
	if (rs.y >= 0)
	{
		intersection->state = 1;
		intersection->object = obj_sphere;
		intersection->distance = get_distance(vec_ray_dir, rp, obj_sphere->sphere);
		intersection->point = point_ray_distance(ray, intersection->distance);
		intersection->colour = colour_lighting(objlist, intersection);
	}
	else
		intersection->colour = colour_ambient_list(objlist);
	free_vector(rp);
	free_vector(vec_ray_dir);
	return (intersection);
}
