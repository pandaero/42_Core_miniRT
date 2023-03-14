/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:02:14 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 09:06:33 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function frees a screen.
void	free_screen(t_screen *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			free_void(screen->pixels[i][j]);
			j++;
		}
		free_void(screen->pixels[i]);
		i++;
	}
	free_void(screen->pixels);
}

//Function frees an entire object linked list.
void	free_list(t_objlist *list)
{
	t_obj	*curr;
	t_obj	*next;

	curr = list->first;
	while (curr != NULL)
	{
		next = curr->next;
		free_void(curr);
		curr = next;
	}
	free_void(list);
}

//Function frees the program struct.
void	free_program(t_program *program)
{
	if (program->objlist)
	{
		if (screen_program(program))
			free_screen(screen_program(program));
		free_list(program->objlist);
	}
}
