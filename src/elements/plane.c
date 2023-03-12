/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:22:24 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/12 21:44:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a plane.
t_plane	*plane_create(void)
{
	t_plane	*new;

	new = (t_plane *)malloc(sizeof(t_plane));
	if (!new)
		return (NULL);
	new->colour = NULL;
	new->point = NULL;
	new->normal = NULL;
	return (new);
}

//Function creates a defined plane from a colour, point and normal direction.
t_plane	*plane_col_point_normal_dir(t_colour *colour, t_point *point, \
									t_direction *normal)
{
	t_plane	*plane;

	plane = plane_create();
	if (!plane)
		return (NULL);
	plane->colour = colour_copy(colour);
	plane->point = point_copy(point);
	plane->normal = direction_copy(normal);
	return (plane);
}

//Function creates a defined plane from a colour, point and normal vector.
t_plane	*plane_col_point_normal_vec(t_colour *colour, t_point *point, \
									t_vector *normal)
{
	t_plane	*plane;

	plane = plane_create();
	if (!plane)
		return (NULL);
	plane->colour = colour_copy(colour);
	plane->point = point_copy(point);
	plane->normal = direction_vector(normal);
	return (plane);
}

//Function creates a defined plane from a valid input line.
t_plane	*plane_line(const char *line)
{
	t_plane	*new;
	char	**split;
	char	*clean;

	new = plane_create();
	if (!new)
		return (NULL);
	if (contains_newline(line) == 1)
	{
		clean = clean_newline(line);
		split = ft_split(clean, ' ');
		free(clean);
	}
	else
		split = ft_split(line, ' ');
	if (!split)
	{
		free_plane(new);
		return (NULL);
	}
	new->point = point_str(split[1]);
	new->normal = direction_str(split[2]);
	new->colour = colour_str(split[3]);
	free_split(split);
	return (new);
}
