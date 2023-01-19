/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:13:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 18:43:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function checks an input line for validity.
int	check_valid_line(const char *line)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	ret = 1;
	if (ft_strncmp(split[0], "A", 2) == 0)
		ret = valid_ambient(line);
	if (ft_strncmp(split[0], "C", 2) == 0)
		ret = valid_camera(line);
	if (ft_strncmp(split[0], "L", 2) == 0)
		ret = valid_light(line);
	// if (ft_strncmp(split[0], "pl", 3) == 0)
	// 	ret = valid_plane(line);
	// if (ft_strncmp(split[0], "sp", 3) == 0)
	// 	ret = valid_sphere(line);
	// if (ft_strncmp(split[0], "cy", 3) == 0)
	// 	ret = valid_cylinder(line);
	free_split(split);
	return (ret);
}

//Function works out portion of valid ambient light parsing.
static int	assist_valid_ambient(char **colsplit)
{
	int	ret;

	ret = 1;
	if (ft_atoi(colsplit[0]) < 0 || ft_atoi(colsplit[1]) < 0 || \
			ft_atoi(colsplit[2]) < 0)
		ret = 0;
	if (ft_atoi(colsplit[0]) > 255 || ft_atoi(colsplit[1]) > 255 || \
			ft_atoi(colsplit[2]) > 255)
		ret = 0;
	return (ret);
}

//Function determines whether a line contains valid ambient light data.
int	valid_ambient(const char *str)
{
	char	**split;
	char	**colsplit;
	int		ret;

	ret = 1;
	split = ft_split(str, ' ');
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	colsplit = ft_split(split[2], ',');
	if (valid_atof(split[1]) == 0)
		ret = 0;
	if (split_size(colsplit) != 3)
		ret = 0;
	if (ret == 1)
		ret = assist_valid_ambient(colsplit);
	free_split(split);
	free_split(colsplit);
	return (ret);
}

//Function works out portion of valid light parsing.
static int	assist_valid_light(char **split)
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
	}
	free_split(ptsplit);
	return (ret);
}

//Function determines whether a line contains valid light description data.
int	valid_light(const char *str)
{
	char	**split;
	char	*clean_double;
	int		ret;

	ret = 1;
	split = ft_split(str, ' ');
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	if (contains_newline(split[2]) == 1)
	{
		clean_double = clean_newline(split[2]);
		if (valid_atof(clean_double) == 0)
			ret = 0;
		free(clean_double);
	}
	else if (valid_atof(split[2]) == 0)
		ret = 0;
	else
		ret = 1;
	if (ret == 1)
		assist_valid_light(split);
	free_split(split);
	return (ret);
}
