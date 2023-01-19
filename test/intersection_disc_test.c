// Tests for intersections on a window.
//  Using minilibx-opengl-20191021
//  From root: cc -framework OpenGL -framework AppKit
//  Using minilibx-linux
//  From root: cc test/test.c test/intersection_disc_test.c src/calculation/* src/elements/* src/intersection/* src/memory/* src/program/* src/object/* libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
//  From folder: cc intersection.c ../src/*.c ../src/intersections/*.c ../minilibx-linux/libmlx_Linux.a ../libft/libft.a -lX11 -lXext -lm
//  From root with fsanitize: cc -g -fsanitize=address test/test.c test/intersections.c src/calculation/* src/elements/* src/intersection/* src/memory/* src/program/* src/object/* libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm

#include "./test.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BLACK
#define BLACK 0x00000000
#endif
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#ifndef WHITE
#define WHITE 0x00FFFFFF
#endif

// Function handles the window closing action.
int closing(t_mlxdata *mlxvars)
{
	printf("Exiting...\n");
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	exit(0);
}

// Function handles key releases.
int keys(int key, t_mlxdata *mlxvars)
{
	if (key == ESCAPE)
		closing(mlxvars);
	return (0);
}


#define RADIUS 10
// Test program for a single sphere in view.
int main(void)
{
	// t_intersect *intersection;
	t_mlxdata *mlxdata;
	t_imgdata *imdt;
	t_direction *ray_direc;
	t_ray *ray;
	int i;
	int j;

	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mlxdata->mlx = mlx_init();
	mlxdata->window = mlx_new_window(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT, "Intersection Test");
	imdt->image = mlx_new_image(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp,
									  &imdt->line_len, &imdt->endian);
	// Scene and lighting
	t_ambient *ambient = ambient_input(RED, 0.4);
	t_point *cam_loc = point_coords(0, 0, 0);
	t_direction *cam_dir = direction_components(0, 1, 0);
	t_camera *cam = camera_input(cam_loc, cam_dir, 90);
	t_obj *obj_cam = object_camera(cam);
	object_print(obj_cam);
	free(obj_cam);
	t_screen *screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, cam);
	t_obj *obj_scr = object_screen(screen);
	object_print(obj_scr);
	free(obj_scr);
	free_point(cam_loc);
	free_direction(cam_dir);
	// Disc
	t_point *point_on_disc = point_coords(0, 0, 10);
	t_direction *disc_norm = direction_components(2, 1, 1);
	t_disc *disc = disc_col_point_normal_dir(0x000055FF, point_on_disc, disc_norm, RADIUS);
	t_obj *obj_disc = object_disc(disc);
	object_print(obj_disc);
	free(obj_disc);
	free_point(point_on_disc);
	free_direction(disc_norm);
	// Pre-Screen Tests
	i = 0;
	int pixel;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			ray_direc = direction_two_points(cam->location, screen->pixels[i][j]->point);
			ray = ray_start_dir(screen->pixels[i][j]->point, ray_direc);
			free_direction(ray_direc);
			// intersection = ray_sphere_intersection(ray, sphere);
			// intersection = intersection_ray_disc(ray, disc);
			pixel = 0;
			intersect_ray_disc(ray, disc);
			return (printf("Exit success\n"));
			if (pixel == 0)
			{
				quick_put_pixel(imdt, j, i, ambient->ratio * ambient->colour);
			}
			else
			{
				quick_put_pixel(imdt, j, i, colour_ambient(WHITE, ambient));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->window, imdt->image, 0, 0);
	mlx_hook(mlxdata->window, 17, NO_EVENT, closing, mlxdata);
	mlx_hook(mlxdata->window, 3, KEY_RELEASE, keys, mlxdata);
	mlx_loop(mlxdata->mlx);
	// free_ambient(ambient);
	free_camera(cam);
	free_screen(screen);
	// free_disc(disc);
	// free_sphere(sphere);
	free(mlxdata);
	free(imdt);
	return (0);
}
