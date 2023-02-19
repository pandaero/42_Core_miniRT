/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/19 21:38:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function assigns colour to an intersection.
void	intersection_colour(t_objlist *list, t_intersect *intersect)
{
	if (intersect->state == MISSED)
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
	t_pixel			*pix;

	strct.list = program->objlist;
	strct.cam = camera_program(program);
	strct.scr = screen_program(program);
	strct.dir = direction_two_points(strct.cam->location, \
									strct.scr->pixels[ii[0]][ii[1]]->point);
	strct.ray = ray_start_dir(strct.scr->pixels[ii[0]][ii[1]]->point, \
																strct.dir);
	strct.temp = intersection_ray_obj(strct.ray, obj);
	pix = strct.scr->pixels[ii[0]][ii[1]];
	if (object_first_list(program->objlist) == obj)
	{
		pix->itsct = intersection_ray_obj(strct.ray, obj);
		intersection_colour(strct.list, pix->itsct);
	}
	if (strct.temp->distance < pix->itsct->distance && strct.temp->distance > 0)
	{
		free_intersection(pix->itsct);
		pix->itsct = strct.temp;
		intersection_colour(strct.list, pix->itsct);
	}
	else
		free_intersection(strct.temp);
	pix->itsct->object = obj;
	free_direction(strct.dir);
	free_ray(strct.ray);
}

//Function performs a secondary intersection calculation for a pixel.
void	sec_itsct_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_screen	*screen;
	t_pixel		*pix;
	t_obj		*object;
	t_diffuse	*light;
	double		tolight;
	t_intersect	*temp_intrsct;

	screen = screen_program(program);
	object = object_first_list(program->objlist);
	light = diffuse_objlist(program->objlist);
	pix = screen->pixels[ii[0]][ii[1]];
	if (pix->itsct->state == INTERSECTED)
	{
		tolight = distance_two_points(pix->itsct->point, light->position);
		while (object->next && object != obj)
		{
			t_ray *	ray_sec = ray_two_points(pix->itsct->point, light->position);
			temp_intrsct = intersection_ray_obj(ray_sec, object);
			if (temp_intrsct->distance <= tolight && temp_intrsct->distance > 0 && temp_intrsct->object != obj)
			{
				pix->sec_itsct = sec_intersect_create();
				pix->sec_itsct->state = INTERSECTED;
				pix->sec_itsct->distance = temp_intrsct->distance;
				pix->sec_itsct->parent = pix->itsct;
				pix->sec_itsct->shadow = colour_full(SHADOW);
			}
			free_intersection(temp_intrsct);
			free_ray(ray_sec);
			// pix->sec_itsct = sec_itsct_calc(program->objlist, pix, object);
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
			if (diffuse_objlist(program->objlist))
				sec_itsct_pass(program, object, ii);
			ii[1]++;
		}
		ii[0]++;
	}
	object->unrendered = 0;
	program->objlist->num_unrendered--;
}
