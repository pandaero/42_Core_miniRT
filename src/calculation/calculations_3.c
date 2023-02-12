/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:48:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/07 19:27:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function works out the dot product of two vectors.
double	vector_dot(t_vector *first, t_vector *second)
{
	return (first->x_comp * second->x_comp + \
			first->y_comp * second->y_comp + \
			first->z_comp * second->z_comp);
}

//Function returns the size of a ft_split-created array.
int	split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//Function that returns a reversed direction, inherit both directions
t_direction	*reverse_direction(t_direction *direction)
{
	t_direction	*reverse_direction;

	reverse_direction = direction_components(\
	-direction->x_comp, \
	-direction->y_comp, \
	-direction->z_comp);
	return (reverse_direction);
}
