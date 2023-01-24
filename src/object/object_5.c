/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:15:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 16:34:46 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function makes an ambient light object.
t_obj	*object_ambient(t_ambient *ambient)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = AMBIENT;
	new->ambient = ambient;
	return (new);
}
