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
Function maps a function to every node's content in a linked list.
Returns the new list.
Create a new node with the function applied to each content. Keep adding nodes.
*/
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*ptrlist_new;
	t_list		*ptrlist_node;
	t_list		*ptrlist_placeholder;

	ptrlist_new = ft_lstnew((*f)(lst->content));
	if (!ptrlist_new)
		return ((void *) 0);
	ptrlist_placeholder = ptrlist_new;
	while (lst->next != (void *) 0)
	{
		lst = lst->next;
		ptrlist_node = ft_lstnew((*f)(lst->content));
		if (!ptrlist_node)
		{
			ft_lstclear(&ptrlist_placeholder, del);
			return ((void *) 0);
		}
		ft_lstadd_back(&ptrlist_new, ptrlist_node);
	}
	return (ptrlist_new);
}

/* Test | gcc -Wall -Werror -Wextra ft_template.c && ./a.out
#include <stdio.h>

int	main(void)
{
	return (0);
}
//*/