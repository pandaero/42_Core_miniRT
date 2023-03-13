/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 19:47:59 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a plane object from a valid input line.
t_obj	*object_plane_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->elem = PLANE;
	new->plane = plane_line(line);
	return (new);
}

//Function creates a sphere object from a valid input line.
t_obj	*object_sphere_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->elem = SPHERE;
	new->sphere = sphere_line(line);
	return (new);
}

//Function creates a cylinder object from a valid input line.
t_obj	*object_cylinder_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->elem = CYLINDER;
	new->cylinder = cylinder_line(line);
	return (new);
}

//Function finds any unrendered object in the object linked list.
t_obj	*object_unrendered_list(t_objlist *objlist)
{
	t_obj	*curr;

	curr = objlist->first;
	while (curr && objlist->num_unren > 0)
	{
		if (curr->ren == 0)
			return (curr);
		if (curr->next == NULL)
			curr = objlist->first;
		else
			curr = curr->next;
	}
	return (NULL);
}
