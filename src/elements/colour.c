/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/21 18:24:06 by pandalaf         ###   ########.fr       */
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

//Function creates a colour from the full colour.
t_colour	*colour_full(int full)
{
	t_colour	*new;

	new = (t_colour *)malloc(sizeof(t_colour));
	if (!new)
		return (NULL);
	new->full = full;
	new->trans = full & 0xFF000000;
	new->red = full & 0xFF0000;
	new->green = full & 0xFF00;
	new->blue = full & 0xFF;
	return (new);
}

//Function creates a colour from an input string. ("0-255,0-255,0-255")
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
	col->full = col->trans * 0x1000000 + col->red * 0x10000 + \
				col->green * 0x100 + col->blue;
	free_split(split);
	return (col);
}

//Function determines the colour of an object.
t_colour	*colour_object(t_obj *object)
{
	t_colour	*colour;

	if (object->elem == PLANE)
		colour = object->plane->colour;
	else if (object->elem == SPHERE)
		colour = object->sphere->colour;
	else if (object->elem == CYLINDER)
		colour = object->cylinder->colour;
	else
		colour = NULL;
	return (colour);
}
