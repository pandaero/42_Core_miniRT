/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 10:49:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function copies a defined ray object's properties to a new one.
t_ray	ray_copy(t_ray ray)
{
	t_ray	new;

	new.ray_orig = point_copy(ray.ray_orig);
	new.ray_dir = direction_copy(ray.ray_dir);
	return (new);
}

//Function creates a defined ray object from a starting point and direction.
t_ray	ray_start_dir(t_point origin, t_direction dir)
{
	t_ray	new;

	new.ray_orig = point_copy(origin);
	new.ray_dir = direction_copy(dir);
	return (new);
}

//Function creates a defined ray object from a starting and directing point.
t_ray	ray_two_points(t_point start, t_point end)
{
	t_ray	new;

	new.ray_orig = point_copy(start);
	new.ray_dir = direction_two_points(start, end);
	return (new);
}

//Function creates a defined ray object from a vector.
t_ray	ray_start_vector(t_point start, t_vector vector)
{
	t_ray	new;

	if (vector.mag == 0)
		return (ray_start_dir(point_copy(start), \
											direction_components(0, 0, 0)));
	new.ray_orig = point_copy(start);
	new.ray_dir = direction_copy(vector.dir);
	return (new);
}
