/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/22 01:47:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function appends n bytes of a source character string to a destination string.
Appends string to another, return val is the size of attempted resulting string.
If defined dest size is larger than current dest size, copy diff to end of dest.
*/
#include <stddef.h>
#include "libft.h"

//Function returns the smaller between specified max length and string length.
static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	unsigned int	i;

	i = 0;
	while (i < maxlen && s[i] != '\0')
		i++;
	return ((size_t) i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*diffdst;
	size_t	dstlen;
	size_t	diffsize;

	dstlen = (size_t) ft_strnlen(dst, dstsize);
	if (dstlen >= dstsize)
		return (dstlen + ft_strlen(src));
	diffdst = dst + dstlen;
	diffsize = dstsize - dstlen;
	return (dstlen + ft_strlcpy(diffdst, src, diffsize));
}

/* Test
//gcc -Wall -Werror -Wextra ft_strlcat.c ft_strlcpy.c ft_strlen.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dst[30];
	char dstcpy[30];
	char dstlib[30];
	char src[] = "AAAAAAAAA";
	unsigned int dsize = 8;

	memset(dst, 0, 30);
	memset(dstcpy, 0, 30);
	memset(dstlib, 0, 30);
	memset(dst, 'B', 3);
	memset(dstcpy, 'B', 3);
	memset(dstlib, 'B', 3);
	printf("Test: dst-%s, src-%s, n-%d, ft_s..-%zu dst*-%s\n",
			dstcpy, src, dsize, ft_strlcat(dst, src, dsize), dst);
	printf("Lib : dst-%s, src-%s, n-%d, strl..-%lu dst*-%s\n",
			dstcpy, src, dsize, strlcat(dstlib, src, dsize), dstlib);
	return (0);
}
//*/