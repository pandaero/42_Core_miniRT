/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:02:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 16:10:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function copies a defined vector object's properties to a new one.
t_vector	vector_copy(t_vector vector)
{
	t_vector	new;

	new.dir = direction_copy(vector.dir);
	new.mag = vector.mag;
	new.x_comp = vector.x_comp;
	new.y_comp = vector.y_comp;
	new.z_comp = vector.z_comp;
	return (new);
}

//Function creates a new defined vector from a scalar and a direction.
t_vector	vector_scale_direction(double scalar, t_direction dir)
{
	t_vector	new;

	new.mag = fabs(scalar);
	new.dir = direction_copy(dir);
	new.x_comp = scalar * new.dir.x_comp;
	new.y_comp = scalar * new.dir.y_comp;
	new.z_comp = scalar * new.dir.z_comp;
	return (new);
}

//Function creates a new defined vector object from two points.
t_vector	vector_two_points(t_point start, t_point end)
{
	t_vector	new;

	if (start.x_co == end.x_co && start.y_co == end.y_co && \
												start.z_co == end.z_co)
		return (vector_components(0, 0, 0));
	new.dir = direction_two_points(start, end);
	new.mag = distance_two_points(start, end);
	new.x_comp = new.mag * new.dir.x_comp;
	new.y_comp = new.mag * new.dir.y_comp;
	new.z_comp = new.mag * new.dir.z_comp;
	return (new);
}

//Function creates a new defined vector object from magnitude and direction.
t_vector	vector_mag_dir(double mag, t_direction dir)
{
	t_vector	new;

	if (mag == 0)
		return (vector_components(0, 0, 0));
	new.dir = direction_copy(dir);
	new.mag = mag;
	new.x_comp = mag * dir.x_comp;
	new.y_comp = mag * dir.y_comp;
	new.z_comp = mag * dir.z_comp;
	return (new);
}
