/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 02:19:02 by pandalaf         ###   ########.fr       */
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

//Function makes an ambient light object.
t_obj	*object_ambient(t_ambient ambient)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = AMBIENT;
	new->ambient = ambient_copy(ambient);
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
