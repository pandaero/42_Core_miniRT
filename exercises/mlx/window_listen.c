// Exercise to open a window and record events.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c -lmlx
// From root: cc -framework OpenGL -framework AppKit exercises/mlx/window_listen.c minilibx_opengl_20191021/libmlx.a
// Using minilibx-linux
// From root: cc exercises/mlx/window_listen.c minilibx-linux/libmlx_Linux.a -lX11 -lXext


#if defined (__APPLE__)
# include "../../apple_mlx.h"
# include "../../minilibx_opengl_20191021/mlx.h"
#endif
#if defined (__linux__)
# include "../../include/linux_mlx.h"
# include "../../minilibx-linux/mlx.h"
#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*window;
}			t_vars;

int	closing(t_vars *mlxvars)
{
	printf("Exiting...\n");
	mlx_destroy_window(mlxvars->mlx, mlxvars->window);
	exit(0);
}

int	keys(int key, t_vars *mlxvars)
{
	if (key == ESCAPE)
		closing(mlxvars);
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

	width = 500;
	height = 500;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return(0);
	vars->window = mlx_new_window(vars->mlx, width, height, "Title");
	image = mlx_new_image(vars->mlx, width, height);
	mlx_put_image_to_window(vars->mlx, vars->window, image, 0, 0);
	mlx_hook(vars->window, 17, NO_EVENT, closing, vars);
	mlx_hook(vars->window, 3, KEY_RELEASE, keys, vars);
	mlx_loop(vars->mlx);
	return (0);
}
