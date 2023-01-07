/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:13:51 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/28 20:35:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

//Function calls format printers for writing to standard output by type.
static int	converter(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'd' || type == 'i')
		count = ft_print_int(va_arg(args, int));
	else if (type == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (type == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (type == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (type == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (type == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 0);
	return (count);
}

//Function begins an interpretation by the converter according to the start pos.
static int	interpreter(va_list args, int start, const char *format)
{
	int		count;
	char	type;

	count = 0;
	if (format[start + 1] == '%')
	{
		count += ft_print_char('%');
		return (count);
	}
	type = type_reader(format, start);
	count += converter(args, type);
	return (count);
}

//Function writes out input-based formatted string. Returns written char count.
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += interpreter(args, i, format);
			i += 1;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
