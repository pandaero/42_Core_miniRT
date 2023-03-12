/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:21:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/31 14:28:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function works out vectors and points required to compute screen pixels.
void	define_screen_pts_vecs(int width, int height, t_camera *camera, \
								t_screen *screen)
{
    screen->pts->centre = screen_centre(width, camera);
    screen->vecs->normal = direction_copy(camera->view_dir);
    screen->vecs->screen_up = screen_up(camera);
    screen->vecs->screen_right = direction_cross(screen->vecs->normal, screen->vecs->screen_up);
    screen->vecs->vec_up = vector_scale_direction(VIEW_SCALING, screen->vecs->screen_up);
    screen->vecs->vec_down = vector_scale_direction(-1 * VIEW_SCALING, screen->vecs->screen_up);
    screen->vecs->vec_left = vector_scale_direction(-1 * VIEW_SCALING, \
											screen->vecs->screen_right);
    screen->vecs->vec_right = vector_scale_direction(VIEW_SCALING, screen->vecs->screen_right);
    screen->vecs->vec_corner_up = vector_scale(height / 2, screen->vecs->vec_up);
    screen->vecs->vec_corner_left = vector_scale(width / 2, screen->vecs->vec_left);
    screen->pts->top_centre = point_point_vector(screen->pts->centre, screen->vecs->vec_corner_up);
    screen->pts->tl_corner = point_point_vector(screen->pts->top_centre, screen->vecs->vec_corner_left);
    screen->vecs->vec_screen_rd = vector_add(screen->vecs->vec_right, screen->vecs->vec_down);
    screen->vecs->vec_screen_rd_0th = vector_scale(0.5, screen->vecs->vec_screen_rd);
    screen->pts->first_px = point_point_vector(screen->pts->tl_corner, screen->vecs->vec_screen_rd_0th);
}

//Function allocates memory for a 2D array of pixels.
static t_pixel	***pixel_centres_create(int height)
{
	t_pixel	***new;

	new = (t_pixel ***)malloc((height) * sizeof(t_pixel **));
	if (!new)
		return (NULL);
	return (new);
}

//Function is a helper for the general case of screen pixel centre determining.
static t_point	*full_centre(int i, int j, t_screen *screen, \
								t_screen_centre strct)
{
	strct.scr_d_px = vector_scale(i, screen->vecs->vec_down);
	strct.scr_r_px = vector_scale(j, screen->vecs->vec_right);
	strct.scr_rd_px = vector_add(strct.scr_r_px, strct.scr_d_px);
	strct.centre = point_point_vector(screen->pts->first_px, \
										strct.scr_rd_px);
	free_vector(strct.scr_r_px);
	free_vector(strct.scr_d_px);
	free_vector(strct.scr_rd_px);
	return (strct.centre);
}

//Function works out the coordinates of each pixel centre.
static t_pixel	*screen_px_centre(int i, int j, t_screen *screen)
{
	t_screen_centre	st;

	if (i == 0 && j == 0)
		st.centre = point_copy(screen->pts->first_px);
	else if (i == 0)
	{
		st.scr_r_px = vector_scale(j, screen->vecs->vec_right);
		st.centre = point_point_vector(screen->pts->first_px, st.scr_r_px);
		free_vector(st.scr_r_px);
	}
	else if (j == 0)
	{
		st.scr_d_px = vector_scale(i, screen->vecs->vec_down);
		st.centre = point_point_vector(screen->pts->first_px, st.scr_d_px);
		free_vector(st.scr_d_px);
	}
	else
	{
		st.centre = NULL;
		st.centre = full_centre(i, j, screen, st);
	}
	st.pix = pixel_point(st.centre);
	free_point(st.centre);
	return (st.pix);
}

//Function works out the centres of the pixels in a screen.
void	screen_pixel_centres(int width, int height, t_camera *camera, \
								t_screen *screen)
{
	t_pixel	***px;
	int		ii[2];

	define_screen_pts_vecs(width, height, camera, screen);
	ii[0] = 0;
	px = pixel_centres_create(height);
	while (ii[0] < height)
	{
		ii[1] = 0;
		px[ii[0]] = (t_pixel **)malloc((width) * sizeof(t_pixel *));
		while (ii[1] < width)
		{
			px[ii[0]][ii[1]] = screen_px_centre(ii[0], ii[1], screen);
			ii[1]++;
		}
		ii[0]++;
	}
	screen->pixels = px;
}
