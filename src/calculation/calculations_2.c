/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:07:02 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function adds two vectors together.
t_vector	*vector_add(t_vector *first, t_vector *second)
{
	t_vector	*new;

	new = vector_create();
	new->x_comp = first->x_comp + second->x_comp;
	new->y_comp = first->y_comp + second->y_comp;
	new->z_comp = first->z_comp + second->z_comp;
	new->dir = direction_components(new->x_comp, new->y_comp, new->z_comp);
	new->mag = magnitude_components(new->x_comp, new->y_comp, new->z_comp);
	return (new);
}

//Function subtracts two vectors.
t_vector	*vector_subtract(t_vector *first, t_vector *second)
{
	t_vector	*new;

	new = vector_create();
	new->x_comp = first->x_comp - second->x_comp;
	new->y_comp = first->y_comp - second->y_comp;
	new->z_comp = first->z_comp - second->z_comp;
	new->dir = direction_components(new->x_comp, new->y_comp, new->z_comp);
	new->mag = magnitude_components(new->x_comp, new->y_comp, new->z_comp);
	return (new);
}

//Function scales a vector.
t_vector	*vector_scale(double scalar, t_vector *vector)
{
	t_vector	*new;

	new = vector_create();
	new->mag = scalar * vector->mag;
	new->dir = direction_copy(vector->dir);
	new->x_comp = scalar * vector->x_comp;
	new->y_comp = scalar * vector->y_comp;
	new->z_comp = scalar * vector->z_comp;
	return (new);
}

//Function works out the vector cross product of two vectors.
t_vector	*vector_cross(t_vector *first, t_vector *second)
{
	t_vector	*vec_prod;

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
	return (vec_prod);
}

//Function determines whether a string contains a decima point character.
int	contains_decimal(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}
