/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a plane object from a valid input line.
t_obj	*object_plane_line(t_program *program, const char *line)
{
	t_obj	*new;
	t_plane	*plane;

	new = object_create();
	if (!new)
		return (NULL);
	plane = plane_line(line);
	if (!plane)
	{
		free_object(new);
		error_object_creation_exit(program, "PLANE");
	}
	ft_printf("PLANE Colour: %x\n", plane->colour->full);
	new->elem = PLANE;
	new->plane = plane;
	return (new);
}

//Function creates a sphere object from a valid input line.
t_obj	*object_sphere_line(t_program *program, const char *line)
{
	t_obj		*new;
	t_sphere	*sphere;

	new = object_create();
	if (!new)
		return (NULL);
	sphere = sphere_line(line);
	if (!sphere)
	{
		free_object(new);
		error_object_creation_exit(program, "SPHERE");
	}
	ft_printf("SPHERE Colour: %x\n", sphere->colour->full);
	new->elem = SPHERE;
	new->sphere = sphere;
	return (new);
}

//Function creates a cylinder object from a valid input line.
t_obj	*object_cylinder_line(t_program *program, const char *line)
{
	t_obj		*new;
	t_cylinder	*cylinder;

	new = object_create();
	if (!new)
		return (NULL);
	cylinder = cylinder_line(line);
	if (!cylinder)
	{
		free_object(new);
		error_object_creation_exit(program, "CYLINDER");
	}
	new->elem = CYLINDER;
	new->cylinder = cylinder;
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

//Function makes a diffuse point-light object.
t_obj	*object_diffuse(t_diffuse *diffuse)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DIFFUSE;
	new->diffuse = diffuse;
	return (new);
}
