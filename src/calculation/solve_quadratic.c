/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/28 16:57:20 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>

#define REAL_SOLUTIONS_EXISTS 1
#define ONE_OR_INFINITE_SOLUTION_EXISTS 2
#define REAL_SOLUTIONS_NONE 0

/*ax^2 + bx + c* take ownership of x, x[0] states that there is a solution*/
double	*solve_quadratic_real(double a, double b, double c)
{
	double	discriminant;
	double	*x;

	x = (double*)malloc(3 * sizeof(double));
	if (!x)
		return(NULL);
	discriminant = pow(b, 2) - 4 * (a) * (c);
	if (discriminant > 0)
	{
		x[0] = REAL_SOLUTIONS_EXISTS;
		x[1] = (-b + sqrt(discriminant)) / (a * 2);
		x[2] = (-b - sqrt(discriminant)) / (a * 2);
	}
	else if (discriminant == 0)
	{
		x[0] = ONE_OR_INFINITE_SOLUTION_EXISTS;
		x[1] = (-b) / (a * 2);
	}
	else if (discriminant < 0)
	{
		x[0] = REAL_SOLUTIONS_NONE;
	}
	return (x);
}
