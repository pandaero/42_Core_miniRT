/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 21:26:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function creates a defined ray object from a starting point and direction.
t_ray	*ray_start_dir(t_point *origin, t_direction *dir)
{
	t_ray	*new;

	if (!dir || dir == NULL)
		return (NULL);
	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->node->elem = RAY;
	new->ray_orig = point_copy(origin);
	new->ray_dir = direction_copy(dir);
	return (new);
}

//Function creates a defined ray object from a starting and directing point.
t_ray	*ray_two_points(t_point *start, t_point *end)
{
	t_ray	*new;

	if (start == NULL || end == NULL || start == end)
		return (NULL);
	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->node->elem = RAY;
	new->ray_orig = point_copy(start);
	new->ray_dir = direction_two_points(start, end);
	return (new);
}

//Function creates a defined ray object from a vector.
t_ray	*ray_vector(t_vector *vector)
{
	t_ray	*new;

	if (vector == NULL || vector->mag == 0)
		return (NULL);
	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->ray_orig = point_copy(vector->start);
	new->ray_dir = direction_copy(vector->dir);
	return (new);
}

//Function copies a defined ray object's properties to a new one.
t_ray	*ray_copy(t_ray *ray)
{
	t_ray	*new;

	if (ray->ray_orig == NULL || ray->dir == NULL)
		return (NULL);
	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->ray_orig = point_copy(ray->ray_orig);
	new->ray_dir = direction_copy(ray->ray_dir);
}
