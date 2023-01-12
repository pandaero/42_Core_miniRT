/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:04 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/12 17:35:30 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function creates and initialises a point.
t_point	*point_create(void)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x_co = 0;
	new->y_co = 0;
	new->z_co = 0;
	return (new);
}

//Function copies a defined point object's properties to a new one.
t_point	*point_copy(t_point *point)
{
	t_point	*new;

	new = point_create();
	if (!new)
		return (NULL);
	new->x_co = point->x_co;
	new->y_co = point->y_co;
	new->z_co = point->z_co;
	return (new);
}

//Function creates a new defined point object from coordinates.
t_point	*point_coords(double x_coord, double y_coord, double z_coord)
{
	t_point	*new;

	new = point_create();
	if (!new)
		return (NULL);
	new->x_co = x_coord;
	new->y_co = y_coord;
	new->z_co = z_coord;
	return (new);
}
