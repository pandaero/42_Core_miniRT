/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:42:54 by pandalaf          #+#    #+#             */
/*   Updated: 2022/08/26 18:42:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

//Function searches for char and returns first location. 0 not found. 1 is 1st.
int	ft_strsrch(char *str, int ch)
{
	unsigned int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (i + 1);
		i++;
	}
	return (0);
}

/*Test strsrch
//gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello";
	char	ch = '3';

	printf("Str: %s, Ch: %c, Out: %d\n", str, ch, ft_strsrch(str, ch));
	return (0);
}
//*/

//Function joins two character strings, creates a new char string.
char	*ft_strjoinmod(char *s1, char *s2)
{
	unsigned char	*ptr;
	unsigned int	ii[2];

	if (!s1)
	{
		s1 = malloc(1 * sizeof(*s1));
		s1[0] = '\0';
	}
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*ptr));
	if (!ptr)
		return ((char *) 0);
	ii[0] = -1;
	while (s1[++ii[0]] != '\0')
		ptr[ii[0]] = s1[ii[0]];
	free(s1);
	ii[1] = -1;
	while (s2[++ii[1]] != '\0')
		ptr[ii[0] + ii[1]] = s2[ii[1]];
	ptr[ii[0] + ii[1]] = 0;
	return ((char *) ptr);
}

/* Test | gcc -Wall -Werror -Wextra get_next_line_utils.c && ./a.out
//valgrind --leak-check=full ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = strdup("You");
	char	s2[] = " and me";
	char	*join;

	printf("Test: s1-%s, ", s1);
	join = ft_strjoinmod(s1, s2);
	printf("s2-%s, Out-%s\n", s2, join);
	free(join);
	return (0);
}
//*/
