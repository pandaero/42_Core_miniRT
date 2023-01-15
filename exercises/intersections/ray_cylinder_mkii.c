/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_mkii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:31:47 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 14:43:47 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
In accordance with the following:
http://www.illusioncatalyst.com/notes_files/mathematics/line_cylinder_intersection.php

identifier: cy
∗ x,y,z coordinates: 50.0,0.0,20.6
∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
∗ the cylinder diameter: 14.2
∗ the cylinder height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255

a=(v⋅v)−(v⋅h^)2
b=2[(v⋅w)−(v⋅h^)(w⋅h^)]
c=(w⋅w)−(w⋅h^)2−r2



*/

#include "./intersections.h"

#define RAY_START_X 0
#define RAY_START_Y 0
#define RAY_START_Z 0
#define RAY_INPUT_DIRECTION_X 1
#define RAY_INPUT_DIRECTION_Y 0
#define RAY_INPUT_DIRECTION_Z 0
#define CYLINDER_CENTER_X 100
#define CYLINDER_CENTER_Y 100
#define CYLINDER_CENTER_Z 100
#define CYLINDER_HEIGHT 10
//cylinder input vector is normalized
#define CYLINDER_INPUT_DIRECTION_X 0
#define CYLINDER_INPUT_DIRECTION_Y 1
#define CYLINDER_INPUT_DIRECTION_Z 0
#define CYLINDER_DIAMETER 5

void	ray_cylinder_intersection()
{
	t_point	*ray_start;
	t_point	*ray_direction_input;
	t_point	*ray_direction;
	t_point	*cylinder_center;
	t_point	*cylinder_direction_input;
	t_point *w; //vector difference between L0 and C
	double	a;
	double	b;
	double	c;

	ray_start = malloc(sizeof(t_point));
	ray_direction_input = malloc(sizeof(t_point));
	cylinder_center = malloc(sizeof(t_point));
	cylinder_direction_input = malloc(sizeof(t_point));
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction_input, RAY_INPUT_DIRECTION_X, RAY_INPUT_DIRECTION_Y, RAY_INPUT_DIRECTION_Z);
	populate_point(cylinder_center, CYLINDER_CENTER_X, CYLINDER_CENTER_Y, CYLINDER_CENTER_Z);
	populate_point(cylinder_direction_input, CYLINDER_INPUT_DIRECTION_X, CYLINDER_INPUT_DIRECTION_Y, CYLINDER_INPUT_DIRECTION_Z);
	ray_direction = direction_two_points_local(ray_start, ray_direction_input);
	w = substract_vectors(ray_start - cylinder_center);
	a = dot(ray_direction, ray_direction) - pow(dot(ray_direction, cylinder_direction_input), 2);
	b = 2 * (dot(ray_direction, w) - dot(ray_direction, cylinder_direction_input) * dot(w, cylinder_direction_input));
	c = dot(ray_direction, ray_direction) - dot(w, cylinder_direction_input);
	solveQuadratic(a, b, c);
	
	free(w);
	free(ray_start);
	free(ray_direction_input);
	free(cylinder_center);
	free(cylinder_direction_input);
	free(ray_direction);
}

int main(void)
{
	ray_cylinder_intersection();
	return(0);
}
