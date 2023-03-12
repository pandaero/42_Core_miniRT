/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/12 22:46:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

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
	int			perc[2];
	int			num;
	int			tot;
	t_pixel		*pixel;

	tot = WIN_HEIGHT * WIN_WIDTH;
	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			num = (ii[0] * WIN_WIDTH + ii[1]);
			pixel = screen_program(program)->pixels[ii[0]][ii[1]];
			render_pixel(program, pixel);
			perc[0] = round(num / tot);
			perc[1] = round(10 * num / tot);
			if (STATUS == 2)
				ft_printf("Rendering... %i.%i%%\r", perc[0], perc[1]);
			ii[1]++;
		}
		if (STATUS == 1)
			ft_printf("Rendering... %i.%i%%\r", perc[0], perc[1]);
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
