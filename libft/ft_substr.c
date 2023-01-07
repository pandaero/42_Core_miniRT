/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/26 20:45:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function creates a new character string from another character string's content.
Returns pointer to the new string. Null if memory allocation fails.
Allocates the memory, then fills it with the sub-string.
*/
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (start > ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return ((char *) 0);
		ptr[0] = '\0';
		return ((char *) ptr);
	}
	else if (len + start >= ft_strlen(s))
		ptr = malloc((ft_strlen(s) - start + 1) * (sizeof(char)));
	else
		ptr = malloc((len + 1) * (sizeof(char)));
	if (!ptr)
		return ((char *) 0);
	i = 0;
	while (len > i && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *) ptr);
}

/* Test | gcc -Wall -Werror -Wextra ft_substr.c ft_strlen.c && ./a.out
#include <stdio.h>

int	main(void)
{
	char			src[] = "0123456789";
	unsigned int	start = 5;
	unsigned int	len = 100;

	printf("Test: str-%s, start-%d, n-%d, out-%s", src, start, len,
			ft_substr(src, start, len));
	return (0);
}
//*/