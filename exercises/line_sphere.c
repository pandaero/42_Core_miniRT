/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:18:09 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/10 17:40:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*This programme will answer the question if the given ray 
with a startpoint and direction
intersects with a sphere comparing the distance between the center of the sphere and the closest point
to the ray. The closes point to the ray will intersect at a 90 degree angle so we can use the
dot(sphere_center - raystart, ray_direction equation) 
to determine that distance. The ray direction is relative to the r start, so it begins in ray zero*/

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}t_point;


int	dot(t_point *S, t_point *r_zero, t_point *r_direction)
{
	return (((S->x - r_zero->x)*r_direction->x) \
	+ ((S->y - r_zero->y)*r_direction->y) + \
	((S->z - r_zero->z)*r_direction->z));
}
#define RAY_START_X 2
#define RAY_START_Y 0
#define RAY_START_Z 8
#define RAY_DIRECTION_X 4
#define RAY_DIRECTION_Y -2
#define RAY_DIRECTION_Z -1
#define SPHERE_CENTER_X 3
#define SPHERE_CENTER_Y 3
#define SPHERE_CENTER_Z 3

void populate_point(t_point *to_fill, int x, int y, int z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}

int	main(void)
{
	t_point	*ray_start;
	t_point	*ray_direction;
	t_point	*sphere_center;
	int		distance_sphere_center_to_ray;

	ray_start = malloc(sizeof(t_point));
	ray_direction = malloc(sizeof(t_point));
	sphere_center = malloc(sizeof(t_point));
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction, RAY_DIRECTION_X, RAY_DIRECTION_Y, RAY_DIRECTION_Z);
	populate_point(sphere_center, SPHERE_CENTER_X, SPHERE_CENTER_Y, SPHERE_CENTER_Z);
	distance_sphere_center_to_ray = dot(sphere_center, ray_start, ray_direction);
	// distance_sphere_center_to_ray = dot(sphere_center, ray_start, ray_direction);
	printf("distance equals: %d\n", distance_sphere_center_to_ray);
	free(ray_start);
	free(ray_direction);
	free(sphere_center);
}