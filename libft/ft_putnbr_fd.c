/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:08:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function writes a number as a string to the input file descriptor.
No return value, writes number as character string to file descriptor.
Uses recursion to run through the number.
*/
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

/* Test
//gcc -Wall -Werror -Wextra ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c && ./a.out
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		filedesc;
	int		n1 = 1234;
	int		n2 = -1234;

	filedesc = open("putnbr1.txt", O_CREAT | O_WRONLY);
	ft_putnbr_fd(n1, filedesc);
	close(filedesc);
	filedesc = open("putnbr2.txt", O_CREAT | O_WRONLY);
	ft_putnbr_fd(n2, filedesc);
	close(filedesc);
	return (0);
}
//*/