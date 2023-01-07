/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 15:15:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function moves n bytes (char 8-bits) from source string to destination string.
Returns pointer to destination string. Destination string has been written to.
Makes pointers to characters (they store 1 byte), writes to temp, then to dest.
*/
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!src || !dst || n == 0)
		return (dst);
	psrc = (unsigned char *) src;
	pdst = (unsigned char *) dst;
	if (dst < src)
		dst = ft_memcpy(dst, src, n);
	else
	{
		i = 0;
		while (n > i)
		{
			pdst[n - i - 1] = psrc[n - i - 1];
			i++;
		}
	}
	return ((void *) dst);
}

/* Test | gcc -Wall -Werror -Wextra ft_memmove.c ft_memcpy.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[] = "500.000";
	char	dstfn[] = "500.000";
	char	src[] = "two3452";
	char	dstcpy[] = "500.000";
	size_t	n = 0;

	printf("----|-Test|----\n");
	printf("Mine|-- Before: %s, Src: %s, After: %s\n",
			dstcpy, src, (char *) ft_memmove(dst, src,n));
	printf("Lib-|-- Before: %s, Src: %s, After: %s\n",
			dstcpy, src, (char *) memmove(dstfn, src, n));
	return (0);
}
//*/