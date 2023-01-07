/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:08:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function maps a function to each character in input string.
Returns a string where each character has been the result of the function map.
Checks for null strings, applies the function to each char of the input str.
*/
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	if (!(!s || !f))
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		out = malloc((i + 1) * sizeof(char));
		if (!out)
			return ((void *) 0);
		i = 0;
		while (s[i] != '\0')
		{
			out[i] = f(i, s[i]);
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	return ((void *) 0);
}

/* Test | gcc -Wall -Werror -Wextra ft_strmapi.c && ./a.out
#include <stdio.h>

char	addx(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char *s = ft_strmapi("1234", addx);

	printf("In:%s, Fn: addex Out:%s", "1234", s);
	return (0);
}
//*/