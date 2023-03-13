/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:17:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 19:39:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

t_obj	*object_create(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	new->elem = EMPTY;
	new->prev = NULL;
	new->next = NULL;
	new->ren = 0;
	new->sec_ren = 0;
	return (new);
}

//Function creates a new empty object.
t_obj	*object_null(void)
{
	return (object_create());
}

//Function copies an object's properties to a new one.
t_obj	*object_copy(t_obj object)
{
	t_obj	*new;

	new = object_create();
	new->ren = object.ren;
	new->sec_ren = object.sec_ren;
	new->elem = object.elem;
	new->ambient = ambient_copy(object.ambient);
	new->diffuse = diffuse_copy(object.diffuse);
	new->camera = camera_copy(object.camera);
	new->prev = object.prev;
	new->next = object.next;
	return (new);
}
