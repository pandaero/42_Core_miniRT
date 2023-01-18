/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:20:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 20:14:30 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function checks whether a character is a spacing character.
int	is_space(char ch)
{
	if (ch == ' ' || (ch > 8 && ch < 14))
		return (1);
	return (0);
}

//Function checks whether a character is allowed in an input file.
int	is_valid_char(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == 'A' || ch == 'C' || ch == 'L')
		return (1);
	if (ch == 's' || ch == 'p' || ch == 'l' || ch == 'c' || ch == 'y')
		return (1);
	if (ch == '.' || ch == ',' || ch == '-' || ch == '+')
		return (1);
	if (is_space(ch) == 1)
		return (1);
	return (0);
}

//Function counts the number of period characters in a string.
static int	num_period(const char *str)
{
	int	ct;
	int	i;

	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			ct++;
		i++;
	}
	return (ct);
}

//Function counts the number of numeric sign characters in a string.
static int	num_sign(const char *str)
{
	int	ct;
	int	i;

	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			ct++;
		i++;
	}
	return (ct);
}

//Function determines whether a string is valid input for the atof function.
int	valid_atof(const char *str)
{
	if (num_period(str) > 1)
		return (0);
	if (num_sign(str) > 1)
		return (0);
	if (num_sign(str) == 1 && !(str[0] == '+' || str[0] == '-'))
		return (0);
	return (1);
}
