/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:24:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/16 09:02:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

static int	sec_int_loop(t_sec_itsct_pass *stct, t_pixel *pixel, \
															t_program *program)
{
	stct->temp = intersection_ray_obj(stct->ray, stct->obj);
	if (stct->temp.state == INTERSECTED && stct->temp.distance <= \
		distance_two_points(pixel->itsct.point, \
									diffuse_objlist(program->objlist).position))
	{
		pixel->sec_itsct.state = INTERSECTED;
		pixel->sec_itsct.distance = stct->temp.distance;
		pixel->sec_itsct.shadow = colour_full(SHADOW);
		if (pixel == stct->lastpix)
			program->objlist->num_sec_unren--;
		return (1);
	}
	else
	{
		pixel->sec_itsct.state = MISSED;
		pixel->sec_itsct.distance = DBL_MAX;
	}
	stct->sec_unren--;
	if (pixel == stct->lastpix)
		program->objlist->num_sec_unren--;
	stct->obj = stct->obj->next;
	return (0);
}

static int	self_sec_itsct_loop(t_program *program, t_pixel *pixel, \
														t_sec_itsct_pass *stct)
{
	t_vector	selfvec;
	t_point		selfraypt;
	t_ray		selfray;
	t_intersect	tempy;

	selfvec = vector_scale_direction(0.1, stct->dir);
	selfraypt = point_point_vector(pixel->itsct.point, selfvec);
	selfray = ray_start_dir(selfraypt, stct->dir);
	tempy = intersection_ray_obj(selfray, stct->obj);
	if (tempy.state == INTERSECTED && tempy.distance < \
						distance_two_points(selfraypt, \
									diffuse_objlist(program->objlist).position))
	{
		pixel->sec_itsct.state = INTERSECTED;
		pixel->sec_itsct.distance = tempy.distance;
		pixel->sec_itsct.shadow = colour_full(SHADOW);
		if (pixel == stct->lastpix)
			program->objlist->num_sec_unren--;
		return (1);
	}
	stct->obj = stct->obj->next;
	stct->sec_unren--;
	return (0);
}

//Function calculates a secondary intersection for a pixel.
void	secondary_intersection_pass(t_program *program, t_pixel *pixel)
{
	t_sec_itsct_pass	stct;

	stct.lastpix = \
				screen_program(program)->pixels[WIN_HEIGHT - 1][WIN_WIDTH - 1];
	stct.sec_unren = program->objlist->num_sec_unren;
	stct.obj = object_first_list(program->objlist);
	stct.dir = direction_two_points(pixel->itsct.point, \
									diffuse_objlist(program->objlist).position);
	stct.ray = ray_start_dir(pixel->itsct.point, stct.dir);
	while (stct.obj && stct.sec_unren > 0)
	{
		if (stct.obj && stct.obj == pixel->itsct.object)
		{
			if (self_sec_itsct_loop(program, pixel, &stct))
				return ;
			continue ;
		}
		if (sec_int_loop(&stct, pixel, program))
			return ;
	}
}
