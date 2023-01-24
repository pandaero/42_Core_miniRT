/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:55:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 23:03:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a new light.
t_light	*light_create(void)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->ratio = 0;
	new->colour = 0x00FFFFFF;
	new->position = NULL;
	return (new);
}

//Function creates a new light as a copy of another.
t_light	*light_copy(t_light *light)
{
	t_light	*new;

	new = light_create();
	if (!new)
		return (NULL);
	new->ratio = light->ratio;
	new->colour = light->colour;
	new->position = point_copy(light->position);
	return (new);
}

//Function creates a new light from a valid input line.
t_light	*light_line(const char *line)
{
	t_light	*new;
	char	**split;
	char	*clean;

	new = light_create();
	if (!new)
		return (NULL);
	if (contains_newline(line) == 1)
	{
		clean = clean_newline(line);
		split = ft_split(clean, ' ');
		free(clean);
	}
	else
		split = ft_split(line, ' ');
	new->ratio = ft_atof(split[2]);
	new->position = point_str(split[1]);
	free_split(split);
	return (new);
}
