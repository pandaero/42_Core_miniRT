/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:17:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/12 18:53:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function creates and initialises an object.
t_obj	*object_create(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	new->elem = EMPTY;
	new->point = NULL;
	new->direction = NULL;
	new->vector = NULL;
	new->ray = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

//Function copies an object's properties to a new one.
t_obj	*object_copy(t_obj *object)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = object->elem;
	new->point = object->point;
	new->direction = object->direction;
	new->vector = object->vector;
	new->ray = object->ray;
	return (new);
}

//Function creates a point object.
t_obj	*object_point(t_point *point)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = POINT;
	new->point = point;
	return (new);
}

//Function creates a direction object.
t_obj	*object_direction(t_direction *direction)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = DIRECTION;
	new->direction = direction;
	return (new);
}

//Function creates a direction object.
t_obj	*object_vector(t_vector *vector)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = VECTOR;
	new->vector = vector;
	return (new);
}
