//Tests for intersections on a window.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c -lmlx
// Using minilibx-linux
// From root: cc test/intersections.c src/*.c libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
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
	t_screen	*screen;
	t_camera	*cam;
	t_point		*cam_loc;
	t_point		*cam_point;
	t_direction	*cam_view_dir;
	t_ray		*ray;
	t_point		*sphere_centre;
	t_sphere	*sphere;
	t_ambient	*ambient;
	t_mlxdata	*mlxdata;
	t_imgdata	*imdt;
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
	ambient = ambient_input(RED, 1);
	cam_loc = point_coords(0, 0, 0);
	cam_point = point_coords(0, 1, 0);
	cam_view_dir = direction_two_points(cam_loc, cam_point);
	cam = camera_input(cam_loc, cam_view_dir, 90);
	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, cam);
	sphere_centre = point_coords(10, 20, 0);
	sphere = sphere_col_centre_radius(BLACK, sphere_centre, 5);
	free_point(cam_loc);
	free_point(cam_point);
	free_direction(cam_view_dir);
	free_point(sphere_centre);

	// printf("[0, 0]: (%f, %f, %f)\n", screen->pts->px_coords[0][0]);
	// printf("[0, w]: (%f, %f, %f)\n", screen->pts->px_coords[0][WIN_WIDTH - 1]);
	// printf("[h, 0]: (%f, %f, %f)\n", screen->pts->px_coords[WIN_HEIGHT - 1][0]);
	// printf("[h, w]: (%f, %f, %f)\n", screen->pts->px_coords[WIN_HEIGHT - 1][WIN_WIDTH - 1]);
	
	// quick_put_pixel(imdt, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0x00FF00FF);
	//*
	i = 0;
	while(i < WIN_HEIGHT)
	{
		j = 0;
		while(j < WIN_WIDTH)
		{
			ray = ray_two_points(cam->location, screen->pts->px_coords[i][j]);
			pixel = ray_sphere_intersection(ray, sphere);
			if (pixel == 0)
				quick_put_pixel(imdt, j, i, ambient->ratio * ambient->colour);
			else if (pixel == 1)
				quick_put_pixel(imdt, j, i, BLACK);
			free(ray->ray_dir);
			free(ray->ray_orig);
			free(ray);
			// free(pixel->point);
			// free(pixel);
			j++;
		}
		// write(1, "\n", 1);
		i++;
	}
	//Sphere colour in projection
	printf("0x%08X\n", (unsigned int) colour_ambient((sphere->colour), ambient));
	//*/
	// ray_sphere_intersection(ray);
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->window, imdt->image, 0, 0);
	mlx_hook(mlxdata->window, 17, NO_EVENT, closing, mlxdata);
	mlx_hook(mlxdata->window, 3, KEY_RELEASE, keys, mlxdata);
	mlx_loop(mlxdata->mlx);
	free_camera(cam);
	free_screen(screen);
	free_ambient(ambient);
	free(mlxdata);
	free(imdt);
	return (0);
}
