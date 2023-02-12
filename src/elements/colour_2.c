/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:48:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 17:00:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function works out the lighting of an intersection based on objects.
void	colour_lighting(t_objlist *objlist, t_intersect *intersect)
{
	t_colour	*objcolour;
	t_ambient	*ambient;
	t_diffuse	*diffuse;

	ambient = ambient_objlist(objlist);
	diffuse = diffuse_objlist(objlist);
	objcolour = colour_object(intersect->object);
	intersect->colour = colour_ambient(objcolour->full, ambient);
	if (objlist_count_diffuse(objlist) == 1)
		colour_diffuse_inverse_square(diffuse, intersect);
}

//Function works out the ambient light colour from an object list.
t_colour	*colour_ambient_list(t_objlist *objlist)
{
	t_ambient	*ambient;
	t_colour	*colour;

	ambient = ambient_objlist(objlist);
	colour = colour_ambient(BLACK, ambient);
	return (colour);
}

//Function works out the lighting effect of a diffuse light on a point. Linear.
void	colour_diffuse_linear(t_colour *colour, t_diffuse *difflight, \
								t_point *point)
{
	double		distance;

	distance = distance_two_points(difflight->position, point);
	colour->full = (unsigned int)(difflight->ratio * WHITE * \
									LIGHTING_FACTOR / distance);
	if (colour->full > WHITE)
		colour->full = WHITE;
}

//Function works out the lighting effect of a diffuse light on a point. Inv. Sq.
void	colour_diffuse_inverse_square(t_diffuse *difflight, \
										t_intersect *intrsct)
{
	double	distance;
	double	ratio;

	distance = distance_two_points(difflight->position, intrsct->point);
	ratio = 1 / pow(distance, 2);
	intrsct->colour->trans = 0;
	intrsct->colour->red += LIGHTING_FACTOR * 255 * ratio * difflight->ratio;
	if (intrsct->colour->red > 255)
		intrsct->colour->red = 255;
	intrsct->colour->green += intrsct->colour->green + LIGHTING_FACTOR * 255 * \
								ratio * difflight->ratio;
	if (intrsct->colour->green > 255)
		intrsct->colour->green = 255;
	intrsct->colour->blue += intrsct->colour->blue + LIGHTING_FACTOR * 255 * \
								ratio * difflight->ratio;
	if (intrsct->colour->blue > 255)
		intrsct->colour->blue = 255;
	intrsct->colour->full = intrsct->colour->trans + intrsct->colour->red * \
							0x10000 + intrsct->colour->green * 0x100 + \
							intrsct->colour->blue;
	if (intrsct->colour->full > WHITE)
		intrsct->colour->full = WHITE;
}
