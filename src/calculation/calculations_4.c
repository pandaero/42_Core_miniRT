/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:14:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/23 15:40:25 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function works out the dot product of two directions.
double	direction_dot(t_direction *dir1, t_direction *dir2)
{
	double	res;

	res = dir1->x_comp * dir2->x_comp + dir1->y_comp * dir2->y_comp + \
			dir1->z_comp * dir2->z_comp;
	return (res);
}

//Function works out the angle between two directions.
double	angle_directions(t_direction *dir1, t_direction *dir2)
{
	double	out;

	out = acos(direction_dot(dir1, dir2));
	return (out);
}
