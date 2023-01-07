/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:42:52 by pandalaf          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"

//Function joins the initial string with reads from a descriptor until newline.
char	*joining(int fd, char *initial)
{
	char	*readbf;
	int		rd;

	readbf = malloc((BUFFER_SIZE + 1) * sizeof(*readbf));
	if (!readbf)
		return (initial);
	rd = 1;
	while (ft_strsrch(initial, '\n') == 0 && rd != 0)
	{
		rd = read(fd, readbf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(readbf);
			return ((char *) 0);
		}	
		readbf[rd] = '\0';
		initial = ft_strjoinmod(initial, readbf);
	}
	free(readbf);
	return (initial);
}

/* Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	int		fd;

	fd = open("sample.txt", O_RDONLY, 0);
	ptr = joining(fd, ptr);
	printf("Joined: %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

//Function trims the input string such that contents after newline are cut.
char	*output(char *candidate)
{
	int		i;
	char	*outout;

	if (candidate[0] == '\0')
		return ((char *) 0);
	i = 0;
	while (candidate[i] != '\0' && candidate[i] != '\n')
		i++;
	outout = malloc((i + 2) * sizeof(*outout));
	if (!outout)
		return ((char *) 0);
	i = 0;
	while (candidate[i] != '\0' && candidate[i] != '\n')
	{
		outout[i] = candidate[i];
		i++;
	}
	if (candidate[i] == '\n')
	{
		outout[i] = candidate[i];
		i++;
	}
	outout[i] = '\0';
	return (outout);
}

/*Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	test1[] = "Hello there\nan\nd \neverything else";
	char	test2[] = "Hello there";
	char	test3[] = "";
	char	test4[] = "\n\n";
	char	*ptr;

	ptr = output(test1);
	printf("Newline Test  : %s\n", ptr);
	free(ptr);
	ptr = output(test2);
	printf("Null-Term Test: %s\n", ptr);
	free(ptr);
	ptr = output(test3);
	printf("Empty Test    : %s\n", ptr);
	free(ptr);
	ptr = output(test4);
	printf("Newlines Test : %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

//Function takes input string and returns contents after the first newline.
char	*remaining(char *candidate)
{
	int		ii[2];
	char	*remout;

	ii[0] = 0;
	while (candidate[ii[0]] != '\0' && candidate[ii[0]] != '\n')
		ii[0]++;
	if (candidate[ii[0]] == '\0')
	{
		free(candidate);
		return ((char *) 0);
	}
	remout = malloc((ft_strlen(candidate) - ii[0] + 1) * sizeof(*remout));
	if (!remout)
		return ((char *) 0);
	ii[0]++;
	ii[1] = 0;
	while (candidate[ii[0]] != '\0')
	{
		remout[ii[1]] = candidate[ii[0]];
		ii[0]++;
		ii[1]++;
	}
	remout[ii[1]] = '\0';
	free(candidate);
	return (remout);
}

/*Test
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	char	*test1;
	test1 = strdup("xxxx\nxx\nxxx\nx\n\n");
	char	*test2;
	test2 = strdup("xx");
	char	*test3;
	test3 = strdup("xxxxxxxx\n\n");
	char	*test4;
	test4 = malloc(2 * sizeof(char));
	test4[0] = '\0';
	test4[1] = '\0';
	char	*test5;
	test5 = strdup("\n\n");

	ptr = remaining(test1);
	printf("Newline Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test2);
	printf("Nothing Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test3);
	printf("Newlast Test: %s\n", ptr);
	free(ptr);
	ptr = remaining(test4);
	printf("Empty Test  : %s\n", ptr);
	free(ptr);
	ptr = remaining(test5);
	printf("Just Newline: %s\n", ptr);
	free(ptr);
	return (0);
}
//*/

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*out;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return ((char *) 0);
	ptr = joining(fd, ptr);
	if (!ptr)
		return ((char *) 0);
	out = output(ptr);
	ptr = remaining(ptr);
	return (out);
}

/*Test
//gcc get_next_line.c get_next_line_utils.c && ./a.out | cat -e
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*ptr;

	i = 1;
	//Standard Input, close it with CTRL + D
	fd = 0;
	fd = open("sample.txt", O_RDONLY, 0);
	ptr = get_next_line(fd);
	while (ptr != (char *) 0)
	{
		printf("Line%d: %s", i, ptr);
		free(ptr);
		ptr = get_next_line(fd);
		i++;
	}
	return (0);
}
//*/