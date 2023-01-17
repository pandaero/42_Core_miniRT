/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/17 14:37:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <math.h>

//Function determines whether a ray intersects with a plane.
int	ray_plane_intersection(t_ray	*ray, t_plane *plane)
{
	t_vector	*vec_ray_dir;	
	t_vector	*plane_vector;
	t_vector	*l;
	t_ip		ip;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	plane_vector = vector_scale_direction(1, plane->normal);
	ip.divisor = vector_dot(vec_ray_dir, plane_vector);
	if (ip.divisor == 0)
	{
		free_vector(plane_vector);
		free_vector(vec_ray_dir);
		return (0);
	}
	l = vector_two_points(ray->ray_orig, plane->point);
	ip.t = vector_dot(l, plane_vector) / vector_dot(vec_ray_dir, plane_vector);
	ip.intersection = 0;
	if (ip.t >= 0)
		ip.intersection = 1;
	free_vector(l);
	free_vector(vec_ray_dir);
	free_vector(plane_vector);
	return (ip.intersection);
}
