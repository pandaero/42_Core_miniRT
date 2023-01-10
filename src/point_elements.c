/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:04 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 18:49:29 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function creates a new defined point object.
t_point	*point_new(double x_coord, double y_coord, double z_coord)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x_co = x_coord;
	new->y_co = y_coord;
	new->z_co = z_coord;
	return (new);
}

//Function copies a defined point object's properties to a new one.
t_point	*point_copy(t_point *point)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x_co = point->x_co;
	new->y_co = point->y_co;
	new->z_co = point->z_co;
	return (new);
}
