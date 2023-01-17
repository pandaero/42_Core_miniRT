/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:31:42 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:36 by pandalaf         ###   ########.fr       */
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
