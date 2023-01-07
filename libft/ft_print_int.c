/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:04:29 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/28 20:34:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft.h"

//Function prints the minimum value for an integer type to the standard output.
static int	ft_print_int_min(void)
{
	int		count;

	count = write(1, "-2147483648", 11);
	return (count);
}

//Function works out the number of digits of an int.
static unsigned int	int_digs(int num)
{
	unsigned int	digs;

	digs = 0;
	if (num == 0)
		digs++;
	if (num < 0)
	{
		digs++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		digs++;
	}
	return (digs);
}

//Function handles special cases of the ft_print_int function.
static int	ft_print_int_special(int num)
{
	if (num == 0)
		return (ft_print_char('0'));
	if (num == INT_MIN)
		return (ft_print_int_min());
	return (0);
}

//Function prints an integer to standard output, unformatted. Returns written.
int	ft_print_int(int num)
{
	int		count;
	int		cpy;
	int		i;
	char	ch[11];

	if (num == INT_MIN || num == 0)
		return (ft_print_int_special(num));
	cpy = num;
	if (num < 0)
	{
		num = -num;
		ch[int_digs(num)] = '-';
	}
	i = 0;
	while (num > 0)
	{
		ch[i++] = num % 10 + '0';
		num /= 10;
	}
	if (cpy < 0)
		i++;
	count = 0;
	while (--i >= 0)
		count += ft_print_char(ch[i]);
	return (count);
}

/*Test
#include <stdio.h>

int	main(void)
{
	int	num;
	int	count;

	count = 0;
	num = INT_MAX;
	printf("Max Test\n");
	count = ft_print_int(num);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	num = 1345462;
	printf("Positive Test\n");
	count = ft_print_int(num);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	printf("Zero Test\n");
	num = 0;
	count = ft_print_int(num);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	num = -1345462;
	printf("Negative Test\n");
	count = ft_print_int(num);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	num = INT_MIN;
	printf("Min Test\n");
	count = ft_print_int(num);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	return (0);
}
//*/