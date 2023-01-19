/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:12 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 23:48:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*
//Function creates a plane object from a valid input line.
t_obj	*object_plane_line(const char *line)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	return (new);
}
*/
//Function creates a sphere object from a valid input line.
t_obj	*object_sphere_line(const char *line)
{
	t_obj		*new;
	t_sphere	*sphere;

	new = object_create();
	if (!new)
		return (NULL);
	sphere = sphere_line(line);
	if (!sphere)
	{
		free_object(new);
		return (NULL);
	}
	new->elem = SPHERE;
	new->sphere = sphere;
	return (new);
}

//Function creates a cylinder object from a valid input line.
t_obj	*object_cylinder_line(const char *line)
{
	t_obj		*new;
	t_cylinder	*cylinder;

	new = object_create();
	if (!new)
		return (NULL);
	cylinder = cylinder_line(line);
	if (!cylinder)
	{
		free_object(new);
		return (NULL);
	}
	new->elem = CYLINDER;
	new->cylinder = cylinder;
	return (new);
}
