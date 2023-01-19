/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:56:51 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 21:20:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a direction from a valid input string.
t_direction	*direction_line(const char *str)
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
	direction->x_comp = ft_atof(split[0]) / mag;
	direction->y_comp = ft_atof(split[1]) / mag;
	direction->z_comp = ft_atof(clean_z) / mag;
	free_split(split);
	free(clean_z);
	return (direction);
}
