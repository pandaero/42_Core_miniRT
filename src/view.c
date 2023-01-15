/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:36:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 15:03:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
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
