/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:21:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/02 19:13:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a sphere.
t_sphere	*sphere_create(void)
{
	t_sphere	*new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	new->colour = NULL;
	new->radius = 0;
	new->centre = NULL;
	return (new);
}

//Function creates a defined sphere from colour, centre and radius.
t_sphere	*sphere_col_centre_radius(t_colour *colour, t_point *centre, \
									double radius)
{
	t_sphere	*sphere;

	sphere = sphere_create();
	sphere->colour = colour;
	sphere->radius = radius;
	sphere->centre = point_copy(centre);
	return (sphere);
}

//Function creates a defined sphere from a valid input line.
t_sphere	*sphere_line(const char *line)
{
	t_sphere	*new;
	char		**split;
	char		*clean;

	new = sphere_create();
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
		free_sphere(new);
		return (NULL);
	}
	new->centre = point_str(split[1]);
	new->radius = ft_atof(split[2]);
	new->colour = colour_str(split[3]);
	return (new);
}
