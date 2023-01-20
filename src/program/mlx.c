/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:33:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 03:28:21 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function handles the window closing action.
int	closing(t_mlxdata *mlxvars)
{
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

	program->mlx = mxdt;
	mxdt = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mxdt->imdt = (t_imgdata *)malloc(sizeof(t_imgdata));
	mxdt->mlx = mlx_init();
	mxdt->window = mlx_new_window(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT, \
									"miniRT");
	mxdt->imdt->image = mlx_new_image(mlxdata->mlx, WIN_WIDTH, WIN_HEIGHT);
	mxdt->imdt->address = mlx_get_data_addr(imdt->image, &imdt->bits_pp, \
											&imdt->line_len, &imdt->endian);
	if (!mxdt->mlx || !mxdt->window || !mxdt->imdt->image || \
			!mxdt->imdt->address)
		error_mlx_exit(program);
}

//Function groups the MLX looping functions. Operates hooks and main loop.
void	mlx_looping(t_program *program)
{
	mlx_put_image_to_window(program->mlx->mlx, program->mlx->window, \
							program->mlx->imdt->image, 0, 0);
	mlx_hook(program->mlx->window, 17, NO_EVENT, closing, mlxdata);
	mlx_hook(program->mlx->window, 3, KEY_RELEASE, keys, mlxdata);
	mlx_loop(program->mlx->mlx);
}
