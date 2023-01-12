/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:30:27 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/12 18:09:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <math.h>

//Function works out the length/distance between two points.
double	distance_two_points(t_point *point_one, t_point *point_two)
{
	double	distance;

	distance = sqrt(pow(point_two->x_co - point_one->x_co, 2)
			+ pow(point_two->y_co - point_one->y_co, 2)
			+ pow(point_two->z_co - point_one->z_co, 2));
	return (distance);
}
