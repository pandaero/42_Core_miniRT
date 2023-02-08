/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 16:52:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function fills an intersection for a pixel.
static void	intersection_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_camera	*cam;
	t_screen	*scr;
	t_direction	*dir;
	t_ray		*ray;
	t_objlist	*list;

	list = program->objlist;
	cam = camera_program(program);
	scr = screen_program(program);
	dir = direction_two_points(cam->location, scr->pixels[ii[0]][ii[1]]->point);
	ray = ray_start_dir(scr->pixels[ii[0]][ii[1]]->point, dir);
	scr->pixels[ii[0]][ii[1]]->intrsct = intersection_ray_obj(ray, obj);
	intersection_colour(list, scr->pixels[ii[0]][ii[1]]->intrsct);
	free_direction(dir);
	free_ray(ray);
}

//Function performs a render through the screen for the input object.
void	render_intersection_pass(t_program *program, t_obj *object)
{
	int	ii[2];

	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			intersection_pass(program, object, ii);
			ii[1]++;
		}
		ii[0]++;
	}
	object->unrendered = 0;
	program->objlist->num_unrendered--;
}
