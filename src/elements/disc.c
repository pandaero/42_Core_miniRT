/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:48:28 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/13 18:35:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a new disc element from another.
t_disc	disc_copy(t_disc other)
{
	t_disc	new;

	new.radius = other.radius;
	new.colour = colour_copy(other.colour);
	new.centre = point_copy(other.centre);
	new.normal = direction_copy(other.normal);
	return (new);
}

//Function creates a disc element from a centre, a normal direction, and radius.
t_disc	disc_centre_normal_radius_colour(t_point centre, t_direction norm, \
									double radius, t_colour colour)
{
	t_disc	new;

	new.centre = point_copy(centre);
	new.normal = direction_copy(norm);
	new.radius = radius;
	new.colour = colour_copy(colour);
	return (new);
}

//Function creates a disc element from a centre, plane, radius, and colour.
t_disc	disc_centre_plane_radius_colour(t_point centre, t_plane plane, \
											double radius, t_colour colour)
{
	t_disc	new;

	new.centre = point_copy(centre);
	new.normal = direction_copy(plane.normal);
	new.radius = radius;
	new.colour = colour_copy(colour);
	return (new);
}
