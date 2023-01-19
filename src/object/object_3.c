/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 21:25:41 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function creates a cylinder object.
t_obj	*object_cylinder(t_cylinder *cylinder)
{
	t_obj	*new;

	new = object_create();
	new->elem = CYLINDER;
	new->cylinder = cylinder;
	return (new);
}

//Function creates a disc object.
t_obj	*object_disc(t_disc *disc)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = DISC;
	new->disc = disc;
	return (new);
}