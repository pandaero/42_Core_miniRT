/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/19 16:12:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function fills the screen with ambient light.
void	render_empty_scene(t_program *program)
{
	int			ii[2];
	t_screen	*scr;
	t_pixel		*pixel;

	scr = screen_program(program);
	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			pixel = scr->pixels[ii[0]][ii[1]];
			pixel->colour = colour_ambient_list(program->objlist);
			ii[1]++;
		}
		ii[0]++;
	}
}

//Function calculates the resulting colour for each pixel.
void	pixel_colour_calculation(t_program *program)
{
	int		i;
	int		j;
	t_pixel	*pix;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			pix = screen_program(program)->pixels[i][j];
			if (pix->sec_itsct)
			{
				if (pix->sec_itsct->state == INTERSECTED)
				 	pix->colour = colour_subtract(pix->itsct->colour, pix->sec_itsct->shadow);
				else
					pix->colour = colour_copy(pix->itsct->colour);
			}
			else if (pix->itsct->state == INTERSECTED)
				pix->colour = colour_copy(pix->itsct->colour);
			else
				pix->colour = colour_ambient_list(program->objlist);
			j++;
		}
		i++;
	}
}

//Function creates a screen from camera, then loops rendering through objlist.
void	render_screen(t_program *program)
{
	t_screen	*screen;
	t_obj		*obj;

	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, camera_program(program));
	list_add_object(program->objlist, object_screen(screen));
	if (program->objlist->num_unrendered == 0)
	{
		render_empty_scene(program);
		return ;
	}
	while (program->objlist->num_unrendered > 0)
	{
		obj = object_unrendered_list(program->objlist);
		render_intersection_pass(program, obj);
	}
	pixel_colour_calculation(program);
}

//Function assigns each window pixel its colour.
void	window_draw(t_program *program)
{
	int			i;
	int			j;
	t_screen	*scr;

	scr = screen_program(program);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			quick_put_pixel(program->mldt->imdt, j, i, \
					scr->pixels[i][j]->colour->full);
			j++;
		}
		i++;
	}
}
