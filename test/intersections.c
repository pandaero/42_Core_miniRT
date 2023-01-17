//Tests for intersections on a window.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit
// Using minilibx-linux
// From root: cc test/test.c test/intersections.c src/calculation/* src/elements/* src/intersection/* src/memory/* src/program/* src/object/* libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
// From folder: cc intersection.c ../src/*.c ../src/intersections/*.c ../minilibx-linux/libmlx_Linux.a ../libft/libft.a -lX11 -lXext -lm

#include "./test.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BLACK
# define BLACK 0x00000000
#endif
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#ifndef WHITE
# define WHITE 0x00FFFFFF
#endif

//Function handles the window closing action.
int	closing(t_mlxdata *mlxvars)
{
	printf("Exiting...\n");
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	exit(0);
}

//Function handles key releases.
int	keys(int key, t_mlxdata *mlxvars)
{
	if (key == ESCAPE)
		closing(mlxvars);
	return (0);
}

//Test program for a single sphere in view.
int	main(void)
{
	t_mlxdata	*mlxdata;
	t_imgdata	*imdt;
	t_direction	*ray_direc;
	t_ray		*ray;
	int			pixel;
	int			i;
	int			j;

	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mlxdata->mlx = mlx_init();
	mlxdata->window = mlx_new_window(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT, "Intersection Test");
	imdt->image = mlx_new_image(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp, \
									   &imdt->line_len, &imdt->endian);
	// Scene and lighting
	// t_ambient	*ambient = ambient_input(RED, 0.4);
	t_point		*cam_loc = point_coords(0, 0, 0);
	t_direction	*cam_dir = direction_components(0, 5, 0);
	t_camera	*cam = camera_input(cam_loc, cam_dir, 90);
	t_obj		*obj_cam = object_camera(cam);
	object_print(obj_cam);
	free(obj_cam);
	t_screen	*screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, cam);
	t_obj		*obj_scr = object_screen(screen);
	object_print(obj_scr);
	free(obj_scr);
	free_point(cam_loc);
	free_direction(cam_dir);
	// Plane
	// t_point		*point_on_plane = point_coords(0, 100, 0);
	// t_direction	*plane_norm = direction_components(0, 1, 0);
	// t_plane		*plane = plane_col_point_normal_dir(0x00FF5555, point_on_plane, plane_norm);
	// free_point(point_on_plane);
	// free_direction(plane_norm);
	// Sphere
	t_point		*sphere_centre = point_coords(0, 1000, 0);
	t_sphere	*sphere = sphere_col_centre_radius(0x00FF5555, sphere_centre, 100);
	free_point(sphere_centre);
	// Pre-Screen Tests
	i = 0;
	while(i < WIN_HEIGHT)
	{
		j = 0;
		while(j < WIN_WIDTH)
		{
			ray_direc = direction_two_points(cam->location, screen->pixels[i][j]->point);
			ray = ray_start_dir(screen->pixels[i][j]->point, ray_direc);
			free_direction(ray_direc);
			pixel = ray_sphere_intersection(ray, sphere);
			// pixel = intersection_ray_plane(ray, plane);
			if (pixel == 0)
				quick_put_pixel(imdt, j, i, BLACK);
			else
				quick_put_pixel(imdt, j, i, WHITE);
			free_ray(ray);
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
	// free_plane(plane);
	free_sphere(sphere);
	free(mlxdata);
	free(imdt);
	return (0);
}
