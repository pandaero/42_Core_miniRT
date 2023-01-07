/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:45:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function sets determined length of memory in a string to zero.
Returns nothing, but the memory will have the zeroes.
Uses ft_memset to set determined length to string.
*/
#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}

/* Test | gcc -Wall -Werror -Wextra ft_bzero.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello";

	printf("Before:  %s\n", str);
	printf("Address: %x\n", *str);
	ft_bzero(str, 3);
	printf("After:   %s\n", str);
	return (0);
}
//*/