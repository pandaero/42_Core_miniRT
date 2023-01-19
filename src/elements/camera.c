/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:36:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 21:26:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Function creates and initialises a camera.
t_camera	*camera_create(void)
{
	t_camera	*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	new->horiz_fov = 0;
	new->location = NULL;
	new->view_dir = NULL;
	return (new);
}

//Function creates a camera from input parameters.
t_camera	*camera_input(t_point *loc, t_direction *view_dir, double hfov_deg)
{
	t_camera	*new;

	new = camera_create();
	new->location = point_copy(loc);
	new->view_dir = direction_copy(view_dir);
	new->horiz_fov = radians_degrees(hfov_deg);
	return (new);
}

//Function creates a camera from a valid input line.
t_camera	*camera_line(const char *str)
{
	t_camera	*new;
	char		**split;
	char		*clean;

	new = camera_create();
	if (!new)
		return (NULL);
	split = ft_split(str, ' ');
	if (contains_newline(split[3]) == 1)
	{
		clean = clean_newline(split[3]);
		new->horiz_fov = ft_atof(clean);
		free(clean);
	}
	else
		new->horiz_fov = ft_atof(split[3]);
	new->location = point_line(split[1]);
	new->view_dir = direction_line(split[2]);
	free_split(split);
	return (new);
}
