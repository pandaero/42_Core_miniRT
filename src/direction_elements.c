/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:00:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 18:48:50 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function creates a defined direction object from two points.
t_direction	*direction_two_points(t_point *start, t_point *end)
{
	t_direction	*new;

	if (start == end || (start->x_co == end->x_co
			&& start->y_co == end->y_co
			&& start->z_co == end->z_co))
		return (NULL);
	new = (t_direction *)malloc(sizeof(t_direction));
	if (!new)
		return (NULL);
	new->x_norm = (end->x_co - start->x_co) / length_two_points(start, end);
	new->y_norm = (end->y_co - start->y_co) / length_two_points(start, end);
	new->z_norm = (end->z_co - start->z_co) / length_two_points(start, end);
	return (new);
}

//Function creates a defined direction object from a vector.
t_direction	*direction_vector(t_vector *vector)
{
	t_direction	*new;

	if (vector->mag == 0)
		return (NULL);
	new = (t_direction *)malloc(sizeof(t_direction));
	if (!new)
		return (NULL);
	new->x_norm = vector->dir->x_norm;
	new->y_norm = vector->dir->y_norm;
	new->z_norm = vector->dir->z_norm;
	return (new);
}

//Function copies a defined direction object's properties to a new one.
t_direction	*direction_copy(t_direction *direction)
{
	t_direction	*new;

	new = (t_direction *)malloc(sizeof(t_direction));
	if (!new)
		return (NULL);
	new->x_norm = direction->x_norm;
	new->y_norm = direction->y_norm;
	new->z_norm = direction->z_norm;
	return (new);
}
