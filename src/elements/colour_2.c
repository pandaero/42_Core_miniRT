/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:48:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 03:37:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function works out the lighting of an intersection based on objects.
void	colour_lighting(t_objlist *objlist, t_intersect *intersect)
{
	t_colour	*objcolour;
	t_colour	*temp;
	t_colour	*temp2;
	t_direction	*dir;
	double		difffac;

	objcolour = colour_object(intersect->object);
	temp = colour_ambient(objcolour, ambient_objlist(objlist));
	dir = direction_two_points(intersect->point, \
								diffuse_objlist(objlist)->position);
	difffac = fmax(0, direction_dot(intersect->normal, dir)) * \
				diffuse_objlist(objlist)->ratio * DIFF_INTENSITY;
	intersect->colour = colour_factor(difffac, temp);
	free_colour(temp);
	temp = colour_amb_cont(ambient_objlist(objlist));
	temp2 = colour_factor(0.5, temp);
	free_colour(temp);
	temp = colour_add(intersect->colour, temp2);
	free_colour(temp2);
	intersect->colour = temp;
}

//Function adds ambient light to a colour.
t_colour	*colour_ambient(t_colour *col, t_ambient *ambient)
{
	t_colour	*ret;

	ret = colour_create();
	ret->trans = 0;
	ret->red = ambient->ratio * ambient->colour->red + \
				((col->full & 0xFF0000) >> 16);
	if (ret->red > 255)
		ret->red = 255;
	ret->green = ambient->ratio * ambient->colour->green + \
				((col->full & 0xFF00) >> 8);
	if (ret->green > 255)
		ret->green = 255;
	ret->blue = ambient->ratio * ambient->colour->blue + \
				((col->full & 0xFF));
	if (ret->blue > 255)
		ret->blue = 255;
	ret->full = ret->trans * 0x1000000 + ret->red * 0x10000 + \
				ret->green * 0x100 + ret->blue;
	if (ret->full > WHITE)
		ret->full = WHITE;
	return (ret);
}

//Function works out the ambient light colour from an object list.
t_colour	*colour_ambient_list(t_objlist *objlist)
{
	t_ambient	*ambient;
	t_colour	*colour;
	t_colour	*black;

	ambient = ambient_objlist(objlist);
	black = colour_full(BLACK);
	colour = colour_ambient(black, ambient);
	free_colour(black);
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
