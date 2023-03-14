/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:48:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 15:23:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function works out the dot product of two vectors.
double	vector_dot(t_vector first, t_vector second)
{
	return (first.x_comp * second.x_comp + \
			first.y_comp * second.y_comp + \
			first.z_comp * second.z_comp);
}

//Function works out the dot product of two directions.
double	direction_dot(t_direction dir1, t_direction dir2)
{
	double	res;

	res = dir1.x_comp * dir2.x_comp + dir1.y_comp * dir2.y_comp + \
			dir1.z_comp * dir2.z_comp;
	return (res);
}

//Function returns the size of a ft_split-created array.
int	split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
