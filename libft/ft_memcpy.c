/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:07:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function copies n bytes (char 8-bits) from source string to destination string.
Returns pointer to destination string. Destination string has been written to.
Makes pointers to unsigned characters (they store 1 byte), and overwrites dest.
*/
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	psrc = (unsigned char *) src;
	pdst = (unsigned char *) dst;
	while (n > i)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return ((void *) dst);
}

/* Test | gcc -Wall -Werror -Wextra ft_memcpy.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[] = "500.000";
	char	dstfn[] = "500.000";
	char	src[] = "two";
	char	dstcpy[] = "500.000";

	printf("----|-Test|----\n");
	printf("Mine|-- Before: %s, Src: %s, After: %s\n",
			dstcpy, src, (char *) ft_memcpy(dst, src,3));
	printf("Lib-|-- Before: %s, Src: %s, After: %s\n",
			dstcpy, src, (char *) memcpy(dstfn, src, 3));
	return (0);
}
//*/