/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:39:00 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/19 20:43:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a disc.
t_disc	*disc_create(void)
{
	t_disc	*new;

	new = (t_disc *)malloc(sizeof(t_disc));
	if (!new)
		return (NULL);
	new->colour = 0;
	new->point = NULL;
	new->normal = NULL;
	new->radius = 0;
	return (new);
}

//Function creates a defined disc from a colour, point and normal direction.
t_disc	*disc_col_point_normal_dir(t_colour colour, t_point *point, \
									t_direction *normal, double radius)
{
	t_disc	*disc;

	disc = disc_create();
	if (!disc)
		return (NULL);
	disc->colour = colour;
	disc->point = point_copy(point);
	disc->normal = direction_copy(normal);
	disc->radius = radius;
	return (disc);
}

//Function creates a defined disc from a colour, point and normal vector.
t_disc	*disc_col_point_normal_vec(t_colour colour, t_point *point, \
									t_vector *normal, double radius)
{
	t_disc	*disc;

	disc = disc_create();
	if (!disc)
		return (NULL);
	disc->colour = colour;
	disc->point = point_copy(point);
	disc->normal = direction_vector(normal);
	disc->radius = radius;
	return (disc);
}
