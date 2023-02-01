/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/01 12:38:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

#define EPSILON 0.00000000000000022

//Function to initialize intersect plane functions
static t_plane_locals	*init_ray_plane(t_ray *ray, t_plane *plane)
{
	t_plane_locals	*locals;

	locals = (t_plane_locals *)malloc(sizeof(t_plane_locals));
	locals->ray_dir_vec = vector_mag_dir(1, ray->ray_dir);
	locals->plane_norm_vec = vector_mag_dir(1, plane->normal);
	locals->denominator = vector_dot\
	(locals->plane_norm_vec, locals->ray_dir_vec);
	return (locals);
}

//Function to free plane struct values
static void	free_plane_intersection(t_plane_locals *locals)
{
	free_vector(locals->ray_dir_vec);
	free_vector(locals->plane_norm_vec);
	free_vector(locals->polo);
}

//Function checks for intersection between plane and ray
t_intersect	*intersection_ray_plane(t_ray *ray, t_plane *plane)
{
	t_intersect			*intersection;
	t_plane_locals		*locals;

	intersection = intersect_create();
	locals = init_ray_plane(ray, plane);
	if (fabs(locals->denominator) > EPSILON)
	{
		locals->polo = vector_two_points(ray->ray_orig, plane->point);
		locals->t = vector_dot(locals->polo, locals->plane_norm_vec) \
		/ locals->denominator;
		if (locals->t >= 0)
		{
			intersection->state = 1;
			intersection->point = point_ray_distance(ray, locals->t);
			intersection->distance = locals->t;
			intersection->colour = plane->colour;
		}
	}
	else
	{
		intersection->state = 0;
		intersection->colour = 0x0000FF00;
	}
	free_plane_intersection(locals);
	return (intersection);
}
