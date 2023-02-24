/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/24 06:43:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

//for tests
// #include <stdio.h>

#define TWO_SOLUTIONS 1
#define ONE_SOLUTION 2
#define NO_REAL_SOLUTION 0
#define A 0
#define B 1
#define C 2

static int	invalid_input(double a)
{
	if (a == 0)
	{
		write(2, "Invalid quadratic equation input\n", 34);
		return (1);
	}
	return (0);
}

static void	calclulate_for_two(double *coefficient, \
double discriminant, double *x)
{
	x[0] = TWO_SOLUTIONS;
	x[1] = (-coefficient[B] + sqrt(discriminant)) / (coefficient[A] * 2);
	x[2] = (-coefficient[B] - sqrt(discriminant)) / (coefficient[A] * 2);
}

static void	calclulate_for_one(double *coefficient, double *x)
{
		x[0] = ONE_SOLUTION;
		x[1] = (-coefficient[B]) / (coefficient[A] * 2);
		x[2] = x[1];
}

/*ax^2 + bx + c* take ownership of x, x[0] states that there is a solution*/
double	*solve_quadratic_real(double *coefficient)
{
	double	discriminant;
	double	*x;

	if (invalid_input(coefficient[A]))
		return (NULL);
	x = (double *)malloc(3 * sizeof(double));
	if (!x)
		return (NULL);
	discriminant = pow(coefficient[B], 2) - \
	4 * (coefficient[A]) * (coefficient[C]);
	if (discriminant > 0)
		calclulate_for_two(coefficient, discriminant, x);
	else if (discriminant == 0)
		calclulate_for_one(coefficient, x);
	else if (discriminant < 0)
	{
		x[0] = NO_REAL_SOLUTION;
		x[1] = 0;
		x[2] = 0;
	}
	return (x);
}
