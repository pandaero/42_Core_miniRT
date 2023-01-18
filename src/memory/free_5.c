/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 23:32:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a cylinder.
void	free_cylinder(t_cylinder *cylinder)
{
	free_point(cylinder->centre);
	free_direction(cylinder->orientation);
	free(cylinder);
}

//Function frees an ambient light.
void	free_ambient(t_ambient *ambient)
{
	free(ambient);
}

//Function frees an intersection.
void	free_intersection(t_intersect *intersection)
{
	free_point(intersection->point);
	free(intersection);
}

//Function frees a pixel.
void	free_pixel(t_pixel *pixel)
{
	// if (pixel->intrsct->state == 1)
	// 	free_intersection(pixel->intrsct);
	free_point(pixel->point);
	free(pixel);
}
