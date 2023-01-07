/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/19 22:25:36 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function compares two strings, gives difference when not equal.
Returns 0 if strings are equal. Returns ASCII difference when not.
Checks while they are equal and increments, when not, gives difference.
*/
#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (str1[i] == str2[i] && n > i + 1)
		i++;
	if (str1[i] != str2[i] && n != 0)
		return ((unsigned char) str1[i] - (unsigned char) str2[i]);
	return (0);
}

/* Test | gcc -Wall -Werror -Wextra ft_strncmp.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str11;
	char	*str21;
	int		n1;

	str11 = "1234";
	str21 = "1235";
	n1 = 3;
	printf("----|Test 1:\n");
	printf("str1: %s, str2: %s, n: %d\n", str11, str21, n1);
	printf("Library: %d, Mine: %d\n", strncmp(str11, str21, n1),
			ft_strncmp(str11, str21, n1));
	return (0);
}
//*/