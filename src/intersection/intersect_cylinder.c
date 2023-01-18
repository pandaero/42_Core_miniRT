/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/18 20:16:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

int	intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vector	*ray_dir_vec;
	t_vector	*cylinder_orientation_vec;
	t_vector	*w; //Define a vector w equal to the difference of L0 and C: w=L0−C
	t_vector	*cyl_up;
	t_vector	*cyl_down;
	t_point		*C;
	t_point		*H;
	double		a;
	double		b;
	double		c;
	
	cyl_up = vector_scale_direction(cylinder->height / 2, cylinder->orientation);
	cyl_down = vector_scale_direction((-1) * cylinder->height / 2, cylinder->orientation);
	H = point_point_vector(cylinder->centre, cyl_up);
	C = point_point_vector(cylinder->centre, cyl_down);
	// printf("ray point origin: [%f, %f, %f]\n", ray->ray_orig->x_co, ray->ray_orig->y_co, ray->ray_orig->z_co);
	// printf("ray direction: [%f, %f, %f]\n", ray->ray_dir->x_comp, ray->ray_dir->y_comp, ray->ray_dir->z_comp);
	// printf("cylinder_height = %f\n", cylinder->height);
	// printf("orientation: [%f, %f, %f]\n", cylinder->orientation->x_comp, cylinder->orientation->y_comp, cylinder->orientation->z_comp);
	// printf("cylinder center [%f, %f, %f]\n", cylinder->centre->x_co, cylinder->centre->y_co, cylinder->centre->z_co);
	// printf("H - [%f, %f, %f]\n", H->x_co, H->y_co, H->z_co);
	// printf("C - [%f, %f, %f]\n", C->x_co, C->y_co, C->z_co);
	// printf ("r = %f\n", cylinder->radius);
	// exit(0);
	w = vector_two_points(ray->ray_orig, C);
	ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
	cylinder_orientation_vec = vector_scale_direction(1, cylinder->orientation);
	a = vector_dot(ray_dir_vec, ray_dir_vec) \
	- pow(vector_dot(ray_dir_vec, cylinder_orientation_vec), 2);
	b = 2 * (vector_dot(ray_dir_vec, w) - vector_dot(ray_dir_vec, cylinder_orientation_vec) * vector_dot(w, cylinder_orientation_vec));
	c = vector_dot(w, w) - pow(vector_dot(w, cylinder_orientation_vec), 2) - pow(cylinder->radius, 2);
	return (solve_quadratic_real(a, b, c));
}
