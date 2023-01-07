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
Function applies a function to each of the linked list's nodes.
Returns nothing. Applies a function to every node on the list.
Applies function on content, sets next for navigation loop.
*/
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != (void *) 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* Test | gcc -Wall -Werror -Wextra ft_template.c && ./a.out
#include <stdio.h>

void addone(void *p)
{
	p += *(int *) 2;
}

int	main(void)
{
	t_list	*ptrlist;

	ptrlist = ft_lstnew((void *) 5);
	printf("Input Content: %d, List Content: ", 5);
	printf("%d\n", *(int *) ptrlist);
	ft_lstiter(ptrlist, addone);
	printf("Content After: %c, List Content: ", 6);
	printf("%d\n", *(int *) ptrlist);
	return (0);
}
//*/