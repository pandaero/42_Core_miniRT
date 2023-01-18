/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/18 14:16:40 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for testing
#include <stdio.h>
#include <stdlib.h>

//Allocates memory and places argument values in the intersection structure
t_intersect	*intersection_data\
(t_colour color_in, int state, \
double dist_in, t_point *point_in)
{
	t_intersect	*intersection;

	intersection = intersect_create();
	intersection->colour = color_in;
	intersection->distance = dist_in;
	intersection->point = point_in;
	intersection->state = state;
}

//Produces the distance between the point of origin to the point of intersection
t_point	*get_intersection_point(t_ray *ray, double t)
{
	return (point_coords\
	(ray->ray_orig->x_co + t * ray->ray_dir->x_comp, \
	ray->ray_orig->y_co + t * ray->ray_dir->y_comp, \
	ray->ray_orig->z_co + t * ray->ray_dir->z_comp));
}

t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_intersect	*intersection;
	t_vector	*ray_dir_vec;
	t_vector	*plane_norm_vec;
	t_vector	*plane_vec;
	t_ip		ip;

	ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
	plane_norm_vec = vector_scale_direction(1, plane->normal);
	if (fabs(vector_dot(plane_norm_vec, ray_dir_vec)) > 0)
	{
		plane_vec = vector_two_points(plane->point, ray->ray_orig);
		ip.numer = vector_dot(plane_vec, plane_norm_vec);
		free_vector(plane_vec);
		ip.inter_dist = ip.numer / vector_dot(plane_norm_vec, ray_dir_vec);
		if (ip.inter_dist > 0)
			intersection = intersection_data(plane->colour, 0, ip.inter_dist, \
			get_intersection_point(ray, ip.inter_dist));
		else
			intersection = intersection_data(plane->colour, 1, ip.inter_dist, \
			get_intersection_point(ray, ip.inter_dist));
	}
	free_vector(ray_dir_vec);
	free_vector(plane_norm_vec);
	return (intersection);
}

// int	intersection_ray_plane(t_ray *ray, t_plane *plane)
// {
// 	t_vector	*ray_dir_vec;
// 	t_vector	*plane_norm_vec;
// 	t_vector	*plane_vec;
// 	double		inter_dist;
// 	double		numer;

// 	ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
// 	plane_norm_vec = vector_scale_direction(1, plane->normal);
// 	if (fabs(vector_dot(plane_norm_vec, ray_dir_vec)) > 0)
// 	{
// 		plane_vec = vector_two_points(plane->point, ray->ray_orig);
// 		numer = vector_dot(plane_vec, plane_norm_vec);
// 		free_vector(plane_vec);
// 		inter_dist = numer / vector_dot(plane_norm_vec, ray_dir_vec);
// 		free_vector(ray_dir_vec);
// 		free_vector(plane_norm_vec);
// 		if (inter_dist > 0)
// 			return (0);
// 		return (1);
// 	}
// 	free_vector(ray_dir_vec);
// 	free_vector(plane_norm_vec);
// 	return (0);
// }

//Function determines whether a ray intersects with a plane.
// int	ray_plane_intersection(t_ray	*ray, t_plane *plane)
// {
// 	t_vector	*vec_ray_dir;	
// 	t_vector	*plane_vector;
// 	t_vector	*lp;
// 	t_vector	*vp;
// 	t_ip		ip;

// 	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
// 	plane_vector = vector_scale_direction(1, plane->normal);
// 	// plane_vector = generate_plane_vector(plane);
// 	ip.divisor = vector_dot(vec_ray_dir, plane_vector);
// 	if (ip.divisor == 0)
// 	{
// 		free_vector(plane_vector);
// 		free_vector(vec_ray_dir);
// 		return (0);
// 	}
// 	lp = vector_two_points(ray->ray_orig, plane->point);
// 	vp = vector_scale(-1, lp);
// 	//  = vector_two_points(ray->ray_orig, plane->point);
// 	ip.t = vector_dot(vp, plane_vector) / ip.divisor;
// 	ip.intersection = 0;
// 	if (ip.t >= 0)
// 		ip.intersection = 1;
// 	free_vector(lp);
// 	free_vector(vp);
// 	free_vector(vec_ray_dir);
// 	free_vector(plane_vector);
// 	return (ip.intersection);
// }
