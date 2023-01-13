/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:26:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 03:02:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Function creates and initialises a screen.
t_screen	*screen_create(void)
{
	t_screen	*new;

	new = (t_screen *)malloc(sizeof(t_screen));
	new->width = 0;
	new->height = 0;
	new->centre = NULL;
	new->normal = NULL;
	new->pixel_centres = NULL;
	return (new);
}

//Function works out the centre of the screen based on the camera properties.
t_point	*screen_centre(double width, t_camera *camera)
{
	t_point	*centre;
	double	distance;

	centre = point_create();
	distance = 2 * width / tan(camera->horiz_fov / 2);
	centre->x_co = camera->location->x_co + distance * camera->view_dir->x_comp;
	centre->y_co = camera->location->y_co + distance * camera->view_dir->y_comp;
	centre->z_co = camera->location->z_co + distance * camera->view_dir->z_comp;
	return (centre);
}

//Function works out the screen-up direction.
t_direction	*screen_up(t_camera *camera)
{
	t_direction	*screen_up;
	t_direction *horiz;
	t_point		*origin;
	t_point		*p_horiz;

	origin = point_coords(0, 0, 0);
	p_horiz = point_coords(1, 0, 0);
	horiz = direction_two_points(origin, p_horiz);
	screen_up = direction_cross_up(camera->view_dir, horiz);
	free_point(origin);
	free_point(p_horiz);
	free_direction(horiz);
	return (screen_up);
}

/*
//Function works out the centres of the pixels in a screen.
t_point	**screen_pixel_centres(int width, int height,
								t_point *centre, t_direction *norm)
{
	t_direction	*screen_up;
	t_point	**centres;
	t_point	corner;

	screen_up = direction_cross();
	corner.x_co = centre->x_co - 
	corner.y_co = 
	corner.z_co = 

}
*/

/*
//Function defines a screen based on a camera element.
t_screen	*screen_camera(t_camera *camera)
{
	t_screen	*new;

	new = screen_create();
	new->width = WIN_WIDTH;
	new->height = WIN_HEIGHT;
	new->normal = camera->view_dir;
	new->centre = screen_centre(camera);
	new->pixel_centres = screen_pixel_centres(new->width, new->height, camera);
}
*/
