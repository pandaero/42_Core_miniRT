/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/17 04:17:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a pixel.
t_pixel	*pixel_create(void)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
		return (NULL);
	new->point = NULL;
	new->itsct = NULL;
	new->sec_itsct = NULL;
	return (new);
}

//Function creates a pixel with its point coordinates.
t_pixel	*pixel_point(t_point *point)
{
	t_pixel	*pixel;

	pixel = pixel_create();
	if (!pixel)
		return (NULL);
	pixel->point = point_copy(point);
	return (pixel);
}
