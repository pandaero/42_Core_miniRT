/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/11 21:06:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h> 

//Function assigns the two real solutions to the given quadratic.
static void	quad_two(t_quad_sol *quad, t_quad_cof *coeff)
{
	double	denom1;
	double	denom2;

	quad->sol = TWO;
	denom1 = -coeff->linear + sqrt(quad->discr);
	denom2 = -coeff->linear - sqrt(quad->discr);
	quad->first = 2 * coeff->constant / denom1;
	quad->second = 2 * coeff->constant / denom2;
}

//Function solves a quadratic equation in form ax^2+bx+c using Muller's method.
t_quad_sol	solve_quadratic(t_quad_cof coeffs)
{
	t_quad_sol	solution;

	solution.first = 0;
	solution.second = 0;
	solution.discr = pow(coeffs.linear, 2) - 4 * coeffs.squared * \
						coeffs.constant;
	if (solution.discr < 0)
		solution.sol = NO_REAL;
	else
	{
		if (solution.discr >= -DBL_EPSILON && solution.discr <= DBL_EPSILON)
		{
			solution.sol = ONE;
			solution.first = 2 * coeffs.constant / -coeffs.linear;
			return (solution);
		}
		else
			quad_two(&solution, &coeffs);
	}
	return (solution);
}
