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
//From root: cc -Wall -Werror -Wextra test/screen_main.c src/object/* src/calculation/* src/elements/* src/memory/* src/program/* test/test.c libft/libft.a -lm
int	main(void)
{
	int			width = 4;
	int			height = 3;
	int			hfov = 90;
	t_point		*cam_loc = point_coords(0, 0, 0);
	t_direction	*cam_view_dir = direction_components(0, 1, 0);
	t_camera	*cam = camera_input(cam_loc, cam_view_dir, hfov);
	free_point(cam_loc);
	free_direction(cam_view_dir);
	t_screen	*screen = screen_camera(width, height, cam);

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
	printf("Point [0, 0]: (%f, %f, %f)\n", screen->pixels[0][0]->point->x_co, screen->pixels[0][0]->point->y_co, screen->pixels[0][0]->point->z_co);
	printf("Point [0, w - 1]: (%f, %f, %f)\n", screen->pixels[0][width - 1]->point->x_co, screen->pixels[0][width - 1]->point->y_co, screen->pixels[0][width - 1]->point->z_co);
	printf("Point [h - 1, 0]: (%f, %f, %f)\n", screen->pixels[height - 1][0]->point->x_co, screen->pixels[height - 1][0]->point->y_co, screen->pixels[height - 1][0]->point->z_co);
	printf("Point [h - 1, w - 1]: (%f, %f, %f)\n", screen->pixels[height - 1][width - 1]->point->x_co, screen->pixels[height - 1][width - 1]->point->y_co, screen->pixels[height - 1][width - 1]->point->z_co);
	printf("Full screen test:\n");
	int i = 0;
	int	j;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (screen->pixels[i][j])
				printf("o");
			else
				printf("x");
			j++;
		}
		printf("\n");
		i++;
	}
	free_object(obj_cam);
	free_object(obj_screen);
	return (0);
}
//*/
