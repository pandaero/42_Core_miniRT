/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:15:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 22:19:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a pixel with its point coordinates.
t_pixel	*pixel_point(t_point point)
{
	t_pixel	*pixel;

	pixel = (t_pixel *)malloc(sizeof(t_pixel));
	pixel->point = point_copy(point);
	pixel->itsct.state = UNCALCULATED;
	pixel->sec_itsct.state = UNCALCULATED;
	return (pixel);
}
