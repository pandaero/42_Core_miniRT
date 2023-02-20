/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:20:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 02:29:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function adds two colours, creating a new one.
t_colour	*colour_add(t_colour *col1, t_colour *col2)
{
	t_colour	*new;

	new = colour_create();
	if (!new)
		return (NULL);
	new->trans = col1->trans + col2->trans;
	if (new->trans > 255)
		new->trans = 255;
	new->red = col1->red + col2->red;
	if (new->red > 255)
		new->red = 255;
	new->green = col1->green + col2->green;
	if (new->green > 255)
		new->green = 255;
	new->blue = col1->blue + col2->blue;
	if (new->blue > 255)
		new->blue = 255;
	new->full = new->trans * (0x1000000) + new->red * (0x10000) + \
				new->green * (0x100) + new->blue;
	return (new);
}

//Function subtracts two colours, creating a new one.
t_colour	*colour_subtract(t_colour *source, t_colour *col)
{
	t_colour	*new;

	new = colour_create();
	if (!new)
		return (NULL);
	new->trans = source->trans - col->trans;
	if (new->trans > 255)
		new->trans = 0;
	new->red = source->red - col->red;
	if (new->red > 255)
		new->red = 0;
	new->green = source->green - col->green;
	if (new->green > 255)
		new->green = 0;
	new->blue = source->blue - col->blue;
	if (new->blue > 255)
		new->blue = 0;
	new->full = new->trans * (0x1000000) + new->red * (0x10000) + \
				new->green * (0x100) + new->blue;
	return (new);
}

//Function applies a factor to a colour.
t_colour	*colour_factor(double factor, t_colour *col)
{
	t_colour	*ret;

	ret = colour_create();
	ret->trans = col->trans * factor;
	ret->red = col->red * factor;
	ret->green = col->green * factor;
	ret->blue = col->blue * factor;
	ret->full = ret->trans * 0x1000000 + ret->red * 0x10000 + \
				ret->green * 0x100 + ret->blue;
	return (ret);
}
