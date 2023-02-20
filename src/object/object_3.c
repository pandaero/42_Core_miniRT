/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 02:42:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a cylinder object.
t_obj	*object_cylinder(t_cylinder *cylinder)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = CYLINDER;
	new->cylinder = cylinder;
	return (new);
}

//Function creates an ambient light object from an input line.
t_obj	*object_ambient_line(t_program *program, const char *line)
{
	t_obj		*new;
	t_ambient	*ambient;

	new = object_create();
	if (!new)
		return (NULL);
	ambient = ambient_line(line);
	if (!ambient)
	{
		free_object(new);
		error_object_creation_exit(program, "AMBIENT");
	}
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = AMBIENT;
	new->ambient = ambient;
	return (new);
}

//Function creates an ambient light object from a valid input line.
t_obj	*object_camera_line(t_program *program, const char *line)
{
	t_obj		*new;
	t_camera	*cam;

	new = object_create();
	if (!new)
		return (NULL);
	cam = camera_line(line);
	if (!cam)
	{
		free_object(new);
		error_object_creation_exit(program, "CAMERA");
	}
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = CAMERA;
	new->camera = cam;
	return (new);
}

//Function creates a diffuse light object from a valid input line.
t_obj	*object_diffuse_line(t_program *program, \
								const char *line)
{
	t_obj		*new;
	t_diffuse	*light;

	new = object_create();
	if (!new)
		return (NULL);
	light = diffuse_line(line);
	if (!light)
	{
		free_object(new);
		error_object_creation_exit(program, "LIGHT");
	}
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DIFFUSE;
	new->diffuse = light;
	return (new);
}
