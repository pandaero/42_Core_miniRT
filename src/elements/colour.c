/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/08 17:00:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a colour.
t_colour	*colour_create(void)
{
	t_colour	*col;

	col = (t_colour *)malloc(sizeof(t_colour));
	if (!col)
		return (NULL);
	col->full = 0;
	col->trans = 0;
	col->red = 0;
	col->green = 0;
	col->blue = 0;
	return (col);
}

//Function copies a colour to a new one.
t_colour	*colour_copy(t_colour *colour)
{
	t_colour	*col;

	col = (t_colour *)malloc(sizeof(t_colour));
	if (!col)
		return (NULL);
	col->full = colour->full;
	col->trans = colour->trans;
	col->red = colour->red;
	col->green = colour->green;
	col->blue = colour->blue;
	return (col);
}

//Function gets a colour value from an input string. ("0-255,0-255,0-255")
t_colour	*colour_str(const char *str)
{
	t_colour	*col;
	char		**split;
	char		*clean;

	col = colour_create();
	if (contains_newline(str) == 1)
	{
		clean = clean_newline(str);
		split = ft_split(clean, ',');
		free(clean);
	}
	else
		split = ft_split(str, ',');
	col->trans = 0;
	col->red = ft_atoi(split[0]);
	col->green = ft_atoi(split[1]);
	col->blue = ft_atoi(split[2]);
	col->full = col->trans + col->red + col->green + col->blue;
	free_split(split);
	return (col);
}

//Function adds ambient light to a colour.
t_colour	*colour_ambient(unsigned int full, t_ambient *ambient)
{
	t_colour	*ret;

	ret = colour_create();
	ret->trans = 0;
	ret->red = ambient->ratio * ambient->colour->red + \
				((full & 0x00FF0000) >> 16);
	if (ret->red > 255)
		ret->red = 255;
	ret->green = ambient->ratio * ambient->colour->green + \
				((full & 0x0000FF00) >> 8);
	if (ret->green > 255)
		ret->green = 255;
	ret->blue = ambient->ratio * ambient->colour->blue + \
				((full & 0x000000FF));
	if (ret->blue > 255)
		ret->blue = 255;
	ret->full = ret->trans * 0x01000000 + ret->red * 0x00010000 + \
				ret->green * 0x00000100 + ret->blue;
	if (ret->full > WHITE)
		ret->full = WHITE;
	return (ret);
}

//Function determines the colour of an object.
t_colour	*colour_object(t_obj *object)
{
	t_colour	*colour;

	if (object->plane)
		colour = object->plane->colour;
	else if (object->sphere)
		colour = object->sphere->colour;
	else if (object->cylinder)
		colour = object->cylinder->colour;
	else
		colour = NULL;
	return (colour);
}
