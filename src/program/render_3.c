/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:19:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/12 03:24:18 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function performs steps that happen only first time for intersection.
static void	first_itsct_loop(t_program *program, t_pixel *pixel, \
								t_itsct_pass *stct)
{
	pixel->itsct = intersection_ray_obj(stct->ray, stct->obj);
	if (pixel->itsct->state == MISSED)
		pixel->itsct->colour = colour_ambient_list(program->objlist);
	else
		pixel->itsct->colour = \
		colour_ambient(colour_object(pixel->itsct->object), \
			ambient_objlist(program->objlist));
	stct->unren--;
	stct->obj = stct->obj->next;
	free_intersection(stct->temp);
}

//Function performs the steps that definitely happen when calculating intersect.
static void	later_itsct_loop(t_pixel *pixel, t_itsct_pass *stct)
{
	if (stct->temp->distance < pixel->itsct->distance && \
			stct->temp->distance > 0)
	{
		free_intersection(pixel->itsct);
		pixel->itsct = stct->temp;
	}
	else
		free_intersection(stct->temp);
	stct->unren--;
	stct->obj = stct->obj->next;
}

//Function applies colour to an intersection during a pass.
static void	itsct_pass_colouring(t_program *program, \
									t_intersect *itsct, int n)
{
	if (itsct->colour)
		free_colour(itsct->colour);
	if (n == 1)
	{
		if (itsct->state == MISSED)
			itsct->colour = colour_ambient_list(program->objlist);
		else
			itsct->colour = colour_ambient(colour_object(itsct->object), \
										ambient_objlist(program->objlist));
	}
	if (n == 2)
	{
		if (itsct->state == MISSED)
			itsct->colour = colour_ambient_list(program->objlist);
		else
			colour_itsct_lighting(program->objlist, itsct);
	}
}

//Function calculates a primary intersection for a pixel.
void	primary_intersection_pass(t_program *program, t_pixel *pixel)
{
	t_itsct_pass	stct;

	stct.unren = program->objlist->num_unren;
	stct.obj = object_first_list(program->objlist);
	stct.dir = direction_two_points(camera_program(program)->location, \
										pixel->point);
	stct.ray = ray_start_dir(pixel->point, stct.dir);
	while (stct.obj && stct.unren > 0)
	{
		stct.temp = intersection_ray_obj(stct.ray, stct.obj);
		itsct_pass_colouring(program, stct.temp, 1);
		if (stct.obj == object_first_list(program->objlist))
		{
			first_itsct_loop(program, pixel, &stct);
			continue ;
		}
		later_itsct_loop(pixel, &stct);
	}
	free_ray(stct.ray);
	free_direction(stct.dir);
	itsct_pass_colouring(program, pixel->itsct, 2);
}
