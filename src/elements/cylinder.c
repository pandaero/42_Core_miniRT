/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:31:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 00:09:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a cylinder.
t_cylinder	*cylinder_create(void)
{
	t_cylinder	*new;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
	new->colour = 0;
	new->radius = 0;
	new->height = 0;
	new->centre = NULL;
	new->orientation = NULL;
	return (new);
}

//Function creates a defined cylinder from centre, radius and height.
t_cylinder	*cylinder_centre_orient_radius_height(t_point *centre, \
				t_direction *orientation, double radius, double height)
{
	t_cylinder	*cylinder;

	cylinder = cylinder_create();
	cylinder->radius = radius;
	cylinder->height = height;
	cylinder->centre = point_copy(centre);
	cylinder->orientation = direction_copy(orientation);
	return (cylinder);
}

//Function assigns a colour to an existing cylinder.
void	cylinder_colour(t_colour colour, t_cylinder *cylinder)
{
	cylinder->colour = colour;
}

//Function creates a defined cylinder from a valid input line.
t_cylinder	*cylinder_line(const char *line)
{
	t_cylinder	*new;
	char		**split;
	char		*clean;

	new = cylinder_create();
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
		return (free_cylinder_ret_null(new));
	new->centre = point_str(split[1]);
	new->orientation = direction_str(split[2]);
	new->radius = ft_atof(split[3]) / 2;
	new->height = ft_atof(split[4]);
	new->colour = colour_str(split[5]);
	free_split(split);
	return (new);
}
