/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:21:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 20:27:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


//Function works out a point along a distance through a ray.
t_point	*point_ray_distance(t_ray *ray, double distance)
{
	t_point	*point;

	point = point_create();
	if (!point)
		return (NULL);
	point->x_co = ray->ray_orig + ray->ray_dir->x_comp * distance;
	point->y_co = ray->ray_orig + ray->ray_dir->y_comp * distance;
	point->z_co = ray->ray_orig + ray->ray_dir->z_comp * distance;
	return (point);
}
