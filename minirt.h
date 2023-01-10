/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:16:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 18:50:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"

//Typedef describes a point in 3D space.
typedef struct s_point
{
	double	x_co;
	double	y_co;
	double	z_co;
}			t_point;

//Typedef describes a direction in 3D space.
typedef struct s_direction
{
	double	x_norm;
	double	y_norm;
	double	z_norm;
}			t_direction;

//Typedef describes a vector and its properties in 3D space.
typedef struct s_vector
{
	double		mag;
	t_direction	*dir;
	t_point		*start;
	t_point		*end;
}				t_vector;

//Typedef describes a ray in 3D space.
typedef struct s_ray
{
	t_point		*ray_orig;
	t_direction	*ray_dir;
}				t_ray;

// ==================================== CREATION ===============================
//Function creates a new defined point object.
t_point		*point_new(double x_coord, double y_coord, double z_coord);
//Function copies a defined point object's properties to a new one.
t_point		*point_copy(t_point *point);
//Function creates a defined direction object from two points.
t_direction	*direction_two_points(t_point *start, t_point *end);
//Function creates a defined direction object from a vector.
t_direction	*direction_vector(t_vector *vector);
//Function copies a defined direction object's properties to a new one.
t_direction	*direction_copy(t_direction *direction);
//Function creates a new defined vector object from two points.
t_vector	*vector_two_points(t_point *start, t_point *end);
//Function creates a new defined vector object from starting point, mag, dir.
t_vector	*vector_start_mag_dir(t_point *start, double mag, t_direction *dir);
//Function copies a defined vector object's properties to a new one.
t_vector	*vector_copy(t_vector *vector);

// ==================================== DELETION ===============================
//Function frees all the allocations belonging to a point object.
void		free_point(t_point *point);
//Function frees all the allocations belonging to a direction object.
void		free_direction(t_direction *direction);
//Function frees all the allocations belonging to a vector object.
void		free_vector(t_vector *vector);

// =================================== OPERATIONS ==============================
//Function works out the length/distance between two points.
double		length_two_points(t_point *point_one, t_point *point_two);

#endif
