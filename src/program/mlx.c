/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:33:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:39:02 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
