/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 15:26:37 by pbiederm         ###   ########.fr       */
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

#include "./intersections.h"

# define PLANE_POINT_INPUT_X 1
# define PLANE_POINT_INPUT_Y 0
# define PLANE_POINT_INPUT_Z 100
# define PLANE_NOT_NORMAL_INPUt_Vector3_X 0
# define PLANE_NOT_NORMAL_INPUt_Vector3_Y 0
# define PLANE_NOT_NORMAL_INPUt_Vector3_Z 1
# define RAY_START_X 0
# define RAY_START_Y 0
# define RAY_START_Z 0
# define RAY_DIRECTION_INPUT_X 0
# define RAY_DIRECTION_INPUT_Y 0
# define RAY_DIRECTION_INPUT_Z -1000000

t_Vector3 *calculate_ray_plane_intersection(t_Vector3 *zero_point, t_Vector3 *direction, double distance)
{
	t_Vector3 *point_of_intersection;

	point_of_intersection = malloc(sizeof(t_Vector3));
	
	point_of_intersection->x = (zero_point->x + direction->x * distance);
	point_of_intersection->y = (zero_point->y + direction->y * distance);
	point_of_intersection->z = (zero_point->z + direction->z * distance);
}
void ray_plane_intersection(void)
{
	t_Vector3	*plane_point;
	t_Vector3	*plane_normal_input;
	t_Vector3 *plane_normal;
	t_Vector3 *ray_start;
	t_Vector3 *ray_direction_input;
	t_Vector3 *ray_direction;
	t_Vector3 *L; //(P - R) is the vector pointing from the origin of the ray to a point on the plane 
	t_Vector3 *point_of_intersection;
	double	t;

	plane_point = malloc(sizeof(t_Vector3));
	plane_normal_input = malloc(sizeof(t_Vector3));
	ray_start = malloc(sizeof(t_Vector3));
	ray_direction_input = malloc(sizeof(t_Vector3));
	populate_point(plane_point, PLANE_POINT_INPUT_X, PLANE_POINT_INPUT_Y, PLANE_POINT_INPUT_Z);
	populate_point(plane_normal_input, PLANE_NOT_NORMAL_INPUt_Vector3_X, PLANE_NOT_NORMAL_INPUt_Vector3_Y, PLANE_NOT_NORMAL_INPUt_Vector3_Z);
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction_input, RAY_DIRECTION_INPUT_X, RAY_DIRECTION_INPUT_Y, RAY_DIRECTION_INPUT_Z);
	ray_direction = direction_two_points_local(ray_start, ray_direction_input);
	plane_normal = direction_two_points_local(plane_point, plane_normal_input);
	L = substract_vectors(plane_point, ray_start);
	t = dot(L, plane_normal) / dot(ray_direction, plane_normal);
	if (t >= 0)
	{
		point_of_intersection = calculate_ray_plane_intersection(ray_start, ray_direction, t);
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