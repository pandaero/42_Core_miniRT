/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:20:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 16:50:44 by pandalaf         ###   ########.fr       */
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
