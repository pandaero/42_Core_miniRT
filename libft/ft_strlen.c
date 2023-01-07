/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:47:15 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function determines length of the string (number of characters contained in it).
Result is number of characters before null terminator.
Counts every character until the null terminator.
*/
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* Test | gcc -Wall -Werror -Wextra ft_strlen.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *f = "Hello World";
	char *d = "";
	printf("Test 1: %s, strlen: %lu, ft_strlen: %lu\n", f, strlen(f), ft_strlen(f));
	printf("Test 2: %s, strlen: %lu, ft_strlen: %lu\n", d, strlen(d), ft_strlen(d));
	return (0);
}
//*/