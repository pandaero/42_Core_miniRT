//Tests for the functions in screen.c

#include "test.h"
#include <stdio.h>

/*Test for screen_up
//From root: cc -Wall -Werror -Wextra test/screen_main.c src/*.c test/test.c libft/libft.a -lm
int	main(void)
{
	t_camera	*camera;
	t_point		*origin;
	t_point		*facing;
	t_direction	*scr_up;

	origin = point_coords(0, 0, 0);
	facing = point_coords(0, -1, 1);
	camera = camera_create();
	camera->location = point_coords(0, -5, 0);
	camera->view_dir = direction_two_points(origin, facing);
	camera->horiz_fov = radians_degrees(90);
	printf("Cam: loc:(%f, %f, %f), dir:(%f, %f, %f), hfov:%f\n", camera->location->x_co, camera->location->y_co, camera->location->z_co, camera->view_dir->x_comp, camera->view_dir->y_comp, camera->view_dir->z_comp, camera->horiz_fov);
	scr_up = screen_up(camera);
	printf("Screen-up: dir:(%f, %f, %f)\n", scr_up->x_comp, scr_up->y_comp, scr_up->z_comp);
	free_point(origin);
	free_point(facing);
	free_direction(scr_up);
	free_camera(camera);
	return (0);
}
//*/
