/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:08:57 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:46:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function checks if character is a digit.
Function returns 1 if it does, 0 otherwise.
Check whether a digit, return 0 if not.
*/

int	ft_isdigit(int ch)
{
	if (!((ch >= '0' && ch <= '9')))
		return ((int) 0);
	return ((int) 1);
}

/* Test | gcc -Wall -Werror -Wextra ft_isdigit.c && ./a.out
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
	printf("Own Result:   %d\n", ft_isdigit(tc1));
	printf("ctype Result: %d\n", isdigit(tc1));
	printf("----|----|----|----\n");
	printf("Character 2:  %c\n", tc2);
	printf("Own Result:   %d\n", ft_isdigit(tc2));
	printf("ctype Result: %d\n", isdigit(tc2));
	printf("----|----|----|----\n");
	printf("Character 3:  %c\n", tc3);
	printf("Own Result:   %d\n", ft_isdigit(tc3));
	printf("ctype Result: %d\n", isdigit(tc3));
	printf("----|----|----|----\n");
	printf("Character 4:  %c\n", tc4);
	printf("Own Result:   %d\n", ft_isdigit(tc4));
	printf("ctype Result: %d\n", isdigit(tc4));
	printf("----|----|----|----\n");
	printf("Character 5:  %c\n", tc5);
	printf("Own Result:   %d\n", ft_isdigit(tc5));
	printf("ctype Result: %d\n", isdigit(tc5));
	printf("----|----|----|----\n");
	printf("Character 6:  %c\n", tc6);
	printf("Own Result:   %d\n", ft_isdigit(tc6));
	printf("ctype Result: %d\n", isdigit(tc6));
	printf("----|----|----|----\n");
	printf("Character 7:  %c\n", tc7);
	printf("Own Result:   %d\n", ft_isdigit(tc7));
	printf("ctype Result: %d\n", isdigit(tc7));
	printf("----|----|----|----\n");
	printf("Character 8:  %c\n", tc8);
	printf("Own Result:   %d\n", ft_isdigit(tc8));
	printf("ctype Result: %d\n", isdigit(tc8));
	printf("----|----|----|----\n");
	printf("Character 9:  %c\n", tc9);
	printf("Own Result:   %d\n", ft_isdigit(tc9));
	printf("ctype Result: %d\n", isdigit(tc9));
	printf("----|----|----|----\n");
	printf("Character 10: %c\n", tc10);
	printf("Own Result:   %d\n", ft_isdigit(tc10));
	printf("ctype Result: %d\n", isdigit(tc10));
	printf("----|----|----|----\n");
	printf("Character 11: %c\n", tc11);
	printf("Own Result:   %d\n", ft_isdigit(tc11));
	printf("ctype Result: %d\n", isdigit(tc11));
	return (0);
}
//*/