/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere_alternative.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:03 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 14:14:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
EXAMPLE NOT WORKING BUT SOME FUNCTIONS ARE USEFULL
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define RAY_START_X 1
#define RAY_START_Y 1
#define RAY_START_Z 1
#define RAY_DIRECTION_X 2
#define RAY_DIRECTION_Y 2
#define RAY_DIRECTION_Z 2
#define SPHERE_CENTER_X 50
#define SPHERE_CENTER_Y 1
#define SPHERE_CENTER_Z 1
#define SPHERE_RADIUS 1

typedef struct
{
    double x;
    double y;
    double z;
} Vector3;

Vector3 vector3_subtract(Vector3 v1, Vector3 v2)
{
    Vector3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

double vector3_dot (Vector3 first, Vector3 second)
{
	return(first.x * second.x + first.y * second.y + first.z * second.z);
}


int ray_sphere_intersection(Vector3 ray_origin, Vector3 ray_direction, Vector3 sphere_center, double sphere_radius, double *t)
{
    Vector3 l = vector3_subtract(sphere_center, ray_origin);
    double tca = vector3_dot(l, ray_direction);
    if (tca < 0) return 0; // the ray points away from the sphere

    double d2 = vector3_dot(l, l) - tca * tca;
    if (d2 > sphere_radius * sphere_radius) return 0; // the ray misses the sphere

    double thc = sqrt(sphere_radius * sphere_radius - d2);
    if (t) *t = tca - thc; // the ray hits the sphere
    return 1;
}

void populate_point(Vector3 *to_fill, double x, double y, double z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}

int main (void)
{
	double *t;
	Vector3	*ray_origin;
	Vector3 *ray_direction;
	Vector3 *sphere_center;

	ray_origin = malloc(sizeof(Vector3));
	ray_direction = malloc(sizeof(Vector3));
	sphere_center = malloc(sizeof(Vector3));
	t = malloc(sizeof(double));
	populate_point(ray_origin, RAY_START_X, RAY_START_Y, RAY_START_Z);
	printf("ray origin x y z %f %f %f\n", ray_origin->x, ray_origin->y, ray_origin->z);
	populate_point(ray_direction, RAY_DIRECTION_X, RAY_DIRECTION_Y, RAY_DIRECTION_Z);
	printf("ray_direction x y z %f %f %f\n", ray_direction->x, ray_direction->y, ray_direction->z);
	populate_point(sphere_center, SPHERE_CENTER_X, SPHERE_CENTER_Y, SPHERE_CENTER_Z);
	printf("sphere_center x y z %f %f %f\n", sphere_center->x, sphere_center->y, sphere_center->z);
	printf("result 1 for intersection: %d\n", \
	ray_sphere_intersection(*ray_origin, *ray_direction, *sphere_center, SPHERE_RADIUS, t));
	printf("we print the t %f\n", *t);
	free(ray_origin);
	free(ray_direction);
	free(sphere_center);
	free(t);
}