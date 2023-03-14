/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:41:02 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function counts the number of ambient objects in an object list.
int	objlist_count_ambient(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == AMBIENT)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function counts the number of light objects in an object list.
int	objlist_count_diffuse(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == DIFFUSE)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function counts the number of camera objects in an object list.
int	objlist_count_camera(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == CAMERA)
			ct++;
		curr = curr->next;
	}
	return (ct);
}
