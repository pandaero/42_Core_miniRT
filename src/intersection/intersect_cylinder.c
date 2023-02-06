/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/06 19:01:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

double *solve_quadratic(double a, double b, double c)
{
	double *result;
	double discriminant;

	result = (double*)malloc(3 * sizeof(double));
	discriminant = pow(b, 2) - (4 * a * c);
	if (discriminant > 0)
	{
		result[0] = 1;
		
	}
}

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{

}
