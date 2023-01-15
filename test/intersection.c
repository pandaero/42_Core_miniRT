/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:13:23 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 19:39:2 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Exercise to open a window and record events.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c -lmlx
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c minilibx_opengl_20191021/libmlx.a
// Using minilibx-linux
// From root: cc exercises/mlx/window_listen.c minilibx-linux/libmlx_Linux.a -lX11 -lXext
// From folder: cc intersection.c ../src/*.c ../src/intersections/*.c ../minilibx-linux/libmlx_Linux.a ../libft/libft.a -lX11 -lXext -lm
// From folder nomlx: cc intersection.c ../src/*.c ../src/intersections/*.c ../libft/libft.a -lX11 -lXext -lm

#if defined (__APPLE__)
# include "../apple_mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"
#endif
#if defined (__linux__)
# include "../include/linux_mlx.h"
# include "../minilibx-linux/mlx.h"
#endif

#include "./test.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BLACK 0x00FF0000
#define WHITE 0x0000FF00
#define WIDTH 50
#define HEIGHT 50

// typedef struct s_Vector3
// {
// 	double	x;
// 	double	y;
// 	double	z;
// }t_Vector3;

typedef struct s_imgdata
{
    void    *image;
    char    *address;
    int     bits_pp;
    int     line_len;
    int     endian;
}            t_imgdata;

typedef struct s_mlxdata
{
    void    *mlx;
    void    *mlxwindow;
}            t_mlxdata;

//Function places a pixel in an image more quickly than with the pixel_put fn.

void    quick_put_pixel(t_imgdata *data, int x, int y, int color)
{
    char    *dest;

    dest = 0;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
		printf("Printing pix: [%d, %d], w:%d, h:%d\n", x, y, WIDTH, HEIGHT);
        dest = data->address + (y * data->line_len + x * (data->bits_pp / 8));
		printf("Got address\n");
        *(unsigned int *)dest = color;
		printf("Assigned colour\n");
    }
}


int	closing(t_mlxdata *mlxvars)
{
	printf("Exiting...\n");
	mlx_destroy_window(mlxvars->mlx, mlxvars->mlxwindow);
	exit(0);
}

int	keys(int key, t_mlxdata *mlxvars)
{
	if (key == ESCAPE)
		closing(mlxvars);
	else
		printf("Key released: %d\n", key);
	return (0);
}

int	main(void)
{
	t_screen	*screen;
	t_camera	*cam;
	t_point		*cam_loc;
	t_point		*cam_point;
	t_direction	*cam_view_dir;
	t_ray		*ray;
	int			pixel;
	int			hfov;
	int			i;
	int			j;
	t_mlxdata    *mlxdata;
	t_imgdata    *imdt;

	hfov = 53;
	cam_loc = point_coords(0, 0, 0);
	cam_point = point_coords(0, 1, 0);
	cam_view_dir = direction_two_points(cam_loc, cam_point);
	cam = camera_input(cam_loc, cam_view_dir, hfov);
	screen = screen_camera(WIDTH, HEIGHT, cam);
	printf("Set-Up: \n");
	t_obj	*obj_cam = object_camera(cam);
	t_obj	*obj_screen = object_screen(screen);
	mlxdata = (t_mlxdata *)malloc(sizeof(t_mlxdata));
    imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
    mlxdata->mlx = mlx_init();
    mlxdata->mlxwindow = mlx_new_window(mlxdata->mlx, WIDTH, HEIGHT, "Intersection Test");
    imdt->image = mlx_new_image(mlxdata->mlx, WIDTH, HEIGHT);
    imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp, \
                                       &imdt->line_len, &imdt->endian);
	printf("[0, 0]: (%f, %f, %f)\n", obj_screen->screen->pts->px_coords[0][0]);
	printf("[0, w]: (%f, %f, %f)\n", obj_screen->screen->pts->px_coords[0][WIDTH - 1]);
	printf("[h, 0]: (%f, %f, %f)\n", obj_screen->screen->pts->px_coords[HEIGHT - 1][0]);
	printf("[h, w]: (%f, %f, %f)\n", obj_screen->screen->pts->px_coords[HEIGHT - 1][WIDTH - 1]);
	i = 0;
	while(i < HEIGHT)
	{
		j = 0;
		while(j < WIDTH)
		{
			ray = ray_two_points(obj_cam->camera->location, obj_screen->screen->pts->px_coords[i][j]);
			pixel = ray_sphere_intersection(ray);
			// return(printf("seg check\n"));
			if(pixel == 0)
			{
				quick_put_pixel(imdt->image, j, i, 0x00FF0000);
				// mlx_pixel_put(mlxdata->mlx, mlxdata->mlxwindow, i, j, BLACK);
				write(1, "0", 1);
			}
			else if (pixel == 1)
			{
				// mlx_pixel_put(mlxdata->mlx, mlxdata->mlxwindow, i, j, WHITE);
				write(1, "1", 1);
				quick_put_pixel(imdt->image, j, i, 0x0000FF00);
			}
			free(ray);
			// free(pixel->point);
			// free(pixel);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	// ray_sphere_intersection(ray);
	
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->mlxwindow, imdt->image, 0, 0);
	mlx_hook(mlxdata->mlxwindow, 17, NO_EVENT, closing, mlxdata);
	mlx_loop(mlxdata->mlx);
	free_point(cam_loc);
	free_point(cam_point);
	free_direction(cam_view_dir);
	free_object(obj_cam);
	free_object(obj_screen);
	// free(mlxdata);
	return (0);
}
