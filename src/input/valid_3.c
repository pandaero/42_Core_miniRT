/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:29:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 19:35:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function determines whether a line contains valid ambient light data.
int	valid_ambient(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	if (valid_rgb(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function determines whether a line contains valid light description data.
int	valid_diffuse(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 3)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[1]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_double(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function determines whether a line contains valid camera data.
int	valid_camera(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 4)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[1]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_double(split[3]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function determines whether a line contains valid plane description data.
int	valid_plane(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 4)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[1]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_rgb(split[3]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function determines whether a line contains valid sphere description data.
int	valid_sphere(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 4)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[1]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_double(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_rgb(split[3]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}
