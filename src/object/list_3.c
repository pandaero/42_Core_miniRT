/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:22:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 17:04:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function finds the ambient light object in an object list.
t_ambient	*ambient_objlist(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr)
	{
		if (curr->ambient || curr->elem == AMBIENT)
			return (curr->ambient);
		curr = curr->next;
	}
	return (NULL);
}

//Function finds a diffuse point-light object in an object list.
t_diffuse	*diffuse_objlist(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr)
	{
		if (curr->diffuse || curr->elem == DIFFUSE)
			return (curr->diffuse);
		curr = curr->next;
	}
	return (NULL);
}
