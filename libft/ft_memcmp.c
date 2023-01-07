/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:08:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function compares two byte strings for equality.
Returns 0 if the strings are identical or the difference between first non-same.
Runs through strings and returns difference if the location differs. 0 when not.
*/
#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	i = 0;
	pstr1 = (unsigned char *) str1;
	pstr2 = (unsigned char *) str2;
	while (n > i)
	{
		if (pstr1[i] != pstr2[i])
			return (pstr1[i] - pstr2[i]);
		i++;
	}
	return (0);
}

/* Test | gcc -Wall -Werror -Wextra ft_memcmp.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("----|----|----|-Test|----|----|----|\n");
	printf("Library: 1-%d, 2-%d, 3-%d, 4-%d, 5-%d", memcmp(s, sCpy, 4),
			memcmp(s, s2, 0), memcmp(s, s2, 1), memcmp(s2, s, 1),
			memcmp(s2, s3, 4));
	printf("Library: 1-%d, 2-%d, 3-%d, 4-%d, 5-%d", ft_memcmp(s, sCpy, 4),
			ft_memcmp(s, s2, 0), ft_memcmp(s, s2, 1), ft_memcmp(s2, s, 1),
			ft_memcmp(s2, s3, 4));
	return (0);
}
//*/