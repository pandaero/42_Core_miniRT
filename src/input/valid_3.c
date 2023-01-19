/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:29:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 18:31:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function checks whether string contains characters allowed as input for atof.
int	is_valid_str_atof(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || \
				str[i] == '-' || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

//Function works out portion of valid camera parsing.
static int	assist2_valid_camera(char **split)
{
	char	**dirsplit;
	int		ret;

	ret = 1;
	dirsplit = ft_split(split[2], ',');
	if (split_size(dirsplit) != 3)
		ret = 0;
	if (ret == 1)
	{
		if (valid_atof(dirsplit[0]) == 0 || valid_atof(dirsplit[1]) == 0 || \
				valid_atof(dirsplit[2]) == 0)
			ret = 0;
	}
	free_split(dirsplit);
	return (ret);
}

//Function works out portion of valid camera parsing.
static int	assist1_valid_camera(char **split)
{
	char	**ptsplit;
	int		ret;

	ret = 1;
	ptsplit = ft_split(split[1], ',');
	if (split_size(ptsplit) != 3)
		ret = 0;
	if (ret == 1)
	{
		if (valid_atof(ptsplit[0]) == 0 || valid_atof(ptsplit[1]) == 0 || \
			valid_atof(ptsplit[2]) == 0)
			ret = 0;
		else
		ret = assist2_valid_camera(split);
	}
	free_split(ptsplit);
	return (ret);
}

//Function determines whether a line contains valid camera data.
int	valid_camera(const char *str)
{
	char	**split;
	char	*clean_double;
	int		ret;

	ret = 1;
	split = ft_split(str, ' ');
	if (split_size(split) != 4)
		return (free_split_ret_int_zero(split));
	if (contains_newline(split[3]) == 1)
	{
		clean_double = clean_newline(split[3]);
		if (valid_atof(clean_double) == 0)
			ret = 0;
		free(clean_double);
	}
	else if (valid_atof(split[3]) == 0)
		ret = 0;
	else
		ret = 1;
	if (ret == 1)
		ret = assist1_valid_camera(split);
	free_split(split);
	return (ret);
}

//Function determines whether a line contains valid plane description data.
//Function determines whether a line contains valid sphere description data.
//Function determines whether a line contains valid cylinder description data.
//Function determines whether a minimum no. of components are present in scene.
