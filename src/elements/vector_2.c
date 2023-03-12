/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:31:51 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 23:54:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a vector from the origin to a point.
t_vector	*vector_point(t_point *point)
{
	t_vector	*vector;
	t_point		*origin;

	origin = point_coords(0, 0, 0);
	vector = vector_two_points(origin, point);
	free_point(origin);
	return (vector);
}

//Function creates a vector from its components.
t_vector	*vector_components(double x_comp, double y_comp, double z_comp)
{
	t_vector	*vector;

	vector = vector_create();
	vector->mag = magnitude_components(x_comp, y_comp, z_comp);
	vector->x_comp = x_comp;
	vector->y_comp = y_comp;
	vector->z_comp = z_comp;
	vector->dir = direction_components(x_comp, y_comp, z_comp);
	return (vector);
}
