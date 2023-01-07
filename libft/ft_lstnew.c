/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_template.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:13:03 by pandalaf          #+#    #+#             */
/*   Updated: 2022/05/20 13:08:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function creates a new node with content in the linked list.
Returns a pointer to a new node. A new node is last, so NEXT contains NULL.
Declare a pointer to the list type, then write to its struct components.
*/
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return ((void *) 0);
	ptr->content = content;
	ptr->next = (void *) 0;
	return (ptr);
}

/* Test | gcc -Wall -Werror -Wextra ft_lstnew.c && ./a.out | cat -e
#include <stdio.h>

int	main(void)
{
	void	*ptrlist;
	
	ptrlist = ft_lstnew((void *) 'h');
	printf("Input Content: %c, List Content: ", 'h');
	printf("%c", *(char *) ptrlist);
	printf("\n");
	return (0);
}
//*/