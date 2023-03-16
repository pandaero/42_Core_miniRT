/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:21:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 16:56:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a new sphere element from another.
t_sphere	sphere_copy(t_sphere other)
{
	t_sphere	new;

	new.radius = other.radius;
	new.colour = colour_copy(other.colour);
	new.centre = point_copy(other.centre);
	return (new);
}

//Function creates a defined sphere from colour, centre and radius.
t_sphere	sphere_col_centre_radius(t_colour colour, t_point centre, \
									double radius)
{
	t_sphere	sphere;

	sphere.colour = colour;
	sphere.radius = radius;
	sphere.centre = point_copy(centre);
	return (sphere);
}

//Function creates a defined sphere from a valid input line.
t_sphere	sphere_line(const char *line)
{
	t_sphere	new;
	char		**split;
	char		*clean;

	if (contains_newline(line) == 1)
	{
		clean = clean_newline(line);
		split = ft_split(clean, ' ');
		free(clean);
	}
	else
		split = ft_split(line, ' ');
	new.centre = point_str(split[1]);
	new.radius = ft_atof(split[2]) / 2;
	new.colour = colour_str(split[3]);
	free_split(split);
	return (new);
}
