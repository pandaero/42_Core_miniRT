/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 04:15:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function assigns colour to an intersection.
void	intersection_colour(t_objlist *list, t_intersect *intersect)
{
	if (intersect->state == 0)
	{
		intersect->colour = colour_ambient_list(list);
		return ;
	}
	colour_lighting(list, intersect);
}

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
		strct.scr->pixels[ii[0]][ii[1]]->itsct = \
			intersection_ray_obj(strct.ray, obj);
	if (strct.temp->distance < \
			strct.scr->pixels[ii[0]][ii[1]]->itsct->distance)
	{
		free_intersection(strct.scr->pixels[ii[0]][ii[1]]->itsct);
		strct.scr->pixels[ii[0]][ii[1]]->itsct = strct.temp;
	}
	else
		free_intersection(strct.temp);
	strct.scr->pixels[ii[0]][ii[1]]->itsct->object = obj;
	intersection_colour(strct.list, strct.scr->pixels[ii[0]][ii[1]]->itsct);
	free_direction(strct.dir);
	free_ray(strct.ray);
}

//Function performs a secondary intersection calculation for a pixel.
void	sec_itsct_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_screen	*screen;
	t_pixel		*pix;
	t_obj		*object;

	screen = screen_program(program);
	object = object_first_list(program->objlist);
	pix = screen->pixels[ii[0]][ii[1]];
	if (pix->itsct->state == INTERSECTED)
	{
		while (object->next)
		{
			pix->sec_itsct = sec_itsct_calc(program->objlist, pix, obj);
			object = object->next;
		}
	}
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
			sec_itsct_pass(program, object, ii);
			ii[1]++;
		}
		ii[0]++;
	}
	object->unrendered = 0;
	program->objlist->num_unrendered--;
}
