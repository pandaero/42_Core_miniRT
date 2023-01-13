//Tests for the functions in src/calculations.c

#include "test.h"
#include <stdio.h>

/*Test for distance_two_points
//From root: cc -Wall -Werror -Wextra test/calculations_main.c src/ *.c libft/libft.a -lm
int	main(void)
{
	t_point	*point1;
	t_point	*point2;
	double	distance;

	point1 = point_coords(1, -4, 3.2);
	point2 = point_coords(3, 1.5, 0);
	distance = distance_two_points(point1, point2);
	printf("Point 1: x:%f y:%f z:%f\n", point1->x_co, point1->y_co, point1->z_co);
	printf("Point 2: x:%f y:%f z:%f\n", point2->x_co, point2->y_co, point2->z_co);
	printf("Distance: %f\n", distance);
	free_point(point1);
	free_point(point2);
	return (0);
}
//*/

/*Test for direction_cross
//From root: cc -Wall -Werror -Wextra test/calculations_main.c src/ *.c test/test.c libft/libft.a -lm
int	main(void)
{
	t_point		*origin;
	t_point		*pointa;
	t_point		*pointb;
	t_vector	*vectora;
	t_vector	*vectorb;
	t_direction	*dira;
	t_direction *dirb;
	t_obj		*obja;
	t_obj		*objb;
	t_obj		*objc;
	t_obj		*objd;

	origin = point_coords(0, 0, 0);
	pointa = point_coords(1, 0, 0);
	pointb = point_coords(0, 1, 0);
	vectora = vector_two_points(origin, pointa);
	vectorb = vector_two_points(origin, pointb);
	objc = object_vector(vectora);
	objd = object_vector(vectorb);
	printf("Source vectors\n");
	object_print(objc);
	object_print(objd);
	free_object(objc);
	free_object(objd);
	dira = direction_cross(vectora->dir, vectorb->dir);
	dirb = direction_cross(vectorb->dir, vectora->dir);
	obja = object_direction(dira);
	objb = object_direction(dirb);
	printf("Cross Product (1, 0, 0) and (0, 1, 0)\n");
	object_print(obja);
	printf("Cross Product (0, 1, 0) and (1, 0, 0)\n");
	object_print(objb);
	free_point(origin);
	free_point(pointa);
	free_point(pointb);
	free_vector(vectora);
	free_vector(vectorb);
	free_direction(dira);
	free_direction(dirb);
	free_object(obja);
	free_object(objb);
	return (0);
}
//*/
