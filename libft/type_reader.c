/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:15:27 by pandalaf          #+#    #+#             */
/*   Updated: 2022/09/26 07:14:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Function identifies the format types. Returns 1 or 0.
int	type_checker(char ch)
{
	if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'x')
		return (1);
	else if (ch == 'd' || ch == 'i' || ch == 'u' || ch == 'X')
		return (1);
	return (0);
}

//Function reads a type specifier after a determined starting location.
char	type_reader(const char *string, int start)
{
	int	i;

	i = 0;
	while (type_checker(string[start + i]) == 0)
		i++;
	return (string[start + i]);
}
