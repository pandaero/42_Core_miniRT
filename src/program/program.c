/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:49:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 05:07:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates a new program data structure.
t_program	*program_create(void)
{
	t_program	*new;

	new = (t_program *)malloc(sizeof(t_program));
	if (!new)
		return (NULL);
	new->objlist = NULL;
	new->mldt = NULL;
	return (new);
}

//Function adds an object linked list to the program data structure.
void	program_add_obj_list(t_program *program, t_objlist *objlist)
{
	program->objlist = objlist;
}
