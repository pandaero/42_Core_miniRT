/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/26 20:55:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function looks for a character within a character string pointer.
Returns pointer to location of character. If invalid, returns string pointer.
Compares each character in string. Returns pointer first time it is the same.
*/
#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;

	i = 0;
	if (ft_isascii(ch) == 0)
		return ((char *) &str[i]);
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char *) &str[i]);
		i++;
	}
	if (ch == '\0' && str[i] == '\0')
		return ((char *) &str[i]);
	return ((char *) 0);
}

/* Test | gcc -Wall -Werror -Wextra ft_strchr.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Word";
	char	ch = 'o';
	char	*ptr;

	printf("----|----|----|----\n");
	printf("String: %s, Address: %x\nChar:   %c, Address: %x\n",
			str, *str, ch, ch);
	ptr = ft_strchr(str, ch);
	printf("Search address: %x\n", *ptr);
	return (0);
}
//*/