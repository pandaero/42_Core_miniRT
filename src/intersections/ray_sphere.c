/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:52 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 20:10:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Added a funcition that normalizes the direction courtesy of Pablo.
use:
cc ray_sphere.c operations.c input.c -lm
*/
#include "../../include/minirt.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//Function produces the output point if there is an intersection, alocates memory to that point
t_Vector3 *zero_sphere_intersection(t_Vector3 *zero_point, t_Vector3 *direction, double distance)
{
	t_Vector3 *point_of_intersection;

	point_of_intersection = malloc(sizeof(t_Vector3));
	
	point_of_intersection->x = -1 * (zero_point->x + direction->x * distance);
	point_of_intersection->y = -1 * (zero_point->y + direction->y * distance);
	point_of_intersection->z = -1 * (zero_point->z + direction->z * distance);
}
/*Comment precise*/
int ray_sphere_intersection(t_ray	*ray)
{
	t_Vector3	*ray_start;
	t_Vector3	*ray_direction;
	t_Vector3	*sphere_center;
	t_Vector3	*Rp; //effect of subtracting the center coordinates of the sphere from the starting point of the ray
	// t_Vector3	*first_intersection;
	int			intersect;
	double		t0; //distance of normalized direction vector to a point of intersection
	double		t1; // distance of normalized direction vector to a different point of intersection
	double		y; // the discriminant

	// exit(printf"segcheck\n");
	ray_start = malloc(sizeof(t_Vector3));
	sphere_center = malloc(sizeof(t_Vector3));
	populate_point(ray_start, ray->ray_orig->x_co, ray->ray_orig->y_co, ray->ray_orig->z_co);
	populate_point(ray_direction, ray->ray_dir->x_comp, ray->ray_dir->y_comp, ray->ray_dir->y_comp);
	populate_point(sphere_center, SPHERE_CENTER_X, SPHERE_CENTER_Y, SPHERE_CENTER_Z);
	Rp = substract_vectors(ray_start, sphere_center);
	y = pow(dot(Rp, ray_direction), 2) - (dot(Rp, Rp)) + pow(SPHERE_RADIUS, 2);
	// printf("ray start - [%f, %f, %f]\n", ray_start->x, ray_start->y, ray_start->z);
	// printf("y = %f\n", y);
	if (y >= 0)
	{
		intersect = 1;
		t0 = (dot(Rp, ray_direction)) - sqrt((pow(dot(Rp, ray_direction), 2)) - (dot(Rp, Rp)) + (pow(SPHERE_RADIUS, 2)));
		t1 = (dot(Rp, ray_direction)) + sqrt((pow(dot(Rp, ray_direction), 2)) - (dot(Rp, Rp)) + (pow(SPHERE_RADIUS, 2)));
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
	free(Rp);
	free(sphere_center);
	free(ray_direction);
	free(ray_start);
	return(intersect);
}