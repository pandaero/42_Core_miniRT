/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/12 14:39:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function fills an intersection for a pixel.
static void	intersection_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_inter_pass	strct;

	strct.list = program->objlist;
	strct.cam = camera_program(program);
	strct.scr = screen_program(program);
	strct.dir = direction_two_points(strct.cam->location, \
									strct.scr->pixels[ii[0]][ii[1]]->point);
	strct.ray = ray_start_dir(strct.scr->pixels[ii[0]][ii[1]]->point, \
																strct.dir);
	strct.temp = intersection_ray_obj(strct.ray, obj);
	if (object_first_list(program->objlist) == obj)
		strct.scr->pixels[ii[0]][ii[1]]->intrsct = \
			intersection_ray_obj(strct.ray, obj);
	if (strct.temp->distance < \
			strct.scr->pixels[ii[0]][ii[1]]->intrsct->distance)
	{
		ft_printf("comparing|");
		free_intersection(strct.scr->pixels[ii[0]][ii[1]]->intrsct);
		strct.scr->pixels[ii[0]][ii[1]]->intrsct = temp;
	}
	else
		free_intersection(temp);
	intersection_colour(strct.list, strct.scr->pixels[ii[0]][ii[1]]->intrsct);
	free_direction(strct.dir);
	free_ray(strct.ray);
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
