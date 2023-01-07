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
Function finds the last node of the linked list.
Returns a pointer to the last node of the list.
Assigns a pointer, then uses the NEXT part of the struct to navigate till end.
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next != (void *) 0)
		ptr = ptr->next;
	return (ptr);
}

/* Test
//gcc -Wall -Werror -Wextra ft_lstlast.c ft_lstnew.c ft_lstadd_front.c && ./a.
#include <stdio.h>

int	main(void)
{
	t_list	*ptrlist;

	ptrlist = ft_lstnew((void *) 'a');
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'b'));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'c'));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'd'));
	printf("Last Node: d, lstlast: ");
	printf("%c\n", *(char *) ft_lstlast(ptrlist));
	return (0);
}
//*/