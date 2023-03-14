/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 09:06:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a pointer.
void	free_void(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

//Function frees a pointer and returns NULL.
void	*free_void_null(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

//Function frees a pointer, and returns a double -1.
double	free_ret_double_minusone(void *ptr)
{
	free_void(ptr);
	return ((double) -1);
}

//Function frees a 2D char array made from ft_split. Returns zero.
int	free_split_ret_int_zero(char **charr)
{
	free_split(charr);
	return (0);
}

//Function frees a 2D char array made from ft_split.
void	free_split(char **charr)
{
	int	i;

	i = 0;
	while (charr[i])
	{
		free_void(charr[i]);
		i++;
	}
	free_void(charr);
	charr = NULL;
}
