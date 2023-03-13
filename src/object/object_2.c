/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:52:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 19:41:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a camera object.
t_obj	*object_camera(t_camera camera)
{
	t_obj	*new;

	new = object_create();
	new->ren = 1;
	new->sec_ren = 1;
	new->elem = CAMERA;
	new->camera = camera_copy(camera);
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

//Function creates a plane object.
t_obj	*object_plane(t_plane plane)
{
	t_obj	*new;

	new = object_create();
	new->elem = PLANE;
	new->plane = plane_copy(plane);
	return (new);
}

//Function creates a sphere object.
t_obj	*object_sphere(t_sphere sphere)
{
	t_obj	*new;

	new = object_create();
	new->elem = SPHERE;
	new->sphere = sphere_copy(sphere);
	return (new);
}
