/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:48:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 01:38:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function adds ambient light to a colour.
t_colour	colour_ambient(t_colour col, t_ambient ambient)
{
	t_colour	ret;

	ret.trans = 0;
	ret.red = ambient.ratio * ambient.colour.red + \
				((col.full & 0xFF0000) >> 16);
	if (ret.red > 255)
		ret.red = 255;
	ret.green = ambient.ratio * ambient.colour.green + \
				((col.full & 0xFF00) >> 8);
	if (ret.green > 255)
		ret.green = 255;
	ret.blue = ambient.ratio * ambient.colour.blue + \
				((col.full & 0xFF));
	if (ret.blue > 255)
		ret.blue = 255;
	ret.full = ret.trans * 0x1000000 + ret.red * 0x10000 + \
				ret.green * 0x100 + ret.blue;
	if (ret.full > WHITE)
		ret.full = WHITE;
	return (ret);
}

//Function works out the ambient light colour from an object list.
t_colour	colour_ambient_list(t_objlist *objlist)
{
	t_ambient	ambient;
	t_colour	colour;

	ambient = ambient_objlist(objlist);
	colour = colour_ambient(colour_full(BLACK), ambient);
	return (colour);
}
