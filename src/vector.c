/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:02:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 12:54:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>
#include <math.h>

//Function creates and initialises a vector.
t_vector	*vector_create(void)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	if (!new)
		return (NULL);
	new->mag = 0;
	new->x_comp = 0;
	new->y_comp = 0;
	new->z_comp = 0;
	new->dir = NULL;
	return (new);
}

//Function copies a defined vector object's properties to a new one.
t_vector	*vector_copy(t_vector *vector)
{
	t_vector	*new;

	if (!vector || vector == NULL || vector->mag == 0)
		return (NULL);
	new = vector_create();
	if (!new)
		return (NULL);
	new->dir = direction_copy(vector->dir);
	new->mag = vector->mag;
	new->x_comp = vector->x_comp;
	new->y_comp = vector->y_comp;
	new->z_comp = vector->z_comp;
	return (new);
}

//Function creates a new defined vector object from two points.
t_vector	*vector_two_points(t_point *start, t_point *end)
{
	t_vector	*new;

	if (start == end || (start->x_co == end->x_co && start->y_co == end->y_co
			&& start->z_co == end->z_co))
		return (NULL);
	new = vector_create();
	if (!new)
		return (NULL);
	new->dir = direction_two_points(start, end);
	new->mag = distance_two_points(start, end);
	new->x_comp = new->mag * new->dir->x_comp;
	new->y_comp = new->mag * new->dir->y_comp;
	new->z_comp = new->mag * new->dir->z_comp;
	return (new);
}

//Function creates a new defined vector object from magnitude and direction.
t_vector	*vector_mag_dir(double mag, t_direction *dir)
{
	t_vector	*new;

	if (mag == 0 || !dir)
		return (NULL);
	new = vector_create();
	if (!new)
		return (NULL);
	new->dir = direction_copy(dir);
	new->mag = mag;
	new->x_comp = mag * dir->x_comp;
	new->y_comp = mag * dir->y_comp;
	new->z_comp = mag * dir->z_comp;
	return (new);
}
