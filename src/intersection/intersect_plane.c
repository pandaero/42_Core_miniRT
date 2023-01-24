/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/24 19:03:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Produces the distance between the point of origin to the point of intersection
t_point	*get_intersection_point(t_ray *ray, double t)
{
	return (point_coords \
			(ray->ray_orig->x_co + t * ray->ray_dir->x_comp, \
			ray->ray_orig->y_co + t * ray->ray_dir->y_comp, \
			ray->ray_orig->z_co + t * ray->ray_dir->z_comp));
}

//Function works out an intersection between a ray and a plane object.
t_intersect	*intersection_ray_plane(t_objlist *objlist, t_ray *ray, \
										t_obj *obj_plane)
{
	t_intersect	*intersection;
	t_vector	*ray_dir_vec;
	t_vector	*plane_norm_vec;
	t_vector	*plane_vec;
	t_ip		ip;

	(void) objlist;
	ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
	plane_norm_vec = vector_scale_direction(1, obj_plane->plane->normal);
	if (fabs(vector_dot(plane_norm_vec, ray_dir_vec)) > 0)
	{
		plane_vec = vector_two_points(obj_plane->plane->point, ray->ray_orig);
		ip.numer = vector_dot(plane_vec, plane_norm_vec);
		free_vector(plane_vec);
		ip.inter_dist = ip.numer / vector_dot(plane_norm_vec, ray_dir_vec);
		if (fabs(ip.inter_dist) > 0)
		{
			intersection = intersect_create();
			intersection->object = obj_plane;
			intersection->point = get_intersection_point(ray, \
														fabs(ip.inter_dist));
			intersection->colour = colour_lighting(objlist, intersection);
			intersection->distance = ip.inter_dist;
			intersection->state = 1;
		}
		else
			intersection = intersect_create();
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
