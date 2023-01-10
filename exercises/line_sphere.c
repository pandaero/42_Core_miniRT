/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:18:09 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/10 19:11:04 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
to compile use: cc line_sphere.c -lm 
This programme will answer the question if the given ray 
with a startpoint and direction
intersects with a sphere comparing the distance between the center of the sphere and the closest point
to the ray. The closes point to the ray will intersect at a 90 degree angle so we can use the
dot(sphere_center - raystart, ray_direction equation) 
to determine that distance. The ray direction is relative to the r start, so it begins in ray zero.
p = R0 + Rd*t 
*/

//Function works out the length/distance between two points.

// [18:24]
//Typedef describes a point in 3D space.
// typedef    struct    s_point
// {
//     double    x_co;
//     double    y_co;
//     double    z_co;
// }            t_point;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}t_point;


//Function works out the length/distance between two points.


#define RAY_START_X 0
#define RAY_START_Y 0
#define RAY_START_Z 0
#define RAY_DIRECTION_X 3
#define RAY_DIRECTION_Y 4
#define RAY_DIRECTION_Z 0
#define SPHERE_CENTER_X 50
#define SPHERE_CENTER_Y 0
#define SPHERE_CENTER_Z 0
#define SPHERE_RADIUS 5

double    length_two_points(t_point *point_one, t_point *point_two)
{
    double    distance;

    distance = sqrt(pow(point_two->x - point_one->x, 2) + 
                    pow(point_two->y - point_one->y, 2) +
                    pow(point_two->z - point_one->z, 2));
    return (distance);
}

double	dot(t_point *S, t_point *r_zero, t_point *r_direction)
{
	return (((S->x - r_zero->x)*r_direction->x) \
	+ ((S->y - r_zero->y)*r_direction->y) + \
	((S->z - r_zero->z)*r_direction->z));
}

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
	t_point *point_of_near_sphere_center;
	t_point *point_of_intersection[2];
	double	t; //amount of times you multiply ray direction to get close to the sphere
	double	y; //lenght_p_sphere_center
	double	x; //distance_from_point_near_to_point_of_intersection

	ray_start = malloc(sizeof(t_point));
	ray_direction = malloc(sizeof(t_point));
	sphere_center = malloc(sizeof(t_point));
	point_of_near_sphere_center = malloc(sizeof(t_point));
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction, RAY_DIRECTION_X, RAY_DIRECTION_Y, RAY_DIRECTION_Z);
	populate_point(sphere_center, SPHERE_CENTER_X, SPHERE_CENTER_Y, SPHERE_CENTER_Z);
	t = dot(sphere_center, ray_start, ray_direction);
	populate_point(point_of_near_sphere_center, \
	RAY_START_X + RAY_DIRECTION_X * t, \
	RAY_START_Y + RAY_DIRECTION_Y * t, \
	RAY_START_Z + RAY_DIRECTION_Z * t);
	y = length_two_points(sphere_center, point_of_near_sphere_center);
	if (y > SPHERE_RADIUS)
	{
		printf("No intersection\n");
		return(0);
	}
	x = sqrt(pow(SPHERE_RADIUS, 2) - pow(y, 2));
	point_of_intersection[0] = malloc(sizeof(t_point));
	point_of_intersection[1] = malloc(sizeof(t_point));
	populate_point(point_of_intersection[0], \
	RAY_START_X + RAY_DIRECTION_X * (t - x), \
	RAY_START_Y + RAY_DIRECTION_Y * (t - x), \
	RAY_START_Z + RAY_DIRECTION_Z * (t - x));
	populate_point(point_of_intersection[1], \
	RAY_START_X + RAY_DIRECTION_X * (t + x), \
	RAY_START_Y + RAY_DIRECTION_Y * (t + x), \
	RAY_START_Z + RAY_DIRECTION_Z * (t + x));
	printf("coordinates of first point of intersection x:y:z - %d:%d:%d\n", \
	point_of_intersection[0]->x, \
	point_of_intersection[0]->y, \
	point_of_intersection[0]->z);
	printf("coordinates of second point of intersection x:y:z - %d:%d:%d\n", \
	point_of_intersection[1]->x, \
	point_of_intersection[1]->y, \
	point_of_intersection[1]->z);
	free(ray_start);
	free(ray_direction);
	free(sphere_center);
	free(point_of_intersection[0]);
	free(point_of_intersection[1]);
	free(point_of_near_sphere_center);
}
