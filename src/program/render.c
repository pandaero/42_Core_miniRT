/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 13:17:59 by pandalaf         ###   ########.fr       */
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

//Function performs rendering based on a scene with objects.
void	render_object_scene(t_program *program)
{
	int			ii[2];
	t_pixel		*pixel;

	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			pixel = screen_program(program)->pixels[ii[0]][ii[1]];
			render_pixel(program, pixel);
			ii[1]++;
		}
		ii[0]++;
	}
}

//Function creates a screen from camera, then loops rendering through objlist.
void	render_screen(t_program *program)
{
	t_screen	*screen;

	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, camera_program(program));
	list_add_object(program->objlist, object_screen(screen));
	if (program->objlist->num_unren == 0)
		render_empty_scene(program);
	else
		render_object_scene(program);
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
