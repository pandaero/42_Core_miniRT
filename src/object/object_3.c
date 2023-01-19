/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 21:25:59 by pandalaf         ###   ########.fr       */
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
/*
//Function creates an ambient light object from an input line.
t_obj	*object_ambient_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	return (new);
}
*/
//Function creates an ambient light object from a valid input line.
t_obj	*object_camera_line(const char *line)
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
		return (NULL);
	}
	new->elem = CAMERA;
	new->camera = cam;
	return (new);
}
/*
//Function creates a light object from a valid input line.
t_obj	*object_light_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	return (new);
}
*/
