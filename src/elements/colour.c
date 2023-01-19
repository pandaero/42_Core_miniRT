/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 22:32:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

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
