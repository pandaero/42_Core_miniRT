//Tests for the functions in src/list.c

#include "test.h"
#include <stdio.h>

/*Test for list_create
//From root: cc -Wall -Werror -Wextra test/list_main.c src/*.c test/test.c libft/libft.a -lm
int	main(void)
{
	t_program	*program;
	t_objlist	*objects;
	t_obj		*p1;
	t_obj		*p2;
	t_obj		*d;
	t_obj		*v;
	t_obj		*r;
	t_point		*point1;
	t_point		*point2;
	t_direction	*direction;
	t_vector	*vector;
	t_ray		*ray;

	program = program_create();
	if (!program)
		return (error_exit(program, "PROGRAM"));
	objects = list_create(program);
	if (!objects)
		return (error_exit(program, "LIST"));
	point1 = point_coords(1, -4, 3.2);
	if (!point1)
		return (error_exit(program, "POINT"));
	p1 = object_point(point1);
	if (!p1)
		return (error_exit(program, "OBJECT"));
	point2 = point_coords(3, 1.5, 0);
	if (!point2)
		return (error_exit(program, "POINT"));
	p2 = object_point(point2);
	if (!p2)
		return (error_exit(program, "OBJECT"));
	direction = direction_two_points(point1, point2);
	if (!direction)
		return (error_exit(program, "DIRECTION"));
	d = object_direction(direction);
	if (!d)
		return (error_exit(program, "OBJECT"));
	vector = vector_start_mag_dir(point1, 5, direction);
	if (!vector)
		return (error_exit(program, "VECTOR"));
	v = object_vector(vector);
	if (!v)
		return (error_exit(program, "OBJECT"));
	ray = ray_vector(vector);
	if (!ray)
		return (error_exit(program, "RAY"));
	r = object_ray(ray);
	if (!r)
		return (error_exit(program, "OBJECT"));
	list_add_object(objects, p1);
	list_add_object(objects, p2);
	list_add_object(objects, d);
	list_add_object(objects, v);
	list_add_object(objects, r);
	// object_print(p1);
	// object_print(p2);
	// object_print(d);
	// object_print(v);
	// object_print(r);
	list_print(program->first_objlist);
	free_program(program);
	return (0);
}
//*/
