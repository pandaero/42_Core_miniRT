/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:04:22 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 15:40:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include <stdlib.h>
# include <stdio.h>s_Vector3
# include <math.h>

typedef struct s_Vector3
{
	double	x;
	double	y;
	double	z;
}t_Vector3;

// typedef struct s_intersect
// {
//     bool    state;
//     t_point    *point;
// }            t_intersect;

// typedef struct s_point
// {
// 	double		x_co;
// 	double		y_co;
// 	double		z_co;
// }				t_point;

double	length_two_points_local(t_Vector3 *point_one, t_Vector3 *point_two);
t_Vector3	*direction_two_points_local(t_Vector3 *start, t_Vector3 *end);
double	dot(t_Vector3 *first, t_Vector3 *second);
t_Vector3	*substract_vectors(t_Vector3 *V, t_Vector3 *W);
void	populate_point(t_Vector3 *to_fill, double x, double y, double z);
t_Vector3	*scalar_times_vector(double scalar, t_Vector3 *vector);
void solveQuadratic(double a, double b, double c);

#endif