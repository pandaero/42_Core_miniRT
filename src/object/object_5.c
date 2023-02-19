/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:13:01 by pandalaf         ###   ########.fr       */
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
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = AMBIENT;
	new->ambient = ambient;
	return (new);
}

//Function finds the first renderable object in the object linked list.
t_obj	*object_first_list(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr && objlist->num_unren > 0)
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

//Function creates a disc object.
t_obj	*object_disc(t_disc *disc)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DISC;
	new->disc = disc;
	return (new);
}
