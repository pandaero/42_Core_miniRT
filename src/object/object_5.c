/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/12 13:05:09 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function makes an ambient light object.
t_obj	*object_ambient(t_ambient *ambient)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = AMBIENT;
	new->ambient = ambient;
	return (new);
}

//Function finds the first renderable object in the object linked list.
t_obj	*object_first_list(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr && objlist->num_unrendered > 0)
	{
		if (curr->elem == PLANE || curr->elem == SPHERE)
			return (curr);
		if (curr->elem == CYLINDER)
			return (curr);
		if (curr->next == NULL)
			curr = objlist->first;
		else
			curr = curr->next;
	}
	return (NULL);
}