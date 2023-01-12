/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere_enchanced.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:42:52 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 14:16:07 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Works with normalized direction vector, vector of lenght one
use:
cc line_sphere_enchanced.c -lm
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}t_point;

#define RAY_START_X 0
#define RAY_START_Y 0
#define RAY_START_Z 0
#define RAY_DIRECTION_X 1
#define RAY_DIRECTION_Y 0
#define RAY_DIRECTION_Z 0
#define SPHERE_CENTER_X 20
#define SPHERE_CENTER_Y 5
#define SPHERE_CENTER_Z 0
#define SPHERE_RADIUS 4

double	dot(t_point *first, t_point *second)
{
	return ((first->x * second->x) + \
	(first->y * second->y) + \
	(first->z * second->z));
}

/*The return value of this function needs to have memory allocated to it.*/
t_point *substract_vectors(t_point *V, t_point *W)
{
	t_point *ret_val;

	ret_val = malloc(sizeof(t_point));
	ret_val->x = V->x - W->x;
	ret_val->y = V->y - W->y;
	ret_val->z = V->z - W->z;
	return (ret_val);
}

void populate_point(t_point *to_fill, double x, double y, double z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}

t_point *zero_sphere_intersection(t_point *zero_point, t_point *direction, double distance)
{
	t_point *point_of_intersection;

	point_of_intersection = malloc(sizeof(t_point));
	
	point_of_intersection->x = -1 * (zero_point->x + direction->x * distance);
	point_of_intersection->y = -1 * (zero_point->y + direction->y * distance);
	point_of_intersection->z = -1 * (zero_point->z + direction->z * distance);
}

int main(void)
{
	t_point	*ray_start;
	t_point	*ray_direction;
	t_point	*sphere_center;
	t_point *Rp; //effect of subtracting the center coordinates of the sphere from the starting point of the ray
	t_point *first_intersection;
	t_point *second_intersection;
	double	t0; //distance of normalized direction vector to a point of intersection
	double	t1; // distance of normalized direction vector to a different point of intersection
	double	y; // the discriminant

	ray_start = malloc(sizeof(t_point));
	ray_direction = malloc(sizeof(t_point));
	sphere_center = malloc(sizeof(t_point));
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction, RAY_DIRECTION_X, RAY_DIRECTION_Y, RAY_DIRECTION_Z);
	populate_point(sphere_center, SPHERE_CENTER_X, SPHERE_CENTER_Y, SPHERE_CENTER_Z);
	Rp = substract_vectors(ray_start, sphere_center);
	y = pow(dot(Rp, ray_direction), 2) - (dot(Rp, Rp)) + pow(SPHERE_RADIUS, 2);
	printf("y = %f\n", y);
	if (y >= 0)
	{
		t0 = (dot(Rp, ray_direction)) - sqrt((pow(dot(Rp, ray_direction), 2)) - (dot(Rp, Rp)) + (pow(SPHERE_RADIUS, 2)));
		t1 = (dot(Rp, ray_direction)) + sqrt((pow(dot(Rp, ray_direction), 2)) - (dot(Rp, Rp)) + (pow(SPHERE_RADIUS, 2)));
		first_intersection = zero_sphere_intersection(ray_start, ray_direction, t0);
		second_intersection = zero_sphere_intersection(ray_start, ray_direction, t1);
		printf("First intersection [%f:%f:%f]\n", first_intersection->x, first_intersection->y, first_intersection->z);
		printf("Second intersection [%f:%f:%f]\n", second_intersection->x, second_intersection->y, second_intersection->z);
	}
	else
	{
		printf("render ambient\n");
	}
	free(Rp);
	free(first_intersection);
	free(sphere_center);
	free(ray_direction);
	free(ray_start);
	free(second_intersection);
}