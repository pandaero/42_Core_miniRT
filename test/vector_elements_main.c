//Tests for the functions in src/vector_elements.c

#include "test.h"
#include <stdio.h>

//Test for length_two_points
//From root: cc -Wall -Werror -Wextra test/vector_elements_main.c src/*.c -lm
int	main(void)
{
	t_point	*point1;
	t_point	*point2;
	double	distance;

	point1 = point_new(1, -4, 3.2);
	point2 = point_new(3, 1.5, 0);
	distance = length_two_points(point1, point2);
	printf("Point 1: x:%f y:%f z:%f\n", point1->x_co, point1->y_co, point1->z_co);
	printf("Point 2: x:%f y:%f z:%f\n", point2->x_co, point2->y_co, point2->z_co);
	printf("Distance: %f\n", distance);
	free_point(point1);
	free_point(point2);
	return (0);
}
