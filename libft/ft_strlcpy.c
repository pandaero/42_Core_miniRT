/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/24 19:16:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function writes to n bytes of a character string from a source to a destination.
Outputs the size of the attempted copy string.
For non-zero destination sizes, overwrites destination with source.
*/
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t sizedst)
{
	unsigned int	i;

	i = 0;
	if (sizedst != 0)
	{
		while (sizedst - 1 > i && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	if (sizedst == 1)
		dst[0] = '\0';
	while (src[i] != '\0')
		i++;
	return ((size_t) i);
}

/* Test | gcc -Wall -Werror -Wextra ft_strlcpy.c && ./a.out | cat -e
#include <stdio.h>
#include <string.h>

int	main(void)
{
	unsigned int n = 4;
	char dst[10];
	char dstcpy[10];
	char dstlib[10];
	char src[] = "coucou";

	memset(dst, 'A', 10);
	memset(dstcpy, 'A', 10);
	memset(dstlib, 'A', 10);
	printf("Test: dst-%s, src-%s, n-%d, ft_s..-%zu dst*-%s\n",
			dstcpy, src, n, ft_strlcpy(dst, src, n), dst);
	printf("Lib : dst-%s, src-%s, n-%d, strl..-%lu dst*-%s\n",
			dstcpy, src, n, strlcpy(dstlib, src, n), dstlib);
	return (0);
}
//*/