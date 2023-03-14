/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:17:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 11:33:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises an object.
t_obj	*object_create(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	new->elem = EMPTY;
	new->prev = NULL;
	new->next = NULL;
	new->ren = 0;
	new->sec_ren = 0;
	return (new);
}

//Function creates a screen object.
t_obj	*object_screen(t_screen screen)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = SCREEN;
	new->screen = screen_copy(screen);
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
