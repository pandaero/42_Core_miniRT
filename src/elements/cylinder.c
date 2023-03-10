/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:31:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/10 13:56:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a cylinder.
t_cylinder	*cylinder_create(void)
{
	t_cylinder	*new;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
	new->colour = NULL;
	new->radius = 0;
	new->height = 0;
	new->centre = NULL;
	new->orientation = NULL;
	new->top_cap = NULL;
	new->base_cap = NULL;
	return (new);
}

//Function assigns disc caps to a cylinder.
static void	give_caps(t_cylinder *cyl)
{
	t_point	*top_centre;
	t_point	*base_centre;
	t_vector	*vec_centre_top;
	t_vector	*vec_centre_base;
	t_direction	*neg_axis;

	vec_centre_top = vector_scale_direction(cyl->height / 2, cyl->orientation);
	neg_axis = reverse_direction(cyl->orientation);
	vec_centre_base = vector_scale_direction(cyl->height / 2, neg_axis);
	top_centre = point_point_vector(cyl->centre, vec_centre_top);
	base_centre = point_point_vector(cyl->centre, vec_centre_base);
	cyl->top_cap = disc_centre_normal_radius_colour(top_centre, cyl->orientation, \
				cyl->radius, cyl->colour);
	cyl->base_cap = disc_centre_normal_radius_colour(base_centre, cyl->orientation, \
				cyl->radius, cyl->colour);
	free_vector(vec_centre_top);
	free_vector(vec_centre_base);
	free_direction(neg_axis);
	free_point(top_centre);
	free_point(base_centre);
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
	give_caps(cylinder);
	return (cylinder);
}

//Function assigns a colour to an existing cylinder.
void	cylinder_colour(t_colour *colour, t_cylinder *cylinder)
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
	give_caps(new);
	free_split(split);
	return (new);
}
