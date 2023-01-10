/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:02:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 18:53:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>
#include <math.h>

//Function works out the length/distance between two points.
double	length_two_points(t_point *point_one, t_point *point_two)
{
	double	distance;

	distance = sqrt(pow(point_two->x_co - point_one->x_co, 2)
			+ pow(point_two->y_co - point_one->y_co, 2)
			+ pow(point_two->z_co - point_one->z_co, 2));
	return (distance);
}

//Function creates a new defined vector object from two points.
t_vector	*vector_two_points(t_point *start, t_point *end)
{
	t_vector	*new;

	if (start == end || (start->x_co == end->x_co
			&& start->y_co == end->y_co
			&& start->z_co == end->z_co))
		return (NULL);
	new = (t_vector *)malloc(sizeof(t_vector));
	new->start = point_copy(start);
	new->end = point_copy(end);
	new->dir = direction_two_points(start, end);
	new->mag = length_two_points(start, end);
	return (new);
}

//Function creates a new defined vector object from starting point, mag, dir.
t_vector	*vector_start_mag_dir(t_point *start, double mag, t_direction *dir)
{
	t_vector	*new;

	if (mag == 0 || !start || start == NULL || !dir || dir == NULL)
		return (NULL);
	new = (t_vector *)malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->start = point_copy(start);
	new->dir = direction_copy(dir);
	new->mag = mag;
	new->end = point_new((start->x_co + mag * dir->x_norm),
			(start->y_co + mag * dir->y_norm),
			(start->z_co + mag * dir->z_norm));
	return (new);
}

//Function copies a defined vector object's properties to a new one.
t_vector	*vector_copy(t_vector *vector)
{
	t_vector	*new;

	if (!vector || vector == NULL || vector->mag == 0)
		return (NULL);
	new = (t_vector *)malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->start = point_copy(vector->start);
	new->end = point_copy(vector->end);
	new->dir = direction_copy(vector->dir);
	new->mag = vector->mag;
	return (new);
}
