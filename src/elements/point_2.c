/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:21:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 16:12:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function works out a point along a distance through a ray.
t_point	point_ray_distance(t_ray ray, double distance)
{
	t_point	point;

	point.x_co = ray.ray_orig.x_co + ray.ray_dir.x_comp * distance;
	point.y_co = ray.ray_orig.y_co + ray.ray_dir.y_comp * distance;
	point.z_co = ray.ray_orig.z_co + ray.ray_dir.z_comp * distance;
	return (point);
}

//Function gives a point that is the subtraction of point 2 from point 1.
t_point	point_subtract(t_point p1, t_point p2)
{
	t_point	point;

	point.x_co = p1.x_co - p2.x_co;
	point.y_co = p1.y_co - p2.y_co;
	point.z_co = p1.z_co - p2.z_co;
	return (point);
}
