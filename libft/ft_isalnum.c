/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:46:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function determines whether input is alphanumeric.
Returns 1 if it is, 0 otherwise.
Uses both isalpha and isdigit to check, combines conditions, 0 if not.
*/
#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ft_isalpha(ch) == 1) || (ft_isdigit(ch) == 1))
		return (1);
	return (0);
}

/* Test | gcc -Wall -Werror -Wextra ft_isalnum.c && ./a.out
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
	printf("Own Result:   %d\n", ft_isalnum(tc1));
	printf("ctype Result: %d\n", isalnum(tc1));
	printf("----|----|----|----\n");
	printf("Character 2:  %c\n", tc2);
	printf("Own Result:   %d\n", ft_isalnum(tc2));
	printf("ctype Result: %d\n", isalnum(tc2));
	printf("----|----|----|----\n");
	printf("Character 3:  %c\n", tc3);
	printf("Own Result:   %d\n", ft_isalnum(tc3));
	printf("ctype Result: %d\n", isalnum(tc3));
	printf("----|----|----|----\n");
	printf("Character 4:  %c\n", tc4);
	printf("Own Result:   %d\n", ft_isalnum(tc4));
	printf("ctype Result: %d\n", isalnum(tc4));
	printf("----|----|----|----\n");
	printf("Character 5:  %c\n", tc5);
	printf("Own Result:   %d\n", ft_isalnum(tc5));
	printf("ctype Result: %d\n", isalnum(tc5));
	printf("----|----|----|----\n");
	printf("Character 6:  %c\n", tc6);
	printf("Own Result:   %d\n", ft_isalnum(tc6));
	printf("ctype Result: %d\n", isalnum(tc6));
	printf("----|----|----|----\n");
	printf("Character 7:  %c\n", tc7);
	printf("Own Result:   %d\n", ft_isalnum(tc7));
	printf("ctype Result: %d\n", isalnum(tc7));
	printf("----|----|----|----\n");
	printf("Character 8:  %c\n", tc8);
	printf("Own Result:   %d\n", ft_isalnum(tc8));
	printf("ctype Result: %d\n", isalnum(tc8));
	printf("----|----|----|----\n");
	printf("Character 9:  %c\n", tc9);
	printf("Own Result:   %d\n", ft_isalnum(tc9));
	printf("ctype Result: %d\n", isalnum(tc9));
	printf("----|----|----|----\n");
	printf("Character 10: %c\n", tc10);
	printf("Own Result:   %d\n", ft_isalnum(tc10));
	printf("ctype Result: %d\n", isalnum(tc10));
	printf("----|----|----|----\n");
	printf("Character 11: %c\n", tc11);
	printf("Own Result:   %d\n", ft_isalnum(tc11));
	printf("ctype Result: %d\n", isalnum(tc11));
	return (0);
}
//*/