/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 04:19:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function performs the operations required to render the program window/screen.
void	render_screen(t_program *program)
{
	t_screen	*screen;
	
	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, cam);
	list_add_object(program->objlist->first, object_screen(screen));
	while (program->objlist->num_unrendered > 0)
	{
		obj = object_unrendered_list(program->objlist);
		render_intersection_pass(program, obj);
	}
}

//Function performs a render through the screen for the input object.
void	render_intersection_pass(t_program *program, t_obj *obj)
{
	t_ray		*ray;
	int			i;
	int			j;

	i = 0;
	while(i < WIN_HEIGHT)
	{
		j = 0;
		while(j < WIN_WIDTH)
		{
			dir = direction_two_points(camera_program(program)->location, \
								screen_program(program)->pixels[i][j]->point);
			ray = ray_start_dir(screen_program(program)->pixels[i][j]->point, \
								dir);
			screen_program(program)->pixels[i][j]->intrsct = \
				intersection_ray_obj(program, ray, obj);
			free_direction(dir);
			free_ray(ray);
			j++;
		}
		i++;
	}
	obj->unrendered = 0;
	program->objlist->num_unrendered--;
}

//Function assigns each pixel its colour.
void	window_draw(t_program *program)
{
	int	i;
	int	j

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			quick_put_pixel(program->mlx->imdt, j, i, \
					screen_program(program)->pixels[i][j]->intrsct->colour);
			j++;
		}
		i++;
	}
}
