/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:49:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:08:46 by pandalaf         ###   ########.fr       */
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
