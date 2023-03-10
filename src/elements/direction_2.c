/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:56:51 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/16 21:44:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a split 2D array and a string.
static void	*free_split_void_ret_null(char **split, char *str)
{
	free_split(split);
	free(str);
	return (NULL);
}

//Function creates a direction from a valid input string.
t_direction	*direction_str(const char *str)
{
	t_direction	*direction;
	char		**split;
	char		*clean_z;
	double		mag;

	direction = direction_create();
	if (!direction)
		return (NULL);
	split = ft_split(str, ',');
	if (contains_newline(split[2]) == 1)
		clean_z = clean_newline(split[2]);
	else
		clean_z = ft_strdup(split[2]);
	mag = magnitude_components(ft_atof(split[0]), ft_atof(split[1]), \
		ft_atof(clean_z));
	if (mag == 0)
		return (free_split_void_ret_null(split, clean_z));
	direction->x_comp = ft_atof(split[0]) / mag;
	direction->y_comp = ft_atof(split[1]) / mag;
	direction->z_comp = ft_atof(clean_z) / mag;
	free_split(split);
	free(clean_z);
	return (direction);
}

//Function creates a reverse direction from an input one.
t_direction	*direction_reverse(t_direction *original)
{
	t_direction	*new;

	new = direction_create();
	if (!new)
		return (NULL);
	new->x_comp = -original->x_comp;
	new->y_comp = -original->y_comp;
	new->z_comp = -original->z_comp;
	return (new);
}
