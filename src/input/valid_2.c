/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:13:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 20:14:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function checks an input line for validity.
int	check_valid_line(const char *line)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	ret = 1;
	if (ft_strncmp(split[0], "A", 2) == 0)
		ret = valid_ambient(line);
	// if (ft_strncmp(split[i], "C", 2) == 0)
	// 	ret = valid_camera();
	// if (ft_strncmp(split[i], "L", 2) == 0)
	// 	ret = valid_light();
	// if (ft_strncmp(split[i], "pl", 3) == 0)
	// 	ret = valid_plane();
	// if (ft_strncmp(split[i], "sp", 3) == 0)
	// 	ret = valid_sphere();
	// if (ft_strncmp(split[i], "cy", 3) == 0)
	// 	ret = valid_cylinder();
	free_split(split);
	return (ret);
}

//Function determines whether a line contains valid ambient light data.
int	valid_ambient(const char *str)
{
	char	**split;
	char	**ssplit;
	int		ret;

	ret = 1;
	split = ft_split(str, ' ');
	if (split_size(split) != 3)
		return (0);
	ssplit = ft_split(split[2], ',');
	if (valid_atof(split[1]) == 0)
		ret = 0;
	if (split_size(ssplit) != 3)
		ret = 0;
	if (ft_atoi(ssplit[0]) == -1 || ft_atoi(ssplit[1]) == -1 || \
			ft_atoi(ssplit[2]) == -1)
		ret = 0;
	free_split(split);
	free_split(ssplit);
	return (ret);
}

//Function determines whether a line contains valid camera data.
//Function determines whether a line contains valid light description data.
//Function determines whether a line contains valid plane description data.
//Function determines whether a line contains valid sphere description data.
//Function determines whether a line contains valid cylinder description data.
//Function determines whether a minimum no. of components are present in scene.
