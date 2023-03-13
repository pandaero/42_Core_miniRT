/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:26:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 18:29:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function copies screen points from another struct.
t_scr_pts	scr_pts_copy(t_scr_pts other)
{
	t_scr_pts	new;

	new.centre = point_copy(other.centre);
	new.first_px = point_copy(other.first_px);
	new.tl_corner = point_copy(other.tl_corner);
	new.top_centre = point_copy(other.top_centre);
	return (new);
}

//Function copies screen vectors from another struct.
t_scr_vec	scr_vecs_copy(t_scr_vec other)
{
	t_scr_vec	new;

	new.normal = direction_copy(other.normal);
	new.screen_up = direction_copy(other.screen_up);
	new.screen_right = direction_copy(other.screen_right);
	new.vec_up = vector_copy(other.vec_up);
	new.vec_down = vector_copy(other.vec_down);
	new.vec_left = vector_copy(other.vec_left);
	new.vec_right = vector_copy(other.vec_right);
	new.vec_corner_up = vector_copy(other.vec_corner_up);
	new.vec_corner_left = vector_copy(other.vec_corner_left);
	new.vec_screen_rd = vector_copy(other.vec_screen_rd);
	new.vec_screen_rd_0th = vector_copy(other.vec_screen_rd_0th);
	return (new);
}

//Function creates a new screen element from another.
t_screen	screen_copy(t_screen other)
{
	t_screen	new;

	new.width = other.width;
	new.height = other.height;
	new.pts = scr_pts_copy(other.pts);
	new.vecs = scr_vecs_copy(other.vecs);
	new.pixels = other.pixels;
	return (new);
}

//Function works out the centre of the screen based on the camera properties.
t_point	screen_centre(double width, t_camera camera)
{
	t_point		centre;
	t_point		cam_point;
	t_vector	dist_vec;
	double		distance;

	cam_point = camera.location;
	distance = (0.5 * width * VIEW_SCALING) / tan(camera.horiz_fov / 2);
	dist_vec = vector_scale_direction(distance, camera.view_dir);
	centre = point_point_vector(cam_point, dist_vec);
	return (centre);
}

//Function works out the screen-up direction.
t_direction	screen_up(t_camera camera)
{
	t_direction	screen_up;
	t_direction	horiz;
	t_point		origin;
	t_point		p_horiz;

	origin = point_coords(0, 0, 0);
	if (camera.view_dir.x_comp == 1 || camera.view_dir.x_comp == -1)
		p_horiz = point_coords(0, 1, 0);
	else
		p_horiz = point_coords(1, 0, 0);
	horiz = direction_two_points(origin, p_horiz);
	screen_up = direction_cross_up(camera.view_dir, horiz);
	return (screen_up);
}
