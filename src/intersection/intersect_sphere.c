/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 15:33:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <stdbool.h>
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
double	get_distance(t_vector *vec_ray_dir, t_vector	*rp, t_sphere	*sphere)
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

//Function that gets the coordinates of intersection between ray and sphere
t_intersect	*ray_sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	t_vector	*vec_ray_dir;
	t_vector	*rp;
	t_rs		rs;
	t_intersect	*intersection;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	rp = vector_two_points(ray->ray_orig, sphere->centre);
	rs.y = pow(vector_dot(rp, vec_ray_dir), 2) - \
	(vector_dot(rp, rp)) + pow(sphere->radius, 2);
	if (rs.y >= 0)
	{
		rs.status = true;
		rs.ret = get_distance(vec_ray_dir, rp, sphere);
	}
	else
		rs.status = false;
	free_vector(rp);
	free_vector(vec_ray_dir);
	intersection = intersection_input(sphere->colour, rs.status, rs.ret, \
	get_intersection_point(ray, rs.ret));
	return (intersection);
}

/*
//Function determines whether a ray intersects a sphere.

//Function works out the closest point of intersection of a ray and a sphere.
t_intersection	*intersection_cam_ray_sphere(t_camera *cam, t_ray *ray, \
												t_sphere *sphere)
{
	t_ray	*ray_to_sphere;

	ray_to_sphere = vector_two_points(ray->ray_orig, sphere->centre);
	
}
//*/
