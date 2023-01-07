/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:47:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function takes an uppercase letter character and makes it a lowercase letter.
Result is the lowercase value for the input character.
Checks input, then ASCII offset is applied to give the lowercase value.
*/

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

/* Test | gcc -Wall -Werror -Wextra ft_tolower.c && ./a.out
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	ch;

	ch = 'A';
	printf("Mine:\n");
	printf("Before: %c, After: %c\n", ch, ft_tolower(ch));
	printf("Library:\n");
	ch--;
	printf("Before: %c, After: %c\n", ch, tolower(ch));
	return (0);
}
//*/