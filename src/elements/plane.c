/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 18:15:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a new plane element from another.
t_plane	plane_copy(t_plane other)
{
	t_plane	new;

	new.colour = colour_copy(other.colour);
	new.point = point_copy(other.point);
	new.normal = direction_copy(other.normal);
	return (new);
}

//Function creates a defined plane from a colour, point and normal direction.
t_plane	plane_col_point_normal_dir(t_colour colour, t_point point, \
									t_direction normal)
{
	t_plane	plane;

	plane.colour = colour_copy(colour);
	plane.point = point_copy(point);
	plane.normal = direction_copy(normal);
	return (plane);
}

//Function creates a defined plane from a colour, point and normal vector.
t_plane	plane_col_point_normal_vec(t_colour colour, t_point point, \
									t_vector normal)
{
	t_plane	plane;

	plane.colour = colour_copy(colour);
	plane.point = point_copy(point);
	plane.normal = direction_vector(normal);
	return (plane);
}

//Function creates a defined plane from a valid input line.
t_plane	plane_line(const char *line)
{
	t_plane	new;
	char	**split;
	char	*clean;

	if (contains_newline(line) == 1)
	{
		clean = clean_newline(line);
		split = ft_split(clean, ' ');
		free(clean);
	}
	else
		split = ft_split(line, ' ');
	new.point = point_str(split[1]);
	new.normal = direction_str(split[2]);
	new.colour = colour_str(split[3]);
	free_split(split);
	return (new);
}
