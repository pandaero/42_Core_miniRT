/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:21:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 22:38:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a sphere.
t_sphere	*sphere_create(void)
{
	t_sphere	*new;

	new = (t_sphere *)malloc(sizeof(t_sphere));
	new->colour = 0;
	new->radius = 0;
	new->centre = NULL;
	return (new);
}

//Function creates a defined sphere from colour, centre and radius.
t_sphere	*sphere_col_centre_radius(t_colour colour, t_point *centre, \
									double radius)
{
	t_sphere	*sphere;

	sphere = sphere_create();
	sphere->colour = colour;
	sphere->radius = radius;
	sphere->centre = point_copy(centre);
	return (sphere);
}
