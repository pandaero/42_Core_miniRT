/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:33:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/12 02:27:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function handles the window closing action.
int	closing(t_program *program)
{
	mlx_destroy_window(program->mldt->mlx, program->mldt->window);
	free_program(program);
	exit(0);
}

//Function handles key releases.
int	keys(int key, t_program *program)
{
	if (key == ESCAPE)
		closing(program);
	return (0);
}

//Function places a pixel in an image more quickly than with the pixel_put fn.
void	quick_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dest;

	dest = 0;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dest = data->address + (y * data->line_len + x * (data->bits_pp / 8));
		*(unsigned int *)dest = color;
	}
}

//Function produces and allocates the MLX-required variables.
void	mlx_initialise(t_program *program)
{
	t_mlxdata	*mxdt;

	mxdt = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mxdt->imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mxdt->mlx = mlx_init();
	mxdt->window = mlx_new_window(mxdt->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mxdt->imdt->image = mlx_new_image(mxdt->mlx, WIN_WIDTH, WIN_HEIGHT);
	mxdt->imdt->address = mlx_get_data_addr(mxdt->imdt->image, \
			&mxdt->imdt->bits_pp, &mxdt->imdt->line_len, &mxdt->imdt->endian);
	if (!mxdt->mlx || !mxdt->window || !mxdt->imdt->image || \
			!mxdt->imdt->address)
		error_mlx_exit(program);
	program->mldt = mxdt;
}

//Function groups the MLX looping functions. Operates hooks and main loop.
void	mlx_looping(t_program *program)
{
	mlx_put_image_to_window(program->mldt->mlx, program->mldt->window, \
							program->mldt->imdt->image, 0, 0);
	mlx_hook(program->mldt->window, 17, NO_EVENT, closing, program);
	mlx_hook(program->mldt->window, 3, KEY_RELEASE, keys, program);
	mlx_loop(program->mldt->mlx);
}
