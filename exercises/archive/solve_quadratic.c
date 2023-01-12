/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere_working.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:32:02 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 14:06:18 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define A 2
#define B 1
#define C -1

/*ax^2 + bx + c*/
void solveQuadratic(const double *a, const double *b, const double *c)
{
	double discriminant;
	double x0;
	double x1;

	printf("a:b:c %f:%f:%f", *a, *b, *c);
	discriminant = pow(*b,2) - 4 * (*a) * (*c);
	printf("disc: %f\n", discriminant);
	if (discriminant >= 0)
	{
		x0 = (-(*b) + sqrt(discriminant)) / ((*a) * 2);
		printf("x0 = %f\n", x0);
		x1 = (-(*b) - sqrt(discriminant)) / ((*a) * 2);
		printf("x1 = %f\n", x1);
	}
	if (discriminant < 0)
	{
		printf("no_real_solution\n");
	}
}

// int main(void)
// {
// 	solveQuadratic(A, B, C);
// }