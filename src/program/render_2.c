/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:19:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 01:58:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <float.h>
#include <math.h>

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
		if (stct.obj && stct.obj == object_first_list(program->objlist))
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
		if (stct.temp.state == INTERSECTED && stct.temp.distance > 0 && stct.temp.distance < pixel->itsct.distance)
			pixel->itsct = intersect_copy(stct.temp);
		stct.unren--;
		stct.obj = stct.obj->next;
	}
	if (pixel->itsct.state != INTERSECTED)
		pixel->itsct.colour = colour_ambient_list(program->objlist);
	else
	{
		pixel->itsct.colour = colour_object(pixel->itsct.object);
		pixel->itsct.colour = colour_ambient(pixel->itsct.colour, ambient_objlist(program->objlist));
		t_direction	dir = direction_two_points(pixel->itsct.point, diffuse_objlist(program->objlist).position);
		double	difffac = fmax(0, direction_dot(pixel->itsct.normal, dir)) * diffuse_objlist(program->objlist).ratio * DIFF_INTENSITY;
		pixel->itsct.colour = colour_factor(difffac, pixel->itsct.colour);
		t_colour	amb;
		amb = colour_factor(0.5, colour_amb_cont(ambient_objlist(program->objlist)));
		amb = colour_add(pixel->itsct.colour, amb);
		pixel->itsct.colour = colour_copy(amb);
	}
}
