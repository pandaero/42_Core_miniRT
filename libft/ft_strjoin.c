/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/26 17:12:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function concatenates two character strings, creates a new char string.
A pointer to the new character string.
Allocates memory for joined string, then copies from first, then second and nul.
*/
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return ((char *) 0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return ((char *) ptr);
}

/* Test | gcc -Wall -Werror -Wextra ft_strjoin.c ft_strlen.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char s1[] = "You";
	char s2[] = " and me";

	printf("Test: s1-%s, s2-%s, Out-%s", s1, s2, ft_strjoin(s1, s2));
	return (0);
}
//*/