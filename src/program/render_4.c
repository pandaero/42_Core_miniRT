/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:24:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 02:01:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

//Function calculates a secondary intersection for a pixel.
void	secondary_intersection_pass(t_program *program, t_pixel *pixel)
{
	t_sec_itsct_pass	stct;

	stct.sec_unren = program->objlist->num_sec_unren;
	stct.obj = object_first_list(program->objlist);
	stct.dir = direction_two_points(pixel->itsct.point, diffuse_objlist(program->objlist).position);
	stct.ray = ray_start_dir(pixel->itsct.point, stct.dir);
	while (stct.obj && stct.sec_unren > 0)
	{
		if (stct.obj && stct.obj == pixel->itsct.object)
		{
			stct.obj = stct.obj->next;
			stct.sec_unren--;
			continue ;
		}
		stct.temp = intersection_ray_obj(stct.ray, stct.obj);
		if (stct.temp.state == INTERSECTED && stct.temp.distance <= distance_two_points(pixel->itsct.point, diffuse_objlist(program->objlist).position))
		{
			pixel->sec_itsct.state = INTERSECTED;
			pixel->sec_itsct.distance = stct.temp.distance;
			pixel->sec_itsct.shadow = colour_full(SHADOW);
		}
		else
		{
			pixel->sec_itsct.state = MISSED;
			pixel->sec_itsct.distance = -DBL_MAX;
		}
		stct.sec_unren--;
		t_pixel * lastpix = screen_program(program)->pixels[WIN_HEIGHT - 1][WIN_WIDTH - 1];
		if (pixel == lastpix)
			program->objlist->num_sec_unren--;
		stct.obj = stct.obj->next;
	}
}
