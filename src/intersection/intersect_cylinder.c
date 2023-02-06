/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/06 11:56:07 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

#define HAS_TWO_RESULTS 1
#define HAS_ONE_OR_INFINITE_RESULT 2
//Cylinder

/*Need to enter complete formula to see effects. If not today will try with a different formula. 
Also grasp the basis of linear algebra.

Need to check the ray, with the plane it's fine.
*/

static t_cylinder_locals	*initialize_variables(t_ray *ray, t_cylinder *cylinder)
{
	t_cylinder_locals	*loc;

	loc = (t_cylinder_locals*)malloc(sizeof(t_cylinder_locals));
	loc->cyl_up = vector_scale_direction(cylinder->height / 2, cylinder->orientation);
	loc->cyl_down = vector_scale_direction((-cylinder->height) / 2, cylinder->orientation);
	loc->H = point_point_vector(cylinder->centre, loc->cyl_up);
	loc->C = point_point_vector(cylinder->centre, loc->cyl_down);
	loc->w = vector_two_points(ray->ray_orig, loc->C); //may be something with ray origin - how to check it
	loc->ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
	loc->cylinder_orientation_vec = vector_scale_direction(1, cylinder->orientation);
	loc->a = vector_dot(loc->ray_dir_vec, loc->ray_dir_vec) \
	- pow(vector_dot(loc->ray_dir_vec, loc->cylinder_orientation_vec), 2);
	loc->b = 2 * (vector_dot(loc->ray_dir_vec, loc->w) - \
	vector_dot(loc->ray_dir_vec, loc->cylinder_orientation_vec) * \
	vector_dot(loc->w, loc->cylinder_orientation_vec));
	loc->c = vector_dot(loc->w, loc->w) - pow(vector_dot\
	(loc->w, loc->cylinder_orientation_vec), 2) - \
	pow(cylinder->radius, 2);
	return(loc);
}

t_intersect *initialize_intersection()
{
	t_intersect	*intersection;
	
	intersection = (t_intersect*)malloc(sizeof(t_intersect));
	intersection->point = (t_point*)malloc(sizeof(t_point));
	return(intersection);
}

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect				*intersection;
	t_cylinder_locals		*loc;
	double					*quadratic_result;
	double					distance_from_base;

	intersection = initialize_intersection();
	loc = initialize_variables(ray, cylinder);
	quadratic_result = solve_quadratic_real(loc->a, loc->b, loc->c);
	if(quadratic_result[0] != HAS_TWO_RESULTS && quadratic_result[0] != HAS_ONE_OR_INFINITE_RESULT)
	{
		intersection->state = 0;
		return (intersection);
	}
	if(quadratic_result[1] > quadratic_result[2] && quadratic_result[0] == HAS_TWO_RESULTS)
	{
		intersection->point = get_intersection_point(ray, quadratic_result[1]);
		intersection->distance = quadratic_result[1];
	}
	else if(quadratic_result[1] < quadratic_result[2] && quadratic_result[0] == HAS_TWO_RESULTS)
	{
		intersection->point = get_intersection_point(ray, quadratic_result[2]);
		intersection->distance = quadratic_result[2];
	}
	else if (quadratic_result[0] == HAS_ONE_OR_INFINITE_RESULT)
	{
		intersection->point = get_intersection_point(ray, quadratic_result[1]);
		intersection->distance = quadratic_result[1];
	}
	t_vector *intersection_point_base_point = vector_two_points(intersection->point, loc->C);
	distance_from_base = vector_dot(loc->cylinder_orientation_vec, intersection_point_base_point);
	if (distance_from_base < 0 || distance_from_base > cylinder->height)
	{
		// if (distance_from_base < 0)
		// {
		// 	t_plane	*lower_cap = plane_col_point_normal_dir(0x00FF00, loc->C, cylinder->orientation); // direction could be inverted
		// 	intersection = intersection_ray_plane(ray, lower_cap);
		// }
		// else if (distance_from_base > cylinder->height)
		// {
		// 	t_plane	*lower_cap = plane_col_point_normal_dir(0xFF0000, loc->H, cylinder->orientation);
		// 	intersection = intersection_ray_plane(ray, lower_cap);
		// }
			// printf("top cap intersection");
		intersection->state = 0;
		return (intersection);
	}
	intersection->state = 1;
	return(intersection);
}
