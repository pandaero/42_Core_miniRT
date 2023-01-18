/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:58:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 17:27:38 by pandalaf         ###   ########.fr       */
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
		if (is_space(str[i]) == 1 && i != (int)ft_strlen(str) - 1)
			out[i] = ' ';
		else if (i != (int)ft_strlen(str) - 1)
			out[i] = str[i];
		else
			out[i] = '\0';
		i++;
	}
	if (i == 0)
		out = ft_strdup(str);
	return (out);
}
