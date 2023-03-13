/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:13:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 01:52:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function checks whether string contains characters allowed as input for atof.
int	valid_str_atof(const char *str)
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

//Function checks an input line for validity.
int	check_valid_line(const char *line)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	if (split_size(split) == 2)
		return(free_split_ret_int_zero(split));
	ret = 1;
	if (ft_strncmp(split[0], "A", 2) == 0)
		ret = valid_ambient(line);
	if (ft_strncmp(split[0], "C", 2) == 0)
		ret = valid_camera(line);
	if (ft_strncmp(split[0], "L", 2) == 0)
		ret = valid_diffuse(line);
	if (ft_strncmp(split[0], "pl", 3) == 0)
		ret = valid_plane(line);
	if (ft_strncmp(split[0], "sp", 3) == 0)
		ret = valid_sphere(line);
	if (ft_strncmp(split[0], "cy", 3) == 0)
		ret = valid_cylinder(line);
	free_split(split);
	return (ret);
}

//Function checks that a string contains valid RGB input.
int	valid_rgb(const char *str)
{
	char	**split;
	char	*clean;

	if (contains_newline(str) == 1)
	{
		clean = clean_newline(str);
		split = ft_split(clean, ',');
		free(clean);
	}
	else
		split = ft_split(str, ',');
	if (!split)
		return (free_split_ret_int_zero(split));
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	if (ft_atoi(split[0]) < 0 || ft_atoi(split[1]) < 0 || \
			ft_atoi(split[2]) < 0)
		return (free_split_ret_int_zero(split));
	if (ft_atoi(split[0]) > 255 || ft_atoi(split[1]) > 255 || \
			ft_atoi(split[2]) > 255)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function checks that a string contains valid input for a point or direction.
int	valid_point_dir(const char *str)
{
	char	**split;
	char	*clean;

	if (contains_newline(str) == 1)
	{
		clean = clean_newline(str);
		split = ft_split(clean, ',');
		free(clean);
	}
	else
		split = ft_split(str, ',');
	if (!split)
		return (free_split_ret_int_zero(split));
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	if (valid_atof(split[0]) == 0 || valid_atof(split[1]) == 0 || \
			valid_atof(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function checks that a string contains valid input for a double.
int	valid_double(const char *str)
{
	char	*clean;

	if (contains_newline(str) == 1)
	{
		clean = clean_newline(str);
		if (valid_atof(clean) == 0)
		{
			free(clean);
			return (0);
		}
		free(clean);
	}
	else if (valid_atof(str) == 0)
		return (0);
	else
		return (1);
	return (1);
}
