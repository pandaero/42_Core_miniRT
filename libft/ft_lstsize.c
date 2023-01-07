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
Function determines the number of nodes in the linked list.
Returns the number of nodes. Returns 0 if invalid.
Checks not null, then navigates list until next is NULL.
*/
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*ptr;

	if (!lst)
		return (0);
	i = 1;
	ptr = lst;
	while (ptr->next != (void *) 0)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/* Test
//gcc -Wall -Werror -Wextra ft_lstsize.c ft_lstnew.c ft_lstadd_front.c && ./a.
#include <stdio.h>

int	main(void)
{
	t_list	*ptrlist;
	
	ptrlist = ft_lstnew((void *) 'a');
	printf("Number: 1, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'b'));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'c'));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'd'));
	printf("Number: 4, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	return (0);
}
//*/