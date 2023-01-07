/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/06/03 10:43:54 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function creates a new char string with chars from the input removed.
Returns a pointer to the new string (with the characters from the set removed).
Allocates necessary memory, then checks source string to trim characters from. 
*/
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - i;
	while (j > 0 && ft_strchr(set, s1[i + j]))
		j--;
	ptr = ft_substr(s1, i, j + 1);
	if (!ptr)
		return ((char *) 0);
	return (ptr);
}

/* Test
//gcc -Wall -Werror -Wextra ft_strtrim.c ft_strchr.c ft_strlen.c ft_substr.c
// && ./a.out | cat -e
#include <stdio.h>

int	main(void)
{
	char	s[] = "  xxtriple";
	char	set[] = " x";
	char	s2[] = " xxtr iple  xx";
	char	s3[] = "  xxtrix  xplexx  ";

	printf("Test1: s-%s, set-%s, Out-%s\n", s, set, ft_strtrim(s, set));
	printf("Test2: s-%s, set-%s, Out-%s\n", s2, set, ft_strtrim(s2, set));
	printf("Test3: s-%s, set-%s, Out-%s\n", s3, set, ft_strtrim(s3, set));
	return (0);
}
//*/