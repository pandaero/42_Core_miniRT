/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:22:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 15:55:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function finds the ambient light object in an object list.
t_ambient	ambient_objlist(t_objlist *objlist)
{
	t_obj		*curr;
	t_ambient	bad;

	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == AMBIENT)
			return (curr->ambient);
		curr = curr->next;
	}
	bad = ambient_input(colour_full(BLACK), 0);
	return (bad);
}

//Function finds a diffuse point-light object in an object list.
t_diffuse	diffuse_objlist(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == DIFFUSE)
			return (curr->diffuse);
		curr = curr->next;
	}
	return (diffuse_line("L 0,0,0 0"));
}

//Function counts the number of plane objects in an object list.
int	objlist_count_plane(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == PLANE)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function counts the number of sphere objects in an object list.
int	objlist_count_sphere(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == SPHERE)
			ct++;
		curr = curr->next;
	}
	return (ct);
}

//Function counts the number of cylinder objects in an object list.
int	objlist_count_cylinder(t_objlist *objlist)
{
	t_obj	*curr;
	int		ct;

	ct = 0;
	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == CYLINDER)
			ct++;
		curr = curr->next;
	}
	return (ct);
}
