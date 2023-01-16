/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/16 14:36:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/*
Added a funcition that normalizes the direction courtesy of Pablo.
use:
cc ray_sphere.c operations.c input.c -lm
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct s_Vector3
{
	double	x;
	double	y;
	double	z;
}			t_Vector3;

typedef struct s_ray_sphere_struct
{
	double		t0;
	double		t1;
	double		y;
	int			intersect;
}t_rs;

/*Function produces the output point if there 
is an intersection, alocates memory to that point.
Maybe it gets the point.*/
t_Vector3	*zero_sphere_intersection(t_Vector3 *zero_point, \
t_Vector3 *direction, double distance)
{
	t_Vector3	*point_of_intersection;

	point_of_intersection = malloc(sizeof(t_Vector3));
	point_of_intersection->x = -1 * (zero_point->x + direction->x * distance);
	point_of_intersection->y = -1 * (zero_point->y + direction->y * distance);
	point_of_intersection->z = -1 * (zero_point->z + direction->z * distance);
	return (point_of_intersection);
}

// Function that finds a point of 
// intersection between a ray 
// and a sphere of a defined radius and center in space.
// Nomenclature:
// 	rp - Resulting from subtracting center of sphere from ray origin.
// 	t0 - distance of normalized direction vector to a point of intersection
// 	t1 - distance of normalized direction vector 
		// to a different point of intersection
// 	y - the discriminant
int	ray_sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	t_vector	*vec_ray_dir;
	t_vector	*rp;
	t_rs		rs;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	rp = vector_two_points(ray->ray_orig, sphere->centre);
	rs.y = pow(vector_dot(rp, vec_ray_dir), 2) - \
	(vector_dot(rp, rp)) + pow(sphere->radius, 2);
	if (rs.y >= 0)
	{
		rs.intersect = 1;
		rs.t0 = (vector_dot(rp, vec_ray_dir)) - \
		sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
		(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
		rs.t1 = (vector_dot(rp, vec_ray_dir)) + \
		sqrt((pow(vector_dot(rp, vec_ray_dir), 2)) - \
		(vector_dot(rp, rp)) + (pow(sphere->radius, 2)));
	}
	else
		rs.intersect = 0;
	free_vector(rp);
	free_vector(vec_ray_dir);
	return (rs.intersect);
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
