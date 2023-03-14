/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:12:04 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 16:13:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function copies a defined point object's properties to a new one.
t_point	point_copy(t_point point)
{
	t_point	new;

	new.x_co = point.x_co;
	new.y_co = point.y_co;
	new.z_co = point.z_co;
	return (new);
}

//Function creates a new defined point object from coordinates.
t_point	point_coords(double x_coord, double y_coord, double z_coord)
{
	t_point	new;

	new.x_co = x_coord;
	new.y_co = y_coord;
	new.z_co = z_coord;
	return (new);
}

//Function creates a point resulting from a vector and a starting point.
t_point	point_point_vector(t_point start, t_vector vector)
{
	t_point	new;

	if (vector.mag == 0)
		return (point_copy(start));
	new.x_co = start.x_co + vector.x_comp;
	new.y_co = start.y_co + vector.y_comp;
	new.z_co = start.z_co + vector.z_comp;
	return (new);
}

//Function creates a point from a valid input string.
t_point	point_str(const char *str)
{
	t_point	point;
	char	**split;

	split = ft_split(str, ',');
	point.x_co = ft_atof(split[0]);
	point.y_co = ft_atof(split[1]);
	point.z_co = ft_atof(split[2]);
	free_split(split);
	return (point);
}
