/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:21:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 10:44:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function works out vectors and points required to compute screen pixels.
void	define_screen_pts_vecs(int width, int height, t_camera camera, \
								t_screen *screen)
{
	screen->pt[CTR] = screen_centre(width, camera);
	screen->dir[NML] = direction_copy(camera.view_dir);
	screen->dir[SCRUP] = screen_up(camera);
	screen->dir[SCRRGT] = direction_cross(screen->dir[NML], screen->dir[SCRUP]);
	screen->vec[UP] = vector_scale_direction(VIEW_SCALING, screen->dir[SCRUP]);
	screen->vec[DN] = vector_scale_direction(-1 * VIEW_SCALING, \
															screen->dir[SCRUP]);
	screen->vec[LFT] = vector_scale_direction(-1 * VIEW_SCALING, \
														screen->dir[SCRRGT]);
	screen->vec[RGT] = vector_scale_direction(VIEW_SCALING, \
														screen->dir[SCRRGT]);
	screen->vec[CNRUP] = vector_scale(height / 2, screen->vec[UP]);
	screen->vec[CNRLFT] = vector_scale(width / 2, screen->vec[LFT]);
	screen->pt[TCTR] = point_point_vector(screen->pt[CTR], \
															screen->vec[CNRUP]);
	screen->pt[TLCNR] = point_point_vector(screen->pt[TCTR], \
														screen->vec[CNRLFT]);
	screen->vec[SCRRD] = vector_add(screen->vec[RGT], screen->vec[DN]);
	screen->vec[SCRRD0] = vector_scale(0.5, screen->vec[SCRRD]);
	screen->pt[FSTPX] = point_point_vector(screen->pt[TLCNR], \
														screen->vec[SCRRD0]);
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
static t_point	full_centre(int i, int j, t_screen *screen, \
								t_screen_centre *strct)
{
	strct->scr_d_px = vector_scale(i, screen->vec[DN]);
	strct->scr_r_px = vector_scale(j, screen->vec[RGT]);
	strct->scr_rd_px = vector_add(strct->scr_r_px, strct->scr_d_px);
	strct->centre = point_point_vector(screen->pt[FSTPX], \
										strct->scr_rd_px);
	return (strct->centre);
}

//Function works out the coordinates of each pixel centre.
static t_pixel	*screen_px_centre(int i, int j, t_screen *screen)
{
	t_screen_centre	st;

	if (i == 0 && j == 0)
		st.centre = point_copy(screen->pt[FSTPX]);
	else if (i == 0)
	{
		st.scr_r_px = vector_scale(j, screen->vec[RGT]);
		st.centre = point_point_vector(screen->pt[FSTPX], st.scr_r_px);
	}
	else if (j == 0)
	{
		st.scr_d_px = vector_scale(i, screen->vec[DN]);
		st.centre = point_point_vector(screen->pt[FSTPX], st.scr_d_px);
	}
	else
		st.centre = full_centre(i, j, screen, &st);
	st.pix = pixel_point(st.centre);
	return (st.pix);
}

//Function works out the centres of the pixels in a screen.
void	screen_pixel_centres(int width, int height, t_camera camera, \
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
