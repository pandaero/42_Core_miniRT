/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:15:17 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/19 15:51:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates an initialises a secondary intersection.
t_sec_itsct	*sec_intersect_create(void)
{
	t_sec_itsct	*new;

	new = (t_sec_itsct *)malloc(sizeof(t_sec_itsct));
	if (!new)
		return (NULL);
	new->parent = NULL;
	new->state = UNCALCULATED;
	new->distance = __DBL_MAX__;
	new->shadow = NULL;
	return (new);
}

//Function calculates a secondary intersection from the scene with an object.
t_sec_itsct	*sec_itsct_calc(t_objlist *objlist, t_pixel *pix, t_obj *obj)
{
	t_ray		*sec_ray;
	t_diffuse	*light;
	t_intersect	*temp_intrsct;
	t_sec_itsct	*sec_itsct;
	double		tolight;

	sec_itsct = NULL;
	light = diffuse_objlist(objlist);
	sec_ray = ray_two_points(pix->itsct->point, light->position);
	tolight = distance_two_points(pix->itsct->point, light->position);
	temp_intrsct = intersection_ray_obj(sec_ray, obj);
	if (temp_intrsct->distance <= tolight)
	{
		sec_itsct = sec_intersect_create();
		sec_itsct->state = INTERSECTED;
		sec_itsct->distance = temp_intrsct->distance;
		sec_itsct->parent = pix->itsct;
		sec_itsct->shadow = colour_full(SHADOW);	
	}
	free_intersection(temp_intrsct);
	free_ray(sec_ray);
	return (sec_itsct);
}
