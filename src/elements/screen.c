/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:26:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 10:35:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function creates a new screen element from another.
t_screen	screen_copy(t_screen other)
{
	t_screen	new;

	new.width = other.width;
	new.height = other.height;
	new.pt[CTR] = point_copy(other.pt[CTR]);
	new.pt[FSTPX] = point_copy(other.pt[FSTPX]);
	new.pt[TLCNR] = point_copy(other.pt[TLCNR]);
	new.pt[TCTR] = point_copy(other.pt[TCTR]);
	new.dir[NML] = direction_copy(other.dir[NML]);
	new.dir[SCRUP] = direction_copy(other.dir[SCRUP]);
	new.dir[SCRRGT] = direction_copy(other.dir[SCRRGT]);
	new.vec[UP] = vector_copy(other.vec[UP]);
	new.vec[DN] = vector_copy(other.vec[DN]);
	new.vec[LFT] = vector_copy(other.vec[LFT]);
	new.vec[RGT] = vector_copy(other.vec[RGT]);
	new.vec[CNRUP] = vector_copy(other.vec[CNRUP]);
	new.vec[CNRLFT] = vector_copy(other.vec[CNRLFT]);
	new.vec[SCRRD]= vector_copy(other.vec[SCRRD]);
	new.vec[SCRRD0]= vector_copy(other.vec[SCRRD0]);
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
