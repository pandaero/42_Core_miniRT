/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:07:02 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 12:19:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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
