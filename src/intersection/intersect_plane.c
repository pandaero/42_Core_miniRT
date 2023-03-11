/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/11 12:16:15 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <float.h>

//Function to initialize intersect plane functions
static t_ip	*init_ray_plane(t_ray *ray, t_plane *plane)
{
	t_ip	*ip;

	ip = (t_ip *)malloc(sizeof(t_ip));
	ip->polo = NULL;
	ip->ray_dir_vec = vector_mag_dir(1, ray->ray_dir);
	ip->plane_norm_vec = vector_mag_dir(1, plane->normal);
	ip->denominator = vector_dot(ip->plane_norm_vec, ip->ray_dir_vec);
	return (ip);
}

//Function to free
static void	free_ip(t_ip *ip)
{
	free_vector(ip->ray_dir_vec);
	free_vector(ip->plane_norm_vec);
	free(ip);
}

//Function checks for intersection between plane and ray
t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_intersect	*intersection;
	t_direction	*normal;
	t_ip		*ip;

	intersection = intersect_create();
	ip = init_ray_plane(ray, plane);
	if (fabs(ip->denominator) >= DBL_EPSILON)
	{
		ip->polo = vector_two_points(ray->ray_orig, plane->point);
		ip->t = vector_dot(ip->polo, ip->plane_norm_vec) / ip->denominator;
		if (ip->t >= 0)
		{
			intersection->state = INTERSECTED;
			intersection->point = point_ray_distance(ray, ip->t);
			intersection->distance = ip->t;
			intersection->normal = direction_copy(plane->normal);
			if (direction_dot(normal, ray->ray_dir) > -DBL_EPSILON)
			{
				free(intersection->normal);
				intersection->normal = direction_reverse(plane->normal);
			}
		}
		free_vector(ip->polo);
	}
	if (intersection->state != INTERSECTED)
		intersection->state = MISSED;
	free_ip(ip);
	return (intersection);
}
