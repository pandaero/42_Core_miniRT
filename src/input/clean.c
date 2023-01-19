/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:58:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 17:31:07 by pandalaf         ###   ########.fr       */
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

//Function determines whether a string contains a newline character.
int	contains_newline(const char *str)
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

//Function replaces all the non-newline spacing characters for space in string.
char	*replace_spacing(const char *str)
{
	char	*out;
	int		i;

	out = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
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

//Function performs the filling of the new string in the clean_newline function.
void	assist_clean_newline(const char *str, char *new)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
}

//Function removes newline characters from a string. Returns a new string.
char	*clean_newline(const char *str)
{
	char	*new;
	int		ct;
	int		i;

	ct = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			ct++;
		i++;
	}
	if (ct == 0)
		return (ft_strdup(str));
	new = (char *)malloc((ft_strlen(str) - ct + 1) * sizeof(char));
	assist_clean_newline(str, new);
	return (new);
}
