/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/22 20:55:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function locates string within n in another string. Returns pointer to location.
Returns a pointer to the first letter within the searched string. Null if no-go.
Searches for the first matching letter, then checks if whole term is found.
*/
#include <stddef.h>

char	*ft_strnstr(const char *sch, const char *trm, size_t srl)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	ptr = 0;
	if (trm[i] == '\0')
		ptr = (char *) sch;
	else
	{
		while (sch[i] != '\0' && srl > i)
		{
			while (trm[j] == sch[i + j] && trm[j] != '\0')
				j++;
			if (trm[j] == '\0' && sch[i + j - 1] == trm[j - 1] && srl >= i + j)
			{
				ptr = (char *) sch + i;
				break ;
			}
			j = 0;
			i++;
		}
	}
	return (ptr);
}

/* Test | gcc -Wall -Werror -Wextra ft_strnstr.c && ./a.out
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			search[30] = "aaabcabcd";
	char			term[10] = "aabc";
	char			term2[] = "cd";
	char            term3[] = "a";
	char			empty[] = "";
	unsigned int	srlen;

	srlen = 8;
	// Correspond to libfttester 2,5,(6),11,12
	printf("Test -- std -- search-%s, term-%s, srlen-%d, ret-%s\n",
			search, term, srlen, ft_strnstr(search, term, srlen));
	printf("Test --empty-- search-%s, term-%s    , srlen-%d, ret-%s\n",
			search, empty, srlen, ft_strnstr(search, empty, srlen));
	printf("Test --almst-- search-%s, term-%s  , srlen-%d, ret-%s\n",
			search, term2, srlen, ft_strnstr(search, term2, srlen));
	srlen = 1;
    printf("Test --alms2-- search-%s, term-%s   , srlen-%d, ret-%s\n",
            search, term3, srlen, ft_strnstr(search, term3, srlen));
	return (0);
}
//*/