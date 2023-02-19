/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:17:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:04:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises an object.
t_obj	*object_create(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	new->ren = 0;
	new->sec_ren = 0;
	new->elem = EMPTY;
	new->ambient = NULL;
	new->diffuse = NULL;
	new->point = NULL;
	new->direction = NULL;
	new->vector = NULL;
	new->ray = NULL;
	new->camera = NULL;
	new->screen = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

//Function copies an object's properties to a new one.
t_obj	*object_copy(t_obj *object)
{
	t_obj	*new;

	if (!object)
		return (NULL);
	new = object_create();
	if (!new)
		return (NULL);
	new->ren = object->ren;
	new->sec_ren = object->sec_ren;
	new->elem = object->elem;
	new->point = point_copy(object->point);
	new->direction = direction_copy(object->direction);
	new->vector = vector_copy(object->vector);
	new->ray = ray_copy(object->ray);
	return (new);
}

//Function creates a point object.
t_obj	*object_point(t_point *point)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = POINT;
	new->point = point_copy(point);
	return (new);
}

//Function creates a direction object.
t_obj	*object_direction(t_direction *direction)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DIRECTION;
	new->direction = direction_copy(direction);
	return (new);
}

//Function creates a vector object.
t_obj	*object_vector(t_vector *vector)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = VECTOR;
	new->vector = vector_copy(vector);
	return (new);
}
