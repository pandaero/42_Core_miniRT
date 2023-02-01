/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/01 14:42:13 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>

//Function gets a colour value from an input string. ("0-255,0-255,0-255")
t_colour	colour_str(const char *str)
{
	t_colour	col;
	char		**split;
	char		*clean;

	if (contains_newline(str) == 1)
	{
		clean = clean_newline(str);
		split = ft_split(clean, ',');
		free(clean);
	}
	else
		split = ft_split(str, ',');
	col = (ft_atoi(split[0]) * 0x00010000) + (ft_atoi(split[1]) * 0x00000100) \
			+ (ft_atoi(split[2]) * 0x00000001);
	free_split(split);
	return (col);
}

//Function adds ambient light to a colour.
t_colour	colour_ambient(t_colour colour, t_ambient *ambient)
{
	t_colour	resulting;

	resulting = colour + (int)(ambient->ratio * ambient->colour);
	if (resulting > WHITE)
		resulting = WHITE;
	if (resulting < BLACK)
		resulting = BLACK;
	return (resulting);
}

//Function works out the lighting effect of a diffuse light on a point. Linear.
t_colour	colour_diffuse_linear(t_diffuse *difflight, t_point *point)
{
	t_colour	colour;
	double		distance;

	distance = distance_two_points(difflight->position, point);
	colour = (int)(difflight->ratio * WHITE * LIGHTING_FACTOR / distance);
	if (colour > WHITE)
		colour = WHITE;
	if (colour < BLACK)
		colour = BLACK;
	return (colour);
}

//Function works out the lighting effect of a diffuse light on a point. Inv. Sq.
t_colour	colour_diffuse_inverse_square(t_diffuse *difflight, t_point *point)
{
	t_colour	colour;
	double		distance;

	distance = distance_two_points(difflight->position, point);
	colour = (int)(difflight->ratio * WHITE * LIGHTING_FACTOR \
				/ pow(distance, 2));
	if (colour > WHITE)
		colour = WHITE;
	if (colour < BLACK)
		colour = BLACK;
	return (colour);
}

//Function determines the colour of an object.
t_colour	colour_object(t_obj *object)
{
	t_colour	colour;

	if (object->plane)
		colour = object->plane->colour;
	else if (object->sphere)
		colour = object->sphere->colour;
	else if (object->cylinder)
		colour = object->cylinder->colour;
	else
		colour = 0;
	return (colour);
}
