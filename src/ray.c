/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:12:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 16:27:12 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>


//Function creates and initialises a ray.
t_ray	*ray_create(void)
{
	t_ray	*new;

	new = (t_ray *)malloc(sizeof(t_ray));
	if (!new)
		return (NULL);
	new->ray_orig = NULL;
	new->ray_dir = NULL;
	return (new);
}

//Function copies a defined ray object's properties to a new one.
t_ray	*ray_copy(t_ray *ray)
{
	t_ray	*new;

	if (!ray || ray->ray_orig == NULL || ray->ray_dir == NULL)
		return (NULL);
	new = ray_create();
	if (!new)
		return (NULL);
	new->ray_orig = point_copy(ray->ray_orig);
	new->ray_dir = direction_copy(ray->ray_dir);
	return (new);
}

//Function creates a defined ray object from a starting point and direction.
t_ray	*ray_start_dir(t_point *origin, t_direction *dir)
{
	t_ray	*new;

	if (!dir || dir == NULL)
		return (NULL);
	new = ray_create();
	if (!new)
		return (NULL);
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
	new = ray_create();
	if (!new)
		return (NULL);
	new->ray_orig = point_copy(start);
	new->ray_dir = direction_two_points(start, end);
	return (new);
}

//Function creates a defined ray object from a vector.
t_ray	*ray_start_vector(t_point *start, t_vector *vector)
{
	t_ray	*new;

	if (vector == NULL || vector->mag == 0)
		return (NULL);
	new = ray_create();
	if (!new)
		return (NULL);
	new->ray_orig = point_copy(start);
	new->ray_dir = direction_copy(vector->dir);
	return (new);
}
