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
Function moves a node to the end of a linked list. (Or at the back)
Returns nothing. The node will be located at the end of a linked list.
Check node is not already end, move to last using ft_lstlast and assign.
*/
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnd)
{
	if (*lst == (void *) 0)
		*lst = newnd;
	else
		ft_lstlast(*lst)->next = newnd;
}

/* Test
//gcc -Wall ft_lstadd_back.c ft_lstlast.c ft_lstnew.c ft_lstsize.c && ./a.out
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*ptrlist;

	ptrlist = ft_lstnew((void *) 'a');
	printf("Before -- Number: 1, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstadd_back(&ptrlist, ft_lstnew((void *) 'b'));
	ft_lstadd_back(&ptrlist, ft_lstnew((void *) 'c'));
	printf("After  -- Number: 3, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	return (0);
}
//*/