/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:48:53 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 21:00:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <unistd.h>
#include <fcntl.h>

//Function writes a RGB triplet based on a pixel colour to a file.
static void	write_ppm_pix_file(t_pixel *pix, int fd)
{
	int	red;
	int	green;
	int	blue;

	red = (pix->colour->full & 0xFF0000) >> 16;
	green = (pix->colour->full & 0xFF00) >> 8;
	blue = pix->colour->full & 0xFF;
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

//Function draws an image from each pixel's colour.
void	image_draw(t_program *program)
{
	int			i;
	int			j;
	int			fd;
	t_screen	*scr;

	scr = screen_program(program);
	fd = open("out.ppm", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	image_ppm_preamble(fd);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			write_ppm_pix_file(scr->pixels[i][j], fd);
			if (j != WIN_WIDTH - 1)
				ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	close(fd);
}
