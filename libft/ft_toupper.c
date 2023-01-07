/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/18 02:48:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function takes a lowercase letter character and makes it an uppercase letter.
Result is the uppercase value for the input character.
Checks input, then ASCII offset is applied to give the uppercase value.
*/

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}

/* Test | gcc -Wall -Werror -Wextra ft_toupper.c && ./a.out
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	ch;

	ch = 'a';
	printf("Mine:\n");
	printf("Before: %c, After: %c\n", ch, ft_toupper(ch));
	printf("Library:\n");
	ch--;
	printf("Before: %c, After: %c\n", ch, toupper(ch));
	return (0);
}
//*/