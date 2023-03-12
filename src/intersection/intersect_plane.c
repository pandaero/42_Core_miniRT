/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/12 02:47:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>

//Function to perform ray-plane intersection calculations.
static void	intersection_calculation(t_ray *ray, t_plane *plane, \
										t_itsct_plane *ip)
{
	t_direction	*temp;

	ip->ray_to_plane = vector_two_points(ray->ray_orig, plane->point);
	ip->dist = vector_dot(ip->ray_to_plane, ip->plane_norm_vec) / \
							ip->denominator;
	if (ip->dist > 0)
	{
		ip->itsct->state = INTERSECTED;
		ip->itsct->point = point_ray_distance(ray, ip->dist);
		ip->itsct->distance = ip->dist;
		ip->itsct->normal = direction_copy(plane->normal);
		if (direction_dot(ip->itsct->normal, ray->ray_dir) > -DBL_EPSILON)
		{
			temp = ip->itsct->normal;
			ip->itsct->normal = direction_reverse(plane->normal);
			free_direction(temp);
		}
	}
	free_vector(ip->ray_to_plane);
}

//Function checks for intersection between plane and ray
t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_itsct_plane	*ip;
	t_intersect		*out;

	ip = (t_itsct_plane *)malloc(sizeof(t_itsct_plane));
	ip->ray_dir_vec = vector_mag_dir(1, ray->ray_dir);
	ip->plane_norm_vec = vector_mag_dir(1, plane->normal);
	ip->denominator = vector_dot(ip->plane_norm_vec, ip->ray_dir_vec);
	ip->itsct = intersect_create();
	if (fabs(ip->denominator) >= DBL_EPSILON)
		intersection_calculation(ray, plane, ip);
	if (ip->itsct->state != INTERSECTED)
		ip->itsct->state = MISSED;
	free_vector(ip->ray_dir_vec);
	free_vector(ip->plane_norm_vec);
	out = ip->itsct;
	free(ip);
	return (out);
}
