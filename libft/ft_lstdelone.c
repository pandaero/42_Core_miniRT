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
Function deletes a node from a linked list.
Returns nothing. Deletes a node from a linked list.
Makes delete function act on the node's content, then free's ex-allocated space.
*/
#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

/* Test
//gcc -Wall -Werror -Wextra ft_lstdelone.c ft_lstadd_front.c ft_lstnew.c 
//ft_lstsize.c && ./a.out
#include <stdio.h>

int	main(void)
{	
	t_list	*ptrlist;

	ptrlist = ft_lstnew(malloc(1));
	printf("Before    -- Number: 1, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'b'));
	ft_lstadd_front(&ptrlist, ft_lstnew(malloc(1)));
	printf("After     -- Number: 3, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstdelone(ptrlist, free);
	printf("After del -- Number: 2, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	return (0);
}
//*/