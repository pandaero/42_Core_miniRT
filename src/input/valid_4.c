/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:02:00 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 16:28:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function determines whether a line contains valid cylinder description data.
int	valid_cylinder(const char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (split_size(split) != 6)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[1]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_point_dir(split[2]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_double(split[3]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_double(split[4]) == 0)
		return (free_split_ret_int_zero(split));
	if (valid_rgb(split[5]) == 0)
		return (free_split_ret_int_zero(split));
	free_split(split);
	return (1);
}

//Function determines whether a minimum no. of components are present in scene.
int	valid_elements(t_objlist *objlist)
{
	if (objlist_count_ambient(objlist) != 1)
	{
		ft_printf("Ambient count\n");
		return (0);
	}
	if (objlist_count_diffuse(objlist) > 1)
	{
		ft_printf("Light count\n");
		return (0);
	}
	if (objlist_count_camera(objlist) != 1)
	{
		ft_printf("Camera count\n");
		return (0);
	}
	if (!camera_objlist(objlist)->view_dir)
	{
		ft_printf("Camera direction\n");
		return (0);
	}
	if (objlist_plane_check_dir(objlist) == 0)
	{
		ft_printf("Plane normal\n");
		return (0);
	}
	if (objlist_cylinder_check_dir(objlist) == 0)
	{
		ft_printf("Cyl Orient\n");
		return (0);
	}
	return (1);
}
