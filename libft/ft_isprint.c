/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:46:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function determines whether input is a printing character.
Returns 1 if it is, 0 otherwise.
Uses ft_isalnum and ranges to check, returns 0 if not.
*/
#include "libft.h"

int	ft_isprint(int ch)
{
	if (ft_isalnum(ch) == 1 || (ch >= ' ' && ch < 48) || (ch > 49 && ch < 58))
		return (1);
	if ((ch >= ':' && ch <= '?') || ch == '@' || (ch > 'Z' && ch <= '_'))
		return (1);
	if (ch == '`' || (ch > 'z' && ch <= '~'))
		return (1);
	return (0);
}

/* Test | gcc -Wall -Werror -Wextra ft_isprint.c && ./a.out
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	tc1 = '\n';
	char	tc2 = '0';
	char	tc3 = '9';
	char	tc4 = '@';
	char	tc5 = '[';
	char	tc6 = '`';
	char	tc7 = '{';
	char	tc8 = 'a';
	char	tc9 = 'z';
	char	tc10 = 'A';
	char	tc11 = 'Z';

	printf("\n----|- Test --|----\n");
	printf("Character 1:  newline\n");
	printf("Own Result:   %d\n", ft_isprint(tc1));
	printf("ctype Result: %d\n", isprint(tc1));
	printf("----|----|----|----\n");
	printf("Character 2:  %c\n", tc2);
	printf("Own Result:   %d\n", ft_isprint(tc2));
	printf("ctype Result: %d\n", isprint(tc2));
	printf("----|----|----|----\n");
	printf("Character 3:  %c\n", tc3);
	printf("Own Result:   %d\n", ft_isprint(tc3));
	printf("ctype Result: %d\n", isprint(tc3));
	printf("----|----|----|----\n");
	printf("Character 4:  %c\n", tc4);
	printf("Own Result:   %d\n", ft_isprint(tc4));
	printf("ctype Result: %d\n", isprint(tc4));
	printf("----|----|----|----\n");
	printf("Character 5:  %c\n", tc5);
	printf("Own Result:   %d\n", ft_isprint(tc5));
	printf("ctype Result: %d\n", isprint(tc5));
	printf("----|----|----|----\n");
	printf("Character 6:  %c\n", tc6);
	printf("Own Result:   %d\n", ft_isprint(tc6));
	printf("ctype Result: %d\n", isprint(tc6));
	printf("----|----|----|----\n");
	printf("Character 7:  %c\n", tc7);
	printf("Own Result:   %d\n", ft_isprint(tc7));
	printf("ctype Result: %d\n", isprint(tc7));
	printf("----|----|----|----\n");
	printf("Character 8:  %c\n", tc8);
	printf("Own Result:   %d\n", ft_isprint(tc8));
	printf("ctype Result: %d\n", isprint(tc8));
	printf("----|----|----|----\n");
	printf("Character 9:  %c\n", tc9);
	printf("Own Result:   %d\n", ft_isprint(tc9));
	printf("ctype Result: %d\n", isprint(tc9));
	printf("----|----|----|----\n");
	printf("Character 10: %c\n", tc10);
	printf("Own Result:   %d\n", ft_isprint(tc10));
	printf("ctype Result: %d\n", isprint(tc10));
	printf("----|----|----|----\n");
	printf("Character 11: %c\n", tc11);
	printf("Own Result:   %d\n", ft_isprint(tc11));
	printf("ctype Result: %d\n", isprint(tc11));
	return (0);
}
//*/