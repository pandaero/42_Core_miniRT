/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 19:43:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a cylinder object.
t_obj	*object_cylinder(t_cylinder cylinder)
{
	t_obj	*new;

	new = object_create();
	new->elem = CYLINDER;
	new->cylinder = cylinder_copy(cylinder);
	return (new);
}

//Function creates an ambient light object from an input line.
t_obj	*object_ambient_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = AMBIENT;
	new->ambient = ambient_line(line);
	return (new);
}

//Function creates an ambient light object from a valid input line.
t_obj	*object_camera_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = CAMERA;
	new->camera = camera_line(line);
	return (new);
}

//Function creates a diffuse light object from a valid input line.
t_obj	*object_diffuse_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DIFFUSE;
	new->diffuse = diffuse_line(line);
	return (new);
}

//Function makes a diffuse point-light object.
t_obj	*object_diffuse(t_diffuse diffuse)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = DIFFUSE;
	new->diffuse = diffuse_copy(diffuse);
	return (new);
}
