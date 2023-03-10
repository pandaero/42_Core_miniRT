/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:48:28 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/10 13:44:14 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a new empty disc element.
t_disc	*disc_create(void)
{
	t_disc	*new;

	new = (t_disc *)malloc(sizeof(t_disc));
	if (!new)
		return (NULL);
	new->centre = NULL;
	new->normal = NULL;
	new->radius = 0;
	new->colour = NULL;
	return (new);
}

//Function creates a disc element from a centre, a normal direction, and radius.
t_disc	*disc_centre_normal_radius_colour(t_point *centre, t_direction *norm, \
									double radius, t_colour *colour)
{
	t_disc	*new;

	new = disc_create();
	if (!new)
		return (NULL);
	new->centre = point_copy(centre);
	new->normal = direction_copy(norm);
	new->radius = radius;
	new->colour = colour_copy(colour);
	return (new);
}

//Function creates a disc element from a centre, plane, radius, and colour.
t_disc	*disc_centre_plane_radius_colour(t_point *centre, t_plane *plane, \
											double radius, t_colour *colour)
{
	t_disc	*new;

	new = disc_create();
	new->centre = point_copy(centre);
	new->normal = direction_copy(plane->normal);
	new->radius = radius;
	new->colour = colour_copy(colour);
	return (new);
}
