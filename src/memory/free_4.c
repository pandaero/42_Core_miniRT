/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:30:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:38:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
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
static void	free_scr_pts(t_scr_pts *pts)
{
	free_point(pts->centre);
	free_point(pts->top_centre);
	free_point(pts->tl_corner);
	free_point(pts->first_px);
	free(pts);
}

//Function frees a screen.
void	free_screen(t_screen *screen)
{
	int	i;
	int	j;

	free_scr_vec(screen->vecs);
	free_scr_pts(screen->pts);
	i = 0;
	while (i < screen->height)
	{
		j = 0;
		while (j < screen->width)
		{
			free_point(screen->pixels[i][j]->point);
			j++;
		}
		free(screen->pixels[i]);
		i++;
	}
	free(screen->pixels);
	free(screen);
}

//Function frees a plane.
void	free_plane(t_plane *plane)
{
	free_point(plane->point);
	free_direction(plane->normal);
	free(plane);
}

//Function frees a sphere.
void	free_sphere(t_sphere *sphere)
{
	free_point(sphere->centre);
	free(sphere);
}
