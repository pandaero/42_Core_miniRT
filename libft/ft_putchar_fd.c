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
Function writes character to input file descriptor.
No return value, writes chaaracter to file descriptor.
Calls write function to write to file descriptor.
*/
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* Test | gcc -Wall -Werror -Wextra ft_putchar_fd.c && ./a.out
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		filedesc;
	char	ch;

	ch = 'B';
	filedesc = open("putchar.txt", O_CREAT | O_WRONLY);
	ft_putchar_fd('A', filedesc);
	write(filedesc, &ch, 1);
	close(filedesc);
	return (0);
}
//*/