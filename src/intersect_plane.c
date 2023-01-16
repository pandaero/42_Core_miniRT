/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:54:59 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/16 20:23:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_intersect_plane
{
	double		divisor;
	double		t;
	int			intersection;
}			t_ip;

static t_vector	*generate_plane_vector(t_plane *plane)
{
	t_vector	*plane_vector;

	plane_vector = malloc(sizeof(t_vector));
	if (!plane_vector)
		return (NULL);
	plane_vector->x_comp = plane->point->x_co + plane->normal->x_comp;
	plane_vector->y_comp = plane->point->y_co + plane->normal->y_comp;
	plane_vector->z_comp = plane->point->z_co + plane->normal->z_comp;
	return (plane_vector);
}

static t_vector	*generate_l(t_ray *ray, t_plane *plane)
{
	t_vector	*l;

	l = (t_vector *)malloc(sizeof(t_vector));
	if (!l)
		return (NULL);
	l->x_comp = plane->point->x_co - ray->ray_orig->x_co;
	l->y_comp = plane->point->y_co - ray->ray_orig->y_co;
	l->z_comp = plane->point->z_co - ray->ray_orig->z_co;
	return (l);
}

//Function used to calculate if a plane intersection exists or not
// L - (P - R) is the vector pointing 
// from the origin of the ray to a point on the plane 
int	ray_plane_intersection(t_ray	*ray, t_plane *plane)
{
	t_vector	*vec_ray_dir;	
	t_vector	*plane_vector;
	t_vector	*l;
	t_ip		ip;

	vec_ray_dir = vector_scale_direction(1, ray->ray_dir);
	plane_vector = generate_plane_vector(plane);
	ip.divisor = vector_dot(vec_ray_dir, plane_vector);
	if (ip.divisor == 0)
	{
		free(plane_vector);
		free(vec_ray_dir->dir);
		free(vec_ray_dir);
		return (0);
	}
	l = generate_l(ray, plane);
	ip.t = vector_dot(l, plane_vector) / vector_dot(vec_ray_dir, plane_vector);
	ip.intersection = 0;
	if (ip.t >= 0)
		ip.intersection = 1;
	free(l);
	free(vec_ray_dir->dir);
	free(vec_ray_dir);
	free(plane_vector);
	return (ip.intersection);
}
