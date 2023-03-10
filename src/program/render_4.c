/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:24:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/21 18:28:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function assigns a secondary intersection to a pixel.
static void	pixel_sec_itsct(t_intersect *itsct, t_pixel *pixel)
{
	pixel->sec_itsct = sec_intersect_create();
	pixel->sec_itsct->state = INTERSECTED;
	pixel->sec_itsct->distance = itsct->distance;
	pixel->sec_itsct->parent = pixel->itsct;
	pixel->sec_itsct->shadow = colour_full(SHADOW);
}

//Function works out the second intersection parameters in the main loop.
static void	sec_itsct_pass_loop(t_program *program, t_pixel *pixel, \
									t_sec_itsct_pass *stct)
{
	t_pixel	*lastpix;

	lastpix = screen_program(program)->pixels[WIN_HEIGHT - 1][WIN_WIDTH - 1];
	stct->temp = intersection_ray_obj(stct->ray, stct->obj);
	if (stct->temp->state == INTERSECTED && stct->temp->distance \
			<= distance_two_points(pixel->itsct->point, \
			diffuse_objlist(program->objlist)->position))
		pixel_sec_itsct(stct->temp, pixel);
	free_intersection(stct->temp);
	stct->sec_unren--;
	if (pixel == lastpix)
		program->objlist->num_sec_unren--;
	stct->obj = stct->obj->next;
}

//Function calculates a secondary intersection for a pixel.
void	secondary_intersection_pass(t_program *program, t_pixel *pixel)
{
	t_sec_itsct_pass	stct;

	stct.sec_unren = program->objlist->num_sec_unren;
	stct.obj = object_first_list(program->objlist);
	stct.dir = direction_two_points(pixel->itsct->point, \
				diffuse_objlist(program->objlist)->position);
	stct.ray = ray_start_dir(pixel->itsct->point, stct.dir);
	while (stct.obj && stct.sec_unren > 0)
	{
		if (stct.obj == pixel->itsct->object)
		{
			stct.obj = stct.obj->next;
			stct.sec_unren--;
			continue ;
		}
		sec_itsct_pass_loop(program, pixel, &stct);
	}
	free_direction(stct.dir);
	free_ray(stct.ray);
}
