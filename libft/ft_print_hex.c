/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:30:49 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/28 20:34:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Function prints a hexadecimal prefix to the standard output.
int	hex_prefix_printer(int cas)
{
	int	count;

	count = 0;
	if (cas != 0 && cas != 1)
		return (0);
	count += ft_print_char('0');
	if (cas == 0)
		count += ft_print_char('X');
	if (cas == 1)
		count += ft_print_char('x');
	return (count);
}

//Function converts a hexadecimal value to base 16 character. Case is toggled.
static int	hex_digit_printer(int num, int cas)
{
	if (cas != 0 && cas != 1)
		return (0);
	if (num >= 10 && num <= 15 && cas == 0)
		return (num + 'A' - 10);
	else if (num >= 10 && num <= 15 && cas == 1)
		return (num + 'a' - 10);
	else
		return (num + '0');
}

//Function prints out a hexadecimal number in either upper or lowercase.
int	ft_print_hex(unsigned int num, int cas)
{
	int		count;
	int		i;
	char	ch[8];

	if (num == 0)
		return (ft_print_char('0'));
	i = 0;
	while (num > 0)
	{
		ch[i] = hex_digit_printer(num % 16, cas);
		num /= 16;
		i++;
	}
	i--;
	count = 0;
	while (i >= 0)
	{
		count += ft_print_char(ch[i]);
		i--;
	}
	return (count);
}

/*Test
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	unsigned int	hex;
	int				count;
	int				cas;

	cas = 0;
	count = 0;
	hex = UINT_MAX;
	printf("Max Test\n");
	count = ft_print_hex(hex, cas);
	printf("\nCount: %d\n", count);
	hex = 1235443;
	printf("Positive Test\n");
	count = ft_print_hex(hex, cas);
	printf("\nCount: %d\n", count);
	hex = 0;
	printf("Zero Test\n");
	count = ft_print_hex(hex, cas);
	printf("\nCount: %d\n", count);
	return (0);
}
//*/