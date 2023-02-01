//Tests for functions in colour.c

#include "test.h"
#include <stdio.h>

//Multi-test
//From root:
int	main(void)
{
	t_objlist	*objlist = list_create();
	t_ambient	*ambient = ambient_input((t_colour)0x0000FF00, 0.5);
	t_diffuse	*diffuse = diffuse_line("L 0,-0,0 0.7");
	t_plane		*plane = plane_line("pl 0,100,0 0,1,0 0,0,100");

	t_obj		*obj_amb = object_ambient(ambient);
	t_obj		*obj_diff = object_diffuse(diffuse);
	t_obj		*obj_plane = object_plane(plane);

	list_add_object(objlist, obj_amb);
	list_add_object(objlist, obj_diff);
	list_add_object(objlist, obj_plane);

	t_point		*origin = point_coords(0,0,0);
	t_point		*ray_dir = point_coords(0,1,0);
	t_ray		*ray = ray_two_points(origin, ray_dir);

	t_intersect	*intersect = intersection_ray_plane(objlist, ray, obj_plane);
	t_colour	colour = colour_lighting(objlist, intersect);

	list_print(objlist);
	printf("Colour at plane-y-axis intersection: %08X\n", colour);
	
	free_point(origin);
	free_point(ray_dir);
	free_ray(ray);
	free_list(objlist);
	return (0);
}
