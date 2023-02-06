/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/06 20:26:39 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define TWO_SOLUTIONS 1
#define ONE_SOLUTION 2
#define NO_REAL_SOLUTION 0

static int invalid_input(double a)
{
	if (a == 0)
	{
		write(2, "Invalid quadratic equation input\n", 34);
		return (1);
	}
	return(0);
}

/*ax^2 + bx + c* take ownership of x, x[0] states that there is a solution*/
double	*solve_quadratic_real(double a, double b, double c)
{
	double	discriminant;
	double	*x;

	if (invalid_input(a))
		return(NULL);
	x = (double*)malloc(3 * sizeof(double));
	if (!x)
		return(NULL);
	discriminant = pow(b, 2) - 4 * (a) * (c);
	if (discriminant > 0)
	{
		x[0] = TWO_SOLUTIONS;
		x[1] = (-b + sqrt(discriminant)) / (a * 2);
		x[2] = (-b - sqrt(discriminant)) / (a * 2);
	}
	else if (discriminant == 0)
	{
		x[0] = ONE_SOLUTION;
		x[1] = (-b) / (a * 2);
		x[2] = x[1];
	}
	else if (discriminant < 0)
	{
		x[0] = NO_REAL_SOLUTION;
		x[1] = 0;
		x[2] = 0;
		x[3] = 0;
	}
	return (x);
}
