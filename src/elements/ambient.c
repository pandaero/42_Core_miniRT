/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:22:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 18:25:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates an ambient element from another.
t_ambient	ambient_copy(t_ambient other)
{
	t_ambient	new;

	new.ratio = other.ratio;
	new.colour = other.colour;
	return (new);
}

//Function creates an ambient light according to colour and ratio.
t_ambient	ambient_input(t_colour colour, double ratio)
{
	t_ambient	ambient;

	ambient.ratio = ratio;
	ambient.colour = colour_copy(colour);
	return (ambient);
}

//Function creates an ambient light from a valid input line.
t_ambient	ambient_line(const char *str)
{
	t_ambient	new;
	char		**split;
	char		*clean;

	split = ft_split(str, ' ');
	if (contains_newline(split[2]) == 1)
	{
		clean = clean_newline(split[2]);
		new.colour = colour_str(clean);
		free(clean);
	}
	else
		new.colour = colour_str(split[2]);
	new.ratio = ft_atof(split[1]);
	free_split(split);
	return (new);
}
