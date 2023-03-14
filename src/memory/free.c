/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 02:17:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a pointer and returns NULL.
void	*free_void_null(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

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
			free(screen->pixels[i][j]);
			j++;
		}
		free(screen->pixels[i]);
		i++;
	}
	free(screen->pixels);
	screen = NULL;
}

//Function frees a 2D char array made from ft_split. Returns zero.
int	free_split_ret_int_zero(char **charr)
{
	free_split(charr);
	return (0);
}

//Function frees a pointer, and returns a double -1.
double	free_ret_double_minusone(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return ((double) -1);
}

//Function frees a 2D char array made from ft_split.
void	free_split(char **charr)
{
	int	i;

	i = 0;
	while (charr[i])
	{
		free(charr[i]);
		i++;
	}
	free(charr);
	charr = NULL;
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

//Function frees an entire object linked list.
void	free_list(t_objlist *list)
{
	t_obj	*curr;
	t_obj	*next;

	curr = list->first;
	while (curr != NULL)
	{
		next = curr->next;
		free_object(curr);
		curr = next;
	}
	free(list);
	list = NULL;
}

//Function frees an object.
void	free_object(t_obj *object)
{
	if (object)
		free(object);
	object = NULL;
}
