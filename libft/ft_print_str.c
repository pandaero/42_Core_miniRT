/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 12:27:07 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/28 20:35:08 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

//Function prints a char string to standard output, unformatted.
int	ft_print_str(const char *str)
{
	int	count;
	int	i;

	count = 0;
	if (!str)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	i = 0;
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

/*Test
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Fifty\n";

	ft_print_str(s1);
	return (0);
}
//*/