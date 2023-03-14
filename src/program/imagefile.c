/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:53 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 12:35:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

//Function writes a RGB triplet based on a pixel colour to a file.
static void	write_ppm_pix_file(t_pixel *pix, int fd)
{
	int	red;
	int	green;
	int	blue;

	red = (pix->colour.full & 0xFF0000) >> 16;
	green = (pix->colour.full & 0xFF00) >> 8;
	blue = pix->colour.full & 0xFF;
	ft_putnbr_fd(red, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(green, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(blue, fd);
}

//Function writes the preamble for a ppm file.
static void	image_ppm_preamble(int fd)
{
	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(WIN_WIDTH, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(WIN_HEIGHT, fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("255", fd);
}

//Function prints out status message for writing operation.
static void	print_status(int prog, int total)
{
	int	perc;

	if (STATUS)
	{
		perc = round(100 * prog / total);
		if (prog == total)
			ft_printf("Writing... 100%%\n");
		else
			ft_printf("Writing... %i%%\r", perc);
	}
}

//Function draws an image from each pixel's colour.
void	image_draw(t_program *program)
{
	int			draw[5];
	t_screen	*scr;

	draw[4] = WIN_WIDTH * WIN_HEIGHT;
	scr = screen_program(program);
	draw[2] = open("out.ppm", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	image_ppm_preamble(draw[2]);
	draw[0] = 0;
	while (draw[0] < WIN_HEIGHT)
	{
		draw[1] = 0;
		while (draw[1] < WIN_WIDTH)
		{
			write_ppm_pix_file(scr->pixels[draw[0]][draw[1]], draw[2]);
			if (draw[1] != WIN_WIDTH - 1)
				ft_putchar_fd(' ', draw[2]);
			draw[1]++;
		}
		draw[3] = (draw[0] * WIN_WIDTH + draw[1]);
		print_status(draw[3], draw[4]);
		ft_putchar_fd('\n', draw[2]);
		draw[0]++;
	}
	close(draw[2]);
}
