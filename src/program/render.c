/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 02:30:04 by pandalaf         ###   ########.fr       */
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

//Function renders a single pixel fully, regarding all possible intersections.
void	render_pixel(t_program *program, t_pixel *pixel)
{
	primary_intersection_pass(program, pixel);
	if (objlist_count_diffuse(program->objlist) && pixel->itsct.state == INTERSECTED)
		secondary_intersection_pass(program, pixel);
	if (pixel->sec_itsct.state == INTERSECTED)
	{
		pixel->colour = colour_subtract(pixel->itsct.colour, pixel->sec_itsct.shadow);
		// pixel->colour = colour_add(colour_ambient_list(program->objlist), pixel->colour);
	}
	else
	{
		if (pixel->itsct.state == INTERSECTED)
			pixel->colour = colour_copy(pixel->itsct.colour);
		else
			pixel->colour = colour_ambient_list(program->objlist);
	}
}

//Function performs rendering based on a scene with objects.
void	render_object_scene(t_program *program)
{
	int			ii[2];
	int			perc[4];
	t_pixel		*pixel;

	perc[3] = WIN_HEIGHT * WIN_WIDTH;
	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			perc[2] = (ii[0] * WIN_WIDTH + ii[1]);
			pixel = screen_program(program)->pixels[ii[0]][ii[1]];
			render_pixel(program, pixel);
			perc[0] = round(100 * perc[2] / perc[3]);
			if (STATUS == 2)
				ft_printf("Rendering... %i%%\r", perc[0]);
			ii[1]++;
		}
		if (STATUS == 1)
			ft_printf("Rendering... %i%%\r", perc[0]);
		ii[0]++;
	}
}

//Function creates a screen from camera, then loops rendering through objlist.
void	render_screen(t_program *program)
{
	t_screen	screen;

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
			quick_put_pixel(&program->mldt->imdt, j, i, \
					scr->pixels[i][j]->colour.full);
			j++;
		}
		i++;
	}
}
