/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 03:03:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a cylinder.
void	free_cylinder(t_cylinder *cylinder)
{
	free_colour(cylinder->colour);
	free_disc(cylinder->top_cap);
	free_disc(cylinder->base_cap);
	free_point(cylinder->centre);
	free_direction(cylinder->orientation);
	free(cylinder);
	cylinder = NULL;
}

//Function frees an ambient light.
void	free_ambient(t_ambient *ambient)
{
	free_colour(ambient->colour);
	free(ambient);
	ambient = NULL;
}

//Function frees an intersection.
void	free_intersection(t_intersect *intersection)
{
	if (intersection->state == INTERSECTED)
	{
		if (intersection->normal)
			free_direction(intersection->normal);
		if (intersection->point)
			free_point(intersection->point);
	}
	if (intersection->colour)
		free_colour(intersection->colour);
	free(intersection);
	intersection = NULL;
}

//Function frees a pixel.
void	free_pixel(t_pixel *pixel)
{
	free_colour(pixel->colour);
	free_intersection(pixel->itsct);
	if (pixel->sec_itsct)
		free_sec_intersection(pixel->sec_itsct);
	free_point(pixel->point);
	free(pixel);
	pixel = NULL;
}

//Function frees a 2D char array made from ft_split.
void	free_split(char **charr)
{
	int	i;

	i = 0;
	while (charr[i])
	{
		free(charr[i]);
		i++;
	}
	free(charr);
	charr = NULL;
}
