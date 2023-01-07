/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/23 15:32:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function interprets a character string to return an integer type (16-bit).
Returns the integer value of the decimal integer quantity in the string.
Interprets sign. When digits, starts to sum values with base until the end.
*/
#include "libft.h"

//Function determines whether character is a spacing character.
static int	ft_isspace(int ch)
{
	if (ch == ' ')
		return (1);
	else if (ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long unsigned int	sum;
	int						sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if (sum > 9223372036854775807)
			return (-1);
	}
	return ((int) sign * sum);
}

/* Test | gcc -Wall -Werror -Wextra ft_atoi.c && ./a.out
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	a[] = "+9223372036854775808lasdf";
	char	a32[] = "+4294967296lasdf";
	char	a32_p1[] = "+4294967297lasdf";
	char	a64[] = "+9223372036854775807lasdf";
	char	a64_p1[] = "+9223372036854775818lasdf";

	printf("Test- str:%s, out:%d\n", a, ft_atoi(a));
	printf("Test- str:%s, out:%d\n", a, atoi(a));
	printf("T32 - str:%s         , out:%d\n", a32, ft_atoi(a32));
	printf("T32 - str:%s         , out:%d\n", a32, atoi(a32));
	printf("T32+- str:%s         , out:%d\n", a32_p1, ft_atoi(a32_p1));
	printf("T32+- str:%s         , out:%d\n", a32_p1, atoi(a32_p1));
	printf("T64 - str:%s, out:%d\n", a64, ft_atoi(a64));
	printf("T64 - str:%s, out:%d\n", a64, atoi(a64));
	printf("T64+- str:%s, out:%d\n", a64_p1, ft_atoi(a64_p1));
	printf("T64+- str:%s, out:%d\n", a64_p1, atoi(a64_p1));
	return (0);
}
//*/