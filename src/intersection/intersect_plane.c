/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/11 16:59:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>

//Function to initialize plane intersection.
static void	init_ray_plane_intersection(t_ray *ray, t_plane *plane, \
										t_itsct_plane *ip)
{
	ip->polo = NULL;
	ip->ray_dir_vec = vector_mag_dir(1, ray->ray_dir);
	ip->plane_norm_vec = vector_mag_dir(1, plane->normal);
	ip->denominator = vector_dot(ip->plane_norm_vec, ip->ray_dir_vec);
}

//Function to perform ray-plane intersection calculations.
static void	intersection_calculation(t_ray *ray, t_plane *plane, \
										t_itsct_plane *ip)
{
	ip->polo = vector_two_points(ray->ray_orig, plane->point);
	ip->t = vector_dot(ip->polo, ip->plane_norm_vec) / ip->denominator;
	if (ip->t >= 0)
	{
		ip->itsct->state = INTERSECTED;
		ip->itsct->point = point_ray_distance(ray, ip->t);
		ip->itsct->distance = ip->t;
		ip->itsct->normal = direction_copy(plane->normal);
		if (direction_dot(ip->itsct->normal, ray->ray_dir) > -DBL_EPSILON)
		{
			free(ip->itsct->normal);
			ip->itsct->normal = direction_reverse(plane->normal);
		}
	}
	free_vector(ip->polo);
}

//Function checks for intersection between plane and ray
t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_itsct_plane	ip;

	init_ray_plane_intersection(ray, plane, &ip);
	ip.itsct = intersect_create();
	if (fabs(ip.denominator) >= DBL_EPSILON)
		intersection_calculation(ray, plane, &ip);
	if (ip.itsct->state != INTERSECTED)
		ip.itsct->state = MISSED;
	free_vector(ip.ray_dir_vec);
	free_vector(ip.plane_norm_vec);
	return (ip.itsct);
}
