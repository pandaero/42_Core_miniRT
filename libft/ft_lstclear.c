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
Function clears an entire linked list.
Returns nothing, wipes a list's nodes' content.
Set a navigation pointer and a temporary clearing pointer, navigate and clear.
*/
#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_location;
	t_list	*ptr_clear;

	ptr_location = *lst;
	while (ptr_location != (void *) 0)
	{
		ptr_clear = ptr_location;
		ptr_location = ptr_location->next;
		ft_lstdelone(ptr_clear, del);
	}
	*lst = (void *) 0;
}

/* Test
//gcc -Wall -Werror -Wextra ft_lstclear.c ft_lstdelone.c ft_lstnew.c
//ft_lstadd_front.c ft_lstsize.c && ./a.out
#include <stdio.h>

int	main(void)
{
	t_list	*ptrlist;

	ptrlist = ft_lstnew(malloc(1));
	printf("Before      -- Number: 1, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstadd_front(&ptrlist, ft_lstnew(malloc(1)));
	ft_lstadd_front(&ptrlist, ft_lstnew(malloc(1)));
	printf("After       -- Number: 3, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstclear(&ptrlist, free);
	printf("After clear -- Number: ?, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	return (0);
}
//*/