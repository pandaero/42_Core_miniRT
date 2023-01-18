/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/18 19:12:00 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>

#define A 2
#define B 1
#define C -1

/*ax^2 + bx + c*/
int	solve_quadratic_real(double a, double b, double c)
{
	double	discriminant;
	double	x0;
	double	x1;

	// printf("a:b:c %f:%f:%f", a, b, c);
	discriminant = pow(b,2) - 4 * (a) * (c);
	// printf("disc: %f\n", discriminant);
	if (discriminant >= 0)
	{
		x0 = (-b + sqrt(discriminant)) / (a * 2);
		// printf("x0 = %f\n", x0);
		x1 = (-b - sqrt(discriminant)) / (a * 2);
		// printf("x1 = %f\n", x1);
		return (1);
	}
	else if (discriminant < 0)
	{
		// printf("no_real_solution\n");
		return (0);
	}
}

// int main(void)
// {
// 	solve_quadratic_real(A, B, C);
// }