/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:25:11 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/28 20:35:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Function prints an unsigned integer to standard output, unformatted.
int	ft_print_unsigned(unsigned int num)
{
	int		count;
	int		i;
	char	ch[10];

	count = 0;
	if (num == 0)
		return (ft_print_char('0'));
	i = 0;
	while (num > 0)
	{
		ch[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
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
	unsigned int	unum;
	int				count;

	count = 0;
	unum = UINT_MAX;
	printf("Max Test\n");
	count = ft_print_unsigned(unum);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	unum = 76543;
	printf("Positive Test\n");
	count = ft_print_unsigned(unum);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	printf("Zero Test\n");
	unum = 0;
	count = ft_print_unsigned(unum);
	ft_print_char('\n');
	printf("Count: %d\n", count);
	return (0);
}
//*/