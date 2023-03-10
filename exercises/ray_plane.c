/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 19:34:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
For this, we will use the same starting point and direction vector for the ray as 
in the previous example: R = (1, 2, 3) and D = (4, 5, 6). And let's say the plane 
is defined by a point on the plane 
P = (x0, y0, z0) and the normal vector to the plane N = (a, b, c).
Compute the parameter of the point of intersection t using the following formula: 
t = ( ( P - R ) . N ) / ( D . N )
where (P - R) is the vector pointing from the origin of the ray 
to a point on the plane Check if t is greater than or equal to zero. 
If it is, then the ray intersects the plane, 
and the point of intersection is given by: P = R + tD

cc ray_plane.c operations.c input.c -lm
*/

#include "./exercises.h"

# define PLANE_POINT_INPUT_X 1
# define PLANE_POINT_INPUT_Y 0
# define PLANE_POINT_INPUT_Z 100
# define PLANE_NOT_NORMAL_INPUT_POINT_X 0
# define PLANE_NOT_NORMAL_INPUT_POINT_Y 0
# define PLANE_NOT_NORMAL_INPUT_POINT_Z 1
# define RAY_START_X 0
# define RAY_START_Y 0
# define RAY_START_Z 0
# define RAY_DIRECTION_INPUT_X 0
# define RAY_DIRECTION_INPUT_Y 0
# define RAY_DIRECTION_INPUT_Z -1000000

t_point *ray_plane_intersection(t_point *zero_point, t_point *direction, double distance)
{
	t_point *point_of_intersection;

	point_of_intersection = malloc(sizeof(t_point));
	
	point_of_intersection->x = (zero_point->x + direction->x * distance);
	point_of_intersection->y = (zero_point->y + direction->y * distance);
	point_of_intersection->z = (zero_point->z + direction->z * distance);
}
int main (void)
{
	t_point	*plane_point;
	t_point	*plane_normal_input;
	t_point *plane_normal;
	t_point *ray_start;
	t_point *ray_direction_input;
	t_point *ray_direction;
	t_point *L; //(P - R) is the vector pointing from the origin of the ray to a point on the plane 
	t_point *point_of_intersection;
	double	t;

	plane_point = malloc(sizeof(t_point));
	plane_normal_input = malloc(sizeof(t_point));
	ray_start = malloc(sizeof(t_point));
	ray_direction_input = malloc(sizeof(t_point));
	populate_point(plane_point, PLANE_POINT_INPUT_X, PLANE_POINT_INPUT_Y, PLANE_POINT_INPUT_Z);
	populate_point(plane_normal_input, PLANE_NOT_NORMAL_INPUT_POINT_X, PLANE_NOT_NORMAL_INPUT_POINT_Y, PLANE_NOT_NORMAL_INPUT_POINT_Z);
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction_input, RAY_DIRECTION_INPUT_X, RAY_DIRECTION_INPUT_Y, RAY_DIRECTION_INPUT_Z);
	ray_direction = direction_two_points(ray_start, ray_direction_input);
	plane_normal = direction_two_points(plane_point, plane_normal_input);
	L = substract_vectors(plane_point, ray_start);
	t = dot(L, plane_normal) / dot(ray_direction, plane_normal);
	if (t >= 0)
	{
		point_of_intersection = ray_plane_intersection(ray_start, ray_direction, t);
		printf("point of intersection: [%f:%f:%f]\n", point_of_intersection->x, point_of_intersection->y, point_of_intersection->z);
		free(point_of_intersection);
	}
	else
	{
		printf("render ambient\n");
	}
	free(L);
	free(ray_direction);
	free(plane_normal);
	free(plane_point);
	free(plane_normal_input);
	free(ray_start);
	free(ray_direction_input);
}