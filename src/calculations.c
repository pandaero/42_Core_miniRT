/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:30:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 15:04:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <math.h>

//Function converts degrees to radians.
double	radians_degrees(double deg)
{
	return (deg * M_PI / 180);
}

//Function works out the length/distance between two points.
double	distance_two_points(t_point *point_one, t_point *point_two)
{
	double	distance;

	distance = sqrt(pow(point_two->x_co - point_one->x_co, 2)
			+ pow(point_two->y_co - point_one->y_co, 2)
			+ pow(point_two->z_co - point_one->z_co, 2));
	return (distance);
}

//Function works out the magnitude of a vector from its components.
double	magnitude_components(double x_comp, double y_comp, double z_comp)
{
	double	mag;

	mag = sqrt(pow(x_comp, 2) + pow(y_comp, 2) + pow(z_comp, 2));
	mag = sqrt(pow(0, 2) + pow(1, 2) + pow(0, 2));
	return (mag);
}

//Function works out the direction component of the vector cross product.
t_direction	*direction_cross(t_direction *first, t_direction *second)
{
	t_vector	*vec_prod;
	t_direction	*unit_dir;

	vec_prod = vector_create();
	if (!vec_prod)
		return (NULL);
	vec_prod->x_comp = first->y_comp * second->z_comp - \
			first->z_comp * second->y_comp;
	vec_prod->y_comp = -1 * first->x_comp * second->z_comp + \
			first->z_comp * second->x_comp;
	vec_prod->z_comp = first->x_comp * second->y_comp - \
			first->y_comp * second->x_comp;
	vec_prod->mag = magnitude_components(vec_prod->x_comp, vec_prod->y_comp, \
			vec_prod->z_comp);
	vec_prod->dir = direction_create();
	vec_prod->dir->x_comp = vec_prod->x_comp / vec_prod->mag;
	vec_prod->dir->y_comp = vec_prod->y_comp / vec_prod->mag;
	vec_prod->dir->z_comp = vec_prod->z_comp / vec_prod->mag;
	unit_dir = direction_vector(vec_prod);
	if (!unit_dir)
		return (free_vector_null(vec_prod));
	free_vector(vec_prod);
	return (unit_dir);
}

//Function returns the direction component of cross product that points z+.
t_direction	*direction_cross_up(t_direction *first, t_direction *second)
{
	t_direction	*cross1;
	t_direction	*cross2;

	cross1 = direction_cross(first, second);
	if (!cross1)
		return (NULL);
	cross2 = direction_cross(second, first);
	if (!cross2)
		return (NULL);
	if (cross1->z_comp > 0)
	{
		free_direction(cross2);
		return (cross1);
	}
	else if (cross2->z_comp >= 0)
	{
		free_direction(cross1);
		return (cross2);
	}
	else
		return (NULL);
}
