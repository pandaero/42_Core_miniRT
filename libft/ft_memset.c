/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:46:57 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function writes a value to a determined length of bytes in a string's memory.
Returns the first argument, the string's first character.
Turns the value to unsigned char, then writes it to each location within length.
*/
#include <stddef.h>

void	*ft_memset(void *byte, int ch, size_t n)
{
	size_t			i;
	unsigned char	*mptr;

	mptr = (unsigned char *) byte;
	i = 0;
	while (n > i)
	{
		mptr[i] = ch;
		i++;
	}
	return (byte);
}

/* Test | gcc -Wall -Werror -Wextra ft_memset.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hello";
	char	strcp[] = "Hello";
	char	*ret;
	char	*ret2;

	printf("Before:  %s\n", str);
	printf("Address: %x\n", *str);
	ret = ft_memset(str, 'x', 2);
	printf("After:     %s\n", str);
	ret2 = memset(strcp, 'x', 2);
	printf("Lib After: %s\n", strcp);
	printf("Address:     %x\n", *ret);
	printf("Lib Address: %x\n", *ret2);
	return (0);
}
//*/