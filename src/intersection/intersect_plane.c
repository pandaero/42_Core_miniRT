/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/01 14:56:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

#define EPSILON 0.00000000000000022

//Function to initialize intersect plane functions
static t_ip	*init_ray_plane(t_ray *ray, t_plane *plane)
{
	t_ip	*ip;

	ip = (t_ip *)malloc(sizeof(t_ip));
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
	free_vector(ip->polo);
}

//Function checks for intersection between plane and ray
t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_intersect	*intersection;
	t_ip		*ip;

	intersection = intersect_create();
	ip = init_ray_plane(ray, plane);
	if (fabs(ip->denominator) > EPSILON)
	{
		ip->polo = vector_two_points(ray->ray_orig, plane->point);
		ip->t = vector_dot(ip->polo, ip->plane_norm_vec) / ip->denominator;
		if (ip->t >= 0)
		{
			intersection->state = 1;
			intersection->point = point_ray_distance(ray, ip->t);
			intersection->distance = ip->t;
		}
	}
	free_ip(ip);
	return (intersection);
}
