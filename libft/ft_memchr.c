/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:09:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function locates the first instance of a character within a string.
Returns pointer to location of the character. Returns null if no such character.
Converts to correct types, then checks for equivalence up to n.
*/
#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *str, int ch, size_t n)
{
	unsigned int	i;
	unsigned char	*strch;
	unsigned char	uch;

	i = 0;
	strch = (unsigned char *) str;
	uch = (unsigned char) ch;
	while (n > i)
	{
		if (strch[i] == uch)
			return ((void *) &strch[i]);
		i++;
	}
	return ((void *) 0);
}

/* Test | gcc -Wall -Werror -Wextra ft_memchr.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};

	printf("Test\nLibrary: 1-%x, 2-%x, 3-%x, 4-%x, 5-%x\n", memchr(s, 0, 0),
			memchr(s, 0, 1), memchr(s, 2, 3), memchr(s, 6, 6),
			memchr(s, 2 + 256, 3));
	printf("Mine:    1-%x, 2-%x, 3-%x, 4-%x, 5-%x", ft_memchr(s, 0, 0),
			ft_memchr(s, 0, 1), ft_memchr(s, 2, 3), ft_memchr(s, 6, 6),
			ft_memchr(s, 2 + 256, 3));
	return (0);
}
//*/