/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:14:32 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 02:16:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function works out the dot product of two directions.
double	direction_dot(t_direction *dir1, t_direction *dir2)
{
	double	res;

	res = dir1->x_comp * dir2->x_comp + dir1->y_comp * dir2->y_comp + \
			dir1->z_comp * dir2->z_comp;
	return (res);
}
