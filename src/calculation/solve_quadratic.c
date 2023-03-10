/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/10 14:02:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h> 

//Function assigns the two real solutions to the given quadratic.
static void	quad_two(t_quad_sol *quad, double a, double b, double c)
{
	double	denom1;
	double	denom2;

	denom1 = -b + sqrt(pow(b, 2) - 4 * a * c);
	denom2 = -b - sqrt(pow(b, 2) - 4 * a * c); 
	quad->sol = TWO;
	quad->first = 2 * c / denom1;
	quad->second = 2 * c / denom2;
}

//Function solves a quadratic equation in form ax^2+bx+c using Muller's method.
t_quad_sol	solve_quadratic(double a, double b, double c)
{
	t_quad_sol	solution;
	double		discr;

	solution.first = 0;
	solution.second = 0;
	discr = pow(b, 2) - 4 * a * c;
	if (discr < DBL_EPSILON)
		solution.sol = NO_REAL;
	else
	{
		if (discr >= -DBL_EPSILON && discr <= DBL_EPSILON)
		{
			solution.sol = ONE;
			solution.first = 2 * c / -b;
			return (solution);
		}
		else
		{
			quad_two(&solution, a, b, c);
			return (solution);
		}
	}
	return (solution);
}
