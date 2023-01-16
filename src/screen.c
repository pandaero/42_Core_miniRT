/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:26:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/16 15:26:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Function creates and initialises a screen points structure.
t_scr_pts	*screen_pts_create(void)
{
	t_scr_pts	*new;

	new = (t_scr_pts *)malloc(sizeof(t_scr_pts));
	new->centre = NULL;
	new->top_centre = NULL;
	new->tl_corner = NULL;
	new->first_px = NULL;
	return (new);
}

//Function creates and initialises a screen vectors structure.
t_scr_vec	*screen_vecs_create(void)
{
	t_scr_vec	*new;

	new = (t_scr_vec *)malloc(sizeof(t_scr_vec));
	new->normal = NULL;
	new->screen_up = NULL;
	new->screen_right = NULL;
	new->vec_up = NULL;
	new->vec_down = NULL;
	new->vec_left = NULL;
	new->vec_right = NULL;
	new->vec_corner_up = NULL;
	new->vec_corner_left = NULL;
	new->vec_screen_rd = NULL;
	new->vec_screen_rd_0th = NULL;
	return (new);
}

//Function creates and initialises a screen.
t_screen	*screen_create(void)
{
	t_screen	*new;

	new = (t_screen *)malloc(sizeof(t_screen));
	new->pts = screen_pts_create();
	new->vecs = screen_vecs_create();
	new->width = 0;
	new->height = 0;
	new->pixels = NULL;
	return (new);
}

//Function works out the centre of the screen based on the camera properties.
t_point	*screen_centre(double width, t_camera *camera)
{
	t_point		*centre;
	t_point		*cam_point;
	t_vector	*dist_vec;
	double		distance;

	cam_point = camera->location;
	distance = (0.5 * width) / tan(camera->horiz_fov / 2);
	dist_vec = vector_scale_direction(distance, camera->view_dir);
	centre = point_point_vector(cam_point, dist_vec);
	free_vector(dist_vec);
	return (centre);
}

//Function works out the screen-up direction.
t_direction	*screen_up(t_camera *camera)
{
	t_direction	*screen_up;
	t_direction	*horiz;
	t_point		*origin;
	t_point		*p_horiz;

	origin = point_coords(0, 0, 0);
	if (camera->view_dir->x_comp == 1 || camera->view_dir->x_comp == -1)
		p_horiz = point_coords(0, 1, 0);
	else
		p_horiz = point_coords(1, 0, 0);
	horiz = direction_two_points(origin, p_horiz);
	screen_up = direction_cross_up(camera->view_dir, horiz);
	free_point(origin);
	free_point(p_horiz);
	free_direction(horiz);
	return (screen_up);
}
