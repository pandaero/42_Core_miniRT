//Tests for the functions in screen.c

#include "test.h"
#include <stdio.h>

/*Test for screen_up
//From root: cc -Wall -Werror -Wextra test/screen_main.c src/ *.c test/test.c libft/libft.a -lm
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

//*Test for screen_pixel_centres
//From root: cc -Wall -Werror -Wextra test/screen_main.c src/ *.c test/test.c libft/libft.a -lm
int	main(void)
{
	t_screen	*screen;
	t_camera	*cam;
	t_point		*cam_loc;
	t_point		*cam_point;
	t_direction	*cam_view_dir;
	int			width;
	int			height;
	int			hfov;

	width = 200;
	height = 100;
	hfov = 53;
	cam_loc = point_coords(0, 0, 0);
	cam_point = point_coords(0, 1, 0);
	cam_view_dir = direction_two_points(cam_loc, cam_point);
	cam = camera_input(cam_loc, cam_view_dir, hfov);
	screen = screen_camera(width, height, cam);

	// Print scene elements
	printf("Set-Up: \n");
	// Print camera point, direction, and hfov.
	t_obj	*obj_cam = object_camera(cam);
	object_print(obj_cam);
	// Print screen characteristics
	t_obj	*obj_screen = object_screen(screen);
	object_print(obj_screen);

	printf("Screen Centre: (%f, %f, %f)\n", screen->pts->centre->x_co, screen->pts->centre->y_co, screen->pts->centre->z_co);
	printf("Screen Corner: (%f, %f, %f)\n", screen->pts->tl_corner->x_co, screen->pts->tl_corner->y_co, screen->pts->tl_corner->z_co);
	printf("Screen Top Corner Vec: (%f, %f, %f)\n", screen->vecs->vec_corner_up->x_comp, screen->vecs->vec_corner_up->y_comp, screen->vecs->vec_corner_up->z_comp);
	printf("Screen Left Corner Vec: (%f, %f, %f)\n", screen->vecs->vec_corner_left->x_comp, screen->vecs->vec_corner_left->y_comp, screen->vecs->vec_corner_left->z_comp);
	printf("Arr [0, 0]: (%f, %f, %f)\n", screen->pts->px_coords[0][0]->x_co, screen->pts->px_coords[0][0]->y_co, screen->pts->px_coords[0][0]->z_co);
	printf("Arr [0, w - 1]: (%f, %f, %f)\n", screen->pts->px_coords[0][width - 1]->x_co, screen->pts->px_coords[0][width - 1]->y_co, screen->pts->px_coords[0][width - 1]->z_co);
	printf("Arr [h - 1, 0]: (%f, %f, %f)\n", screen->pts->px_coords[height - 1][0]->x_co, screen->pts->px_coords[height - 1][0]->y_co, screen->pts->px_coords[height - 1][0]->z_co);
	printf("Arr [h - 1, w - 1]: (%f, %f, %f)\n", screen->pts->px_coords[height - 1][width - 1]->x_co, screen->pts->px_coords[height - 1][width - 1]->y_co, screen->pts->px_coords[height - 1][width - 1]->z_co);
	
	free_point(cam_loc);
	free_point(cam_point);
	free_direction(cam_view_dir);
	free_object(obj_cam);
	free_object(obj_screen);
	return (0);
}
//*/
