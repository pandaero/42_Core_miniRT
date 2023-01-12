/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:04:22 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 17:13:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}t_point;

double	length_two_points(t_point *point_one, t_point *point_two);
t_point	*direction_two_points(t_point *start, t_point *end);
double	dot(t_point *first, t_point *second);
t_point *substract_vectors(t_point *V, t_point *W);
void 	populate_point(t_point *to_fill, double x, double y, double z);