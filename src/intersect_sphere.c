/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 23:19:25 by pandalaf         ###   ########.fr       */
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

//Function produces the output point if there is an intersection, alocates memory to that point
t_Vector3 *zero_sphere_intersection(t_Vector3 *zero_point, t_Vector3 *direction, double distance)
{
	t_Vector3 *point_of_intersection;

	point_of_intersection = malloc(sizeof(t_Vector3));
	point_of_intersection->x = -1 * (zero_point->x + direction->x * distance);
	point_of_intersection->y = -1 * (zero_point->y + direction->y * distance);
	point_of_intersection->z = -1 * (zero_point->z + direction->z * distance);
	return (point_of_intersection);
}
/*Comment precise*/
int ray_sphere_intersection(t_ray *ray, t_sphere *sphere)
{
	t_vector	*vec_ray_dir;
	t_vector	*Rp; // Resulting from subtracting center of sphere from ray origin.

	int			intersect;
	double		t0; //distance of normalized direction vector to a point of intersection
	double		t1; // distance of normalized direction vector to a different point of intersection
	double		y; // the discriminant

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	Rp = vector_two_points(ray->ray_orig, sphere->centre);
	y = pow(vector_dot(Rp, vec_ray_dir), 2) - (vector_dot(Rp, Rp)) + pow(sphere->radius, 2);
	// printf("ray start - [%f, %f, %f]\n", ray_start->x, ray_start->y, ray_start->z);
	// printf("y = %f\n", y);
	if (y >= 0)
	{
		intersect = 1;
		t0 = (vector_dot(Rp, vec_ray_dir)) - sqrt((pow(vector_dot(Rp, vec_ray_dir), 2)) - (vector_dot(Rp, Rp)) + (pow(sphere->radius, 2)));
		t1 = (vector_dot(Rp, vec_ray_dir)) + sqrt((pow(vector_dot(Rp, vec_ray_dir), 2)) - (vector_dot(Rp, Rp)) + (pow(sphere->radius, 2)));
		// if (t0 <= t1)
		// 	first_intersection = zero_sphere_intersection(ray_start, ray_direction, t0);
		// else
		// 	first_intersection = zero_sphere_intersection(ray_start, ray_direction, t1);
		// printf("First intersection [%f:%f:%f]\n", first_intersection->x, first_intersection->y, first_intersection->z);
		// free(first_intersection);
	}
	else
	{
		intersect = 0;
		// printf("render ambient\n");
	}
	free_vector(Rp);
	free_vector(vec_ray_dir);
	return(intersect);
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
