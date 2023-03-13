/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:36:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 18:25:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Function creates a camera element from another.
t_camera	camera_copy(t_camera other)
{
	t_camera	new;

	new.horiz_fov = other.horiz_fov;
	new.location = point_copy(other.location);
	new.view_dir = direction_copy(other.view_dir);
	return (new);
}

//Function creates a camera from input parameters.
t_camera	camera_input(t_point loc, t_direction view_dir, double hfov_deg)
{
	t_camera	new;

	new.location = point_copy(loc);
	new.view_dir = direction_copy(view_dir);
	new.horiz_fov = radians_degrees(hfov_deg);
	return (new);
}

//Function creates a camera from a valid input line.
t_camera	camera_line(const char *str)
{
	t_camera	new;
	char		**split;
	char		*clean;

	split = ft_split(str, ' ');
	if (contains_newline(split[3]) == 1)
	{
		clean = clean_newline(split[3]);
		new.horiz_fov = ft_atof(clean);
		free(clean);
	}
	else
		new.horiz_fov = ft_atof(split[3]);
	new.location = point_str(split[1]);
	new.view_dir = direction_str(split[2]);
	free_split(split);
	return (new);
}

//Function locates the camera from the program structure.
t_camera	camera_program(t_program *program)
{
	t_obj		*curr;
	t_camera	bad;

	curr = program->objlist->first;
	while (curr)
	{
		if (curr->elem == CAMERA)
			return (curr->camera);
		curr = curr->next;
	}
	bad = camera_input(point_coords(0, 0, 0), direction_components(0, 0, 0), 0);
	return (bad);
}

//Function locates the camera from an object list.
t_camera	camera_objlist(t_objlist *objlist)
{
	t_obj		*curr;
	t_camera	bad;


	curr = objlist->first;
	while (curr)
	{
		if (curr->elem == CAMERA)
			return (curr->camera);
		curr = curr->next;
	}
	bad = camera_input(point_coords(0, 0, 0), direction_components(0, 0, 0), 0);
	return (bad);
}
