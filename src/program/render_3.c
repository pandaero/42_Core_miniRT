/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:19:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 23:08:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <float.h>
#include <math.h>

// //Function performs steps that happen only first time for intersection.
// static void	first_itsct_loop(t_program *program, t_pixel *pixel, \
// 															t_itsct_pass *stct)
// {
// 	pixel->itsct.distance = DBL_MAX;
// 	pixel->itsct = intersection_ray_obj(stct->ray, stct->obj);
// 	if (pixel->itsct.state == MISSED)
// 		pixel->itsct.colour = colour_ambient_list(program->objlist);
// 	else
// 		pixel->itsct.colour = \
// 		colour_ambient(colour_object(pixel->itsct.object), \
// 			ambient_objlist(program->objlist));
// 	stct->unren--;
// 	stct->obj = stct->obj->next;
// }

// //Function performs the steps that definitely happen when calculating intersect.
// static void	later_itsct_loop(t_pixel *pixel, t_itsct_pass *stct)
// {
// 	stct->temp.distance = DBL_MAX;
// 	stct->temp = intersection_ray_obj(stct->ray, stct->obj);
// 	if (stct->temp.distance < pixel->itsct.distance && \
// 			stct->temp.distance > 0)
// 		pixel->itsct = stct->temp;
// 	stct->unren--;
// 	stct->obj = stct->obj->next;
// }

// //Function applies colour to an intersection during a pass.
// static void	itsct_pass_colouring(t_program *program, t_intersect *itsct)
// {
// 	if (itsct->state == MISSED)
// 		itsct->colour = colour_ambient_list(program->objlist);
// 	else
// 		colour_itsct_lighting(program->objlist, *itsct);
// }

//Function calculates a primary intersection for a pixel.
void	primary_intersection_pass(t_program *program, t_pixel *pixel)
{
	t_itsct_pass	stct;

	stct.unren = program->objlist->num_unren;
	stct.obj = object_first_list(program->objlist);
	stct.dir = direction_two_points(camera_program(program).location, pixel->point);
	stct.ray = ray_start_dir(pixel->point, stct.dir);
	while (stct.obj && stct.unren > 0)
	{
		if (stct.obj == object_first_list(program->objlist))
		{
			pixel->itsct.distance = -DBL_MAX;
			pixel->itsct = intersection_ray_obj(stct.ray, stct.obj);
			if (pixel->itsct.state == MISSED)
				pixel->itsct.colour = colour_ambient_list(program->objlist);
			else
				pixel->itsct.colour = colour_ambient(colour_object(pixel->itsct.object), ambient_objlist(program->objlist));
			stct.unren--;
			stct.obj = stct.obj->next;
			continue ;
		}
		stct.temp = intersection_ray_obj(stct.ray, stct.obj);
		if (stct.temp.distance > 0 && stct.temp.distance < pixel->itsct.distance)
			pixel->itsct = intersect_copy(stct.temp);
		stct.unren--;
		stct.obj = stct.obj->next;
	}
	if (pixel->itsct.state != INTERSECTED)
		pixel->itsct.colour = colour_ambient_list(program->objlist);
	else
	{
		t_diffuse	diff = diffuse_objlist(program->objlist);
		pixel->itsct.colour = colour_object(pixel->itsct.object);
		pixel->itsct.colour = colour_ambient(pixel->itsct.colour, ambient_objlist(program->objlist));
		t_direction	dir = direction_two_points(pixel->itsct.point, diff.position);
		double	difffac = fmax(0, direction_dot(pixel->itsct.normal, dir)) * diff.ratio * DIFF_INTENSITY;
		pixel->itsct.colour = colour_factor(difffac, pixel->itsct.colour);
		t_colour	amb = colour_amb_cont(ambient_objlist(program->objlist));
		amb = colour_factor(0.5, amb);
		amb = colour_add(pixel->itsct.colour, amb);
		pixel->itsct.colour = amb;
	}
}
