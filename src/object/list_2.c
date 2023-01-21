/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:41:02 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/21 03:08:25 by pandalaf         ###   ########.fr       */
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
		if (curr->ambient || curr->elem == AMBIENT)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function counts the number of light objects in an object list.
int	objlist_count_light(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->light || curr->elem == LIGHT)
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
		if (curr->camera || curr->elem == CAMERA)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function cycles through plane objects checking that direction is non-null.
int	objlist_plane_check_dir(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == PLANE)
		{
			if (curr->plane)
			{
				if (!curr->plane->normal)
					return (0);
			}			
		}
		curr = curr->next;
	}
	return (1);
}

//Function cycles through cylinder objects checking that direction is non-null.
int	objlist_cylinder_check_dir(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == CYLINDER)
		{
			if (curr->cylinder)
			{
				if (!curr->cylinder->orientation)
					return (0);
			}
		}
		curr = curr->next;
	}
	return (1);
}
