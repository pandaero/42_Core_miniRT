/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:52:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 04:21:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a ray object.
t_obj	*object_ray(t_ray *ray)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = RAY;
	new->ray = ray;
	return (new);
}

//Function creates a camera object.
t_obj	*object_camera(t_camera *camera)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = CAMERA;
	new->camera = camera;
	return (new);
}

//Function creates a screen object.
t_obj	*object_screen(t_screen *screen)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = SCREEN;
	new->screen = screen;
	return (new);
}

//Function creates a plane object.
t_obj	*object_plane(t_plane *plane)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->unrendered = 1;
	new->elem = PLANE;
	new->plane = plane;
	return (new);
}

//Function creates a sphere object.
t_obj	*object_sphere(t_sphere *sphere)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	num->unrendered = 1;
	new->elem = SPHERE;
	new->sphere = sphere;
	return (new);
}
