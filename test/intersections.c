//Tests for intersections on a window.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit
// Using minilibx-linux
// From root: cc test/intersections.c src/calculation/* src/elements/* src/intersection/* src/memory/* src/program/* libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm
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
	t_point		*point_on_plane;
	t_direction *plane_norm;
	t_plane		*plane;
	int			pixel;
	int			i;
	int			j;

	point_on_plane = point_coords(0, -20 ,0);
	plane_norm = direction_components(0, 1, 0);
	plane = plane_col_point_normal_dir(GREEN, point_on_plane, plane_norm);
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mlxdata->mlx = mlx_init();
	mlxdata->window = mlx_new_window(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT, "Intersection Test");
	imdt->image = mlx_new_image(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp, \
									   &imdt->line_len, &imdt->endian);
	ambient = ambient_input(WHITE, 0.4);
	cam_loc = point_coords(0, 0, 0);
	cam_point = point_coords(0, 1, 0);
	cam_view_dir = direction_two_points(cam_loc, cam_point);
	cam = camera_input(cam_loc, cam_view_dir, 90);
	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, cam);
	sphere_centre = point_coords(10, 10, 0);
	sphere = sphere_col_centre_radius(0x00FF5555, sphere_centre, 5);
	free_point(cam_loc);
	free_point(cam_point);
	free_direction(cam_view_dir);
	free_point(sphere_centre);
	i = 0;
	while(i < WIN_HEIGHT)
	{
		j = 0;
		while(j < WIN_WIDTH)
		{
			ray = ray_two_points(cam->location, screen->pixels[i][j]->point);
			pixel = ray_sphere_intersection(ray, sphere);
			// pixel = ray_plane_intersection(ray, plane);
			if (pixel == 0)
				quick_put_pixel(imdt, j, i, ambient->ratio * ambient->colour);
			else
				quick_put_pixel(imdt, j, i, colour_ambient((sphere->colour), ambient));
			free(ray->ray_dir);
			free(ray->ray_orig);
			free(ray);
			j++;
		}
		i++;
	}
	//Sphere colour in projection
	printf("0x%08X\n", (unsigned int) colour_ambient((sphere->colour), ambient));
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->window, imdt->image, 0, 0);
	mlx_hook(mlxdata->window, 17, NO_EVENT, closing, mlxdata);
	mlx_hook(mlxdata->window, 3, KEY_RELEASE, keys, mlxdata);
	mlx_loop(mlxdata->mlx);
	free(plane->point);
	free(plane->normal);
	free(plane);
	free_camera(cam);
	free_screen(screen);
	free_ambient(ambient);
	free(mlxdata);
	free(imdt);
	return (0);
}
