/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:20:45 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/19 15:20:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#if defined (__APPLE__)
# define OS_PTR_MSG "0x0"
#else
# define OS_PTR_MSG "(nil)"
#endif

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

//Function prints a hexadecimal number with long long type.
int	ft_print_hex_long(unsigned long long int num, int cas)
{
	int		count;
	int		i;
	char	ch[16];

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
	unsigned long long	hex;
	int					count;
	int					cas;

	cas = 0;
	count = 0;
	hex = ULLONG_MAX;
	printf("Max Test\n");
	count = ft_print_hex_long(hex, cas);
	printf("\nCount: %d\n", count);
	hex = 1235443;
	printf("Positive Test\n");
	count = ft_print_hex_long(hex, cas);
	printf("\nCount: %d\n", count);
	hex = 0;
	printf("Zero Test\n");
	count = ft_print_hex_long(hex, cas);
	printf("\nCount: %d\n", count);
	return (0);
}
//*/

//Function prints an pointer address to standard output, unformatted.
int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = ft_print_str(OS_PTR_MSG);
		return (count);
	}
	count += hex_prefix_printer(1);
	count += ft_print_hex_long((unsigned long long) ptr, 1);
	return (count);
}

/*Test
#include <stdio.h>

int	main(void)
{
	char	*ptr = "You\n";
	void	*vptr = 0;

	ft_print_ptr(vptr);
	ft_print_char('\n');
	printf("Null ptr: %p\n", vptr);
	ft_print_ptr(ptr);
	ft_print_char('\n');
	return (0);
}
//*/