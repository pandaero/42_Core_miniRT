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
Function applies another function to the entered string.
Returns nothing, modifies entered string.
For non-empty pointers to char and function, applies function to char string.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!(!s || !f))
	{
		i = 0;
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}

/* Test | gcc -Wall -Werror -Wextra ft_striteri.c && ./a.out
#include <stdio.h>

void	addx(unsigned int i, char *c)
{
	*c += i;
}

int	main(void)
{
	char s[] = "1234";

	ft_striteri(s, addx);
	printf("In:%s, Fn: addex Out:%s\n", "1234", s);
	return (0);
}
//*/