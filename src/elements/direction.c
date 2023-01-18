/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:00:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 18:37:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a direction.
t_direction	*direction_create(void)
{
	t_direction	*new;

	new = (t_direction *)malloc(sizeof(t_direction));
	if (!new)
		return (NULL);
	new->x_comp = 0;
	new->y_comp = 0;
	new->z_comp = 0;
	return (new);
}

//Function copies a defined direction object's properties to a new one.
t_direction	*direction_copy(t_direction *direction)
{
	t_direction	*new;

	new = direction_create();
	if (!new)
		return (NULL);
	new->x_comp = direction->x_comp;
	new->y_comp = direction->y_comp;
	new->z_comp = direction->z_comp;
	return (new);
}

//Function creates a defined direction from components.
t_direction	*direction_components(double x_comp, double y_comp, double z_comp)
{
	t_direction	*new;
	double		mag;

	new = direction_create();
	if (!new)
		return (NULL);
	mag = magnitude_components(x_comp, y_comp, z_comp);
	new->x_comp = x_comp / mag;
	new->y_comp = y_comp / mag;
	new->z_comp = z_comp / mag;
	return (new);
}

//Function creates a defined direction from two points.
t_direction	*direction_two_points(t_point *start, t_point *end)
{
	t_direction	*new;

	if (start == end || (start->x_co == end->x_co
			&& start->y_co == end->y_co
			&& start->z_co == end->z_co))
		return (NULL);
	new = direction_create();
	if (!new)
		return (NULL);
	new->x_comp = (end->x_co - start->x_co) / distance_two_points(start, end);
	new->y_comp = (end->y_co - start->y_co) / distance_two_points(start, end);
	new->z_comp = (end->z_co - start->z_co) / distance_two_points(start, end);
	return (new);
}

//Function creates a defined direction object from a vector.
t_direction	*direction_vector(t_vector *vector)
{
	t_direction	*new;

	if (vector->mag == 0)
		return (NULL);
	new = direction_create();
	if (!new)
		return (NULL);
	new->x_comp = vector->dir->x_comp;
	new->y_comp = vector->dir->y_comp;
	new->z_comp = vector->dir->z_comp;
	return (new);
}
