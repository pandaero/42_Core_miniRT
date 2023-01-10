// Exercise to open a window and record events.
// Using minilibx-opengl-20191021
// From root: cc -framework OpenGL -framework AppKit exercises/window_listen.c -lmlx

#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		x1;
	int		y2;
	int		x, y;

	x1 = 1;
	y2 = 2;
	x = 0;
	while (x < 10)
	{
		y = 2 * x;
		if (x1 * 2 == y2)
		{
			printf("It intesects\n");
			return(0);
		}
		x++;
	}
	printf("It does not intersect\n");
	return (0);
}
