/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:58:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 20:06:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function skips to the first non-space character within a char string.
int	skip_spacing(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_space(str[i]) == 1)
			i++;
		else
			return (i);
	}
	return (i);
}

/*
//Function determines whether a string contains a newline character.
static int	contains_newline(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
*/

//Function replaces all the non-newline spacing characters for space in string.
char	*replace_spacing(const char *str)
{
	char	*out;
	int		i;

	out = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (is_space(str[i]) == 1 && str[i] != '\n')
			out[i] = ' ';
		else
			out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	if (i == 0)
		out = ft_strdup(str);
	return (out);
}
