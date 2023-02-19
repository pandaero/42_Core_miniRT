/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_redo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:38:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/19 16:19:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
// printf ("q_result [%f, %f, %f]\n", quadratic_result[0], quadratic_result[1], quadratic_result[2]);
// printf("cylinder points: [%f, %f, %f]", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);

#include <stdio.h>
#include <stdlib.h>

#define A 0
#define B 1
#define C 2



// //Substracts 
// static t_vect	sub_vect(const t_vector *vect1, const t_vector *vect2)
// {
// 	vec
// 	return (new_vect(vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z));
// }

// generates the distance between intersection and base
static double	distance_base_intersection(t_vector *vector_ray, t_vector *vector_cylinder, t_vector *vector_base_center, double quadratic_solution\
)
{
	double distance_from_base;
	double v = vector_dot(vector_ray, \
	vector_cylinder);
	double w = vector_dot(vector_base_center, vector_cylinder);
	distance_from_base = v * quadratic_solution + w;
	return(distance_from_base);
}

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect	*cylinder_intersect;
	t_vector 	*vector_ray;
	t_vector	*vector_cylinder;
	t_vector	*vector_ray_origin_base_center;
	t_vector	*vector_base_top;
	double		distance_cylinder_axis;
	double		coefficient[3];
	double		*quadratic_result;
	
	cylinder_intersect = intersect_create();
	vector_ray = vector_scale_direction(1, ray->ray_dir);
	vector_cylinder = vector_scale_direction(1, cylinder->orientation);
	vector_ray_origin_base_center = vector_two_points(cylinder->centre, ray->ray_orig);
	vector_base_top = vector_scale_direction(cylinder->height, cylinder->orientation);
	coefficient[A] = vector_dot(vector_ray, vector_ray) - pow(vector_dot(vector_ray, vector_cylinder), 2);
	coefficient[B] = 2 * (vector_dot(vector_ray, vector_ray_origin_base_center) - (vector_dot(vector_ray, vector_cylinder) * vector_dot(vector_ray_origin_base_center, vector_cylinder)));
	coefficient[C] = vector_dot(vector_ray_origin_base_center, vector_ray_origin_base_center) - pow(vector_dot(vector_ray_origin_base_center, vector_cylinder), 2) - pow(cylinder->radius, 2);
	quadratic_result = malloc(3 * sizeof(double));
	quadratic_result = solve_quadratic_real(coefficient);
	if ((quadratic_result[0] == 2) && (quadratic_result[1] > 0 )&& (quadratic_result[2] > 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[1]);
	}
	if ((quadratic_result[0] == 1) && (quadratic_result[1] > 0 )&& (quadratic_result[2] < 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[1]);
 	}
	else if ((quadratic_result[0] == 1) && (quadratic_result[1] > 0 )&& (quadratic_result[2] < 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[1]);
	}
	else if ((quadratic_result[0] == 1) && (quadratic_result[2] < quadratic_result[1] )&& (quadratic_result[2] > 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[2]);
	}
	else if ((quadratic_result[0] == 1) && (quadratic_result[1] < quadratic_result[2]) && (quadratic_result[1] > 0))
	{
		cylinder_intersect->point = get_intersection_point(ray, quadratic_result[1]);
	}
	if(cylinder_intersect->point != NULL)
	{		
		distance_cylinder_axis = 2 * sqrt(fabs((pow(cylinder->radius,2) - pow(distance_two_points(cylinder->centre, cylinder_intersect->point),2))));
		printf("distance: [%f] |", distance_cylinder_axis);
		printf("cylinder->heigt: %f |", cylinder->height);
		printf("cylinder points: [%f, %f, %f]", cylinder_intersect->point->x_co, cylinder_intersect->point->y_co, cylinder_intersect->point->z_co);
		printf("[%f]", cylinder_intersect->point->x_co);
		if (distance_cylinder_axis >= 0.0)
		{
			if (distance_cylinder_axis <= cylinder->height)
			{
				printf("bang!\n");
				cylinder_intersect->state = 1;
				
			}
		}
		printf("\n");
	}
	if(cylinder_intersect->state == 1)
	{
		//may be a memory problem somewhere here
		free_vector(vector_base_top);
		free_vector(vector_ray_origin_base_center);
		free_vector(vector_cylinder);
		free_vector(vector_ray);
		free(quadratic_result);
		return(cylinder_intersect);
	}
	cylinder_intersect->state = 0;
	free(cylinder_intersect->point);
	cylinder_intersect->point = NULL;
	free_vector(vector_base_top);
	free_vector(vector_ray_origin_base_center);
	free_vector(vector_cylinder);
	free_vector(vector_ray);
	free(quadratic_result);
	return(cylinder_intersect);
}

// double dist1 = vector_dot(vector_cylinder, vector_substract(vector_scale_direction(quadratic_result[1], vector_ray), vector_substract(cylinder->centre, ray->ray_orig)));

// 	t_vect	add_vect(const t_vect vect1, const t_vect vect2)
// {
// 	return (new_vect(vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z));
// }

// static t_vect	sub_vect(const t_vecor vect1, const t_vector vect2)
// 
// 	return (new_vect(vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z));
// }

// t_vect	minus_vect(const t_vect vect)
// {
// 	return (new_vect(-vect.x, -vect.y, -vect.z));
// }

// t_vect	multi_vect(const t_vect vect, const double x)
// {
// 	return (new_vect(vect.x * x, vect.y * x, vect.z * x));
// }

// double	dot_product(const t_vect vect1, const t_vect vect2)
// {
// 	return (vect1.x * vect2.x + vect1.y * vect2.y + vect1.z *vect2.z);
// }

// t_vect	cross_product(const t_vect v1, const t_vect v2)
// {
// 	t_vect	origin;
// 	t_vect	normal;
// 	double	denom;
// 	double	cross;

// 	origin = new_vect(0, 0, 0);
// 	denom = distance(origin, v1) * distance(origin, v2);
// 	cross = denom * sinf(acos(dot_product(v1, v2) / denom));
// 	normal = new_vect(v1.y * v2.z - v1.z * v2.y, v1.x * v2.z - v1.z * v2.x, v1.y * v2.x - v1.x * v2.y);
// 	return (multi_vect(normal, cross));
// }