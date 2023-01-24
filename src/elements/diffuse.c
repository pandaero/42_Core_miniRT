/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:55:26 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 19:00:26 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a new diffuse point-light.
t_diffuse	*diffuse_create(void)
{
	t_diffuse	*new;

	new = (t_diffuse *)malloc(sizeof(t_diffuse));
	if (!new)
		return (NULL);
	new->ratio = 0;
	new->position = NULL;
	return (new);
}

//Function creates a new diffuse point-light as a copy of another.
t_diffuse	*diffuse_copy(t_diffuse *light)
{
	t_diffuse	*new;

	new = diffuse_create();
	if (!new)
		return (NULL);
	new->ratio = light->ratio;
	new->position = point_copy(light->position);
	return (new);
}

//Function creates a new diffuse point-light from a valid input line.
t_diffuse	*diffuse_line(const char *line)
{
	t_diffuse	*new;
	char		**split;
	char		*clean;

	new = diffuse_create();
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
