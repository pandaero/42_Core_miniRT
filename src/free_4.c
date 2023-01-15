/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:30:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/14 20:20:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function frees screen vectors.
static void	free_scr_vec(t_scr_vec *vec)
{
	free_direction(vec->normal);
	free_direction(vec->screen_up);
	free_direction(vec->screen_right);
	free_vector(vec->vec_up);
	free_vector(vec->vec_down);
	free_vector(vec->vec_left);
	free_vector(vec->vec_right);
	free_vector(vec->vec_corner_up);
	free_vector(vec->vec_corner_left);
	free_vector(vec->vec_screen_rd);
	free_vector(vec->vec_screen_rd_0th);
	free(vec);
}

//Function frees screen points.
static void	free_scr_pts(t_scr_pts *pts, t_screen *screen)
{
	int	i;
	int	j;

	free_point(pts->centre);
	free_point(pts->top_centre);
	free_point(pts->tl_corner);
	free_point(pts->first_px);
	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			free_point(pts->px_coords[i][j]);
			j++;
		}
		free(pts->px_coords[i]);
		i++;
	}
	free(pts->px_coords);
	free(pts);
}

//Function frees a screen.
void	free_screen(t_screen *screen)
{
	free_scr_vec(screen->vecs);
	free_scr_pts(screen->pts, screen);
	free(screen);
}