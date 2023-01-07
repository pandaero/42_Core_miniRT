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
Function writes a string to the input file descriptor and an end-of-line char.
No return value, writes string and ending to file descriptor.
Calls write function in a loop until the end of the string is reached, then EOL.
*/
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;
	char			eol;

	i = 0;
	eol = '\n';
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, &eol, 1);
}

/* Test | gcc -Wall -Werror -Wextra ft_putendl_fd.c && ./a.out
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		filedesc;
	char	s[] = "Newline follows";

	filedesc = open("putendl.txt", O_CREAT | O_WRONLY);
	ft_putstr_fd(s, filedesc);
	close(filedesc);
	return (0);
}
//*/