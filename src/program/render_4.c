/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:24:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 00:07:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>

// //Function assigns a secondary intersection to a pixel.
// static void	pixel_sec_itsct(t_intersect *itsct, t_pixel *pixel)
// {
// 	pixel->sec_itsct.state = INTERSECTED;
// 	pixel->sec_itsct.distance = itsct->distance;
// 	pixel->sec_itsct.parent = pixel->itsct;
// 	pixel->sec_itsct.shadow = colour_full(SHADOW);
// }

// //Function works out the second intersection parameters in the main loop.
// static void	sec_itsct_pass_loop(t_program *program, t_pixel *pixel, \
// 														t_sec_itsct_pass *stct)
// {
// 	t_pixel	*lastpix;

// 	lastpix = screen_program(program).pixels[WIN_HEIGHT - 1][WIN_WIDTH - 1];
// 	stct->temp = intersection_ray_obj(stct->ray, stct->obj);
// 	if (stct->temp.state != MISSED && stct->temp.distance <= distance_two_points(pixel->itsct.point, diffuse_objlist(program->objlist).position))
// 	{
// 		pixel->sec_itsct.state = INTERSECTED;
// 		pixel->sec_itsct.distance = stct->temp.distance;
// 		pixel->sec_itsct.parent = pixel->itsct;
// 		pixel->sec_itsct.shadow = colour_full(SHADOW);
// 	}	
// 	stct->sec_unren--;
// 	if (pixel == lastpix)
// 		program->objlist->num_sec_unren--;
// 	stct->obj = stct->obj->next;
// }


// //Function calculates a secondary intersection from the scene with an object.
// t_sec_itsct	sec_itsct_calc(t_objlist *objlist, t_pixel *pix, t_obj *obj)
// {
// 	t_ray		sec_ray;
// 	t_diffuse	light;
// 	t_intersect	temp_intrsct;
// 	t_sec_itsct	sec_itsct;
// 	double		tolight;

// 	light = diffuse_objlist(objlist);
// 	sec_ray = ray_two_points(pix->itsct.point, light.position);
// 	tolight = distance_two_points(pix->itsct.point, light.position);
// 	temp_intrsct = intersection_ray_obj(sec_ray, obj);
// 	if (temp_intrsct.distance <= tolight && temp_intrsct.distance > 0)
// 	{
// 		sec_itsct.state = INTERSECTED;
// 		sec_itsct.distance = temp_intrsct.distance;
// 		sec_itsct.parent = pix->itsct;
// 		sec_itsct.shadow = colour_full(SHADOW);
// 	}
// 	sec_itsct.state = MISSED;
// 	sec_itsct.distance = DBL_MAX;
// 	return (sec_itsct);
// }

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
		if (stct.obj == pixel->itsct.object)
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
