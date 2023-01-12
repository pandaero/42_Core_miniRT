// Exercise to open a window and record events.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c -lmlx
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c minilibx_opengl_20191021/libmlx.a

#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}			t_vars;

int	closing(t_vars *mlxvars)
{
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	exit(0);
}

int	keys(int key, t_vars *mlxvars)
{
	if (key == 53)
	{
		mlx_destroy_window(mlxvars->mlx, mlxvars->window);
		exit(0);
	}
	else
		printf("Key released: %d\n", key);
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	void	*image;
	int		width;
	int		height;

	width = 300;
	height = 500;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return(0);
	vars->window = mlx_new_window(vars->mlx, width, height, "Title");
	image = mlx_new_image(vars->mlx, width, height);
	mlx_put_image_to_window(vars->mlx, vars->window, image, 0, 0);
	mlx_hook(vars->window, 17, 0, closing, vars);
	mlx_hook(vars->window, 3, 0, keys, vars);
	mlx_loop(vars->mlx);
	return (0);
}
