/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/24 19:32:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function duplicates a string to a new memory location.
Returns a pointer to the new string location. Does not write to stderror.
Measures the size required, then allocates it and fills it with previous values.
*/
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*dst;
	unsigned int	size;

	size = ft_strlen(str);
	dst = malloc((1 + size) * (sizeof(char)));
	if (!dst)
		return ((char *) 0);
	if (str[0] == '\0')
	{
		dst[0] = '\0';
		return ((char *) dst);
	}
	dst = ft_memcpy(dst, str, size + 1);
	return ((char *) dst);
}

/* Test
//gcc -Wall -Werror -Wextra ft_strdup.c ft_memcpy.c ft_strlen.c&&./a.out|cat -e
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = ft_strdup((char *) "coucou");
	char	*empty = ft_strdup((char *) "");

	printf("Test1: str-%s, ret-%s\n", "coucou", s);
	printf("Teste: str-%s      , ret-%s\n", "", empty);
	return (0);
}
//*/