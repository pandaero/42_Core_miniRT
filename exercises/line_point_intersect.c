/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_point_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:06 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 14:14:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks if the given point x1 and y2 intersects with the function a*x = y
Simple introduction to the concept of intersection. This implementation would be too resource heavy.
*/

#include <stdio.h>
#include <stdlib.h>

#define a 2
#define coordinate_x 1
#define coordinate_y 2

int	main(void)
{
	int		x1;
	int		y2;
	int		x, y;

	x1 = coordinate_x;
	y2 = coordinate_y;
	x = 0;
	while (x < 10)
	{
		if (x1 * a == y2)
		{
			printf("It intesects\n");
			return(0);
		}
		x++;
	}
	printf("It does not intersect\n");
	return (0);
}
