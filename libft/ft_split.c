/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/06/03 19:02:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function splits a char string into char strings between a delimiter char.
Returns an array of char strings.
Determines no. of split elements, allocs mem, fills array using start and len.
*/
#include "libft.h"
#include <stdlib.h>

//Function finds number of "words" in string between a set delimiter character.
unsigned int	ft_nwrds(const char *str, unsigned char ch)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			if (str[i + 1] != ch && str[i + 1] != '\0')
				cnt++;
			i++;
		}
		else
		{
			if (cnt == 0)
				cnt++;
			i++;
		}
	}
	return (cnt);
}

//Function returns the starting position index of a word.
static unsigned int	startpos(const char *str, char del, unsigned int pos)
{
	if (str[pos] != del)
		return (pos);
	while (str[pos] == del)
		pos++;
	if (str[pos] != del)
		return (pos);
	else
		return (0);
}

//Function determines the length of a word, given its starting position index.
static unsigned int	length(const char *str, char del, unsigned int pos)
{
	unsigned int	ret;

	ret = 0;
	while (str[pos] != '\0' && str[pos] != del)
	{
		pos++;
		ret++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char			**out;
	unsigned int	i;
	unsigned int	start;
	unsigned int	len;

	out = (char **)malloc((ft_nwrds(s, c) + 1) * sizeof(char *));
	if (!out)
		return ((void *) 0);
	i = 0;
	start = 0;
	len = 0;
	while (i < ft_nwrds(s, c))
	{
		start = startpos(s, c, start + len);
		len = length(s, c, start);
		out[i] = ft_substr((char *)s, start, len);
		i++;
	}
	out[i] = (char *) 0;
	return (out);
}

/* Test
//gcc -Wall -Werror -Wextra ft_split.c ft_substr.c ft_strlen.c && ./a.out
#include <stdio.h>

int	main(void)
{
	//char	str[] = ";;o;he;;hello";
	char	str[] = "tripouille";

	char	**arr = ft_split(str, 0);
	printf("Result1:%s, Result2:%s, Result3:%s, Result4:%s\n",
			arr[0], arr[1], "0", "0"); //arr[2], arr[3]);
	return (0);
}
//*/