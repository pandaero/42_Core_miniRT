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
Function moves a node to the beginning of a linked list. (Or in front)
Returns nothing. The node will be located at the front of a linked list.
Check that contents are non-null, assign NEW's NEXT to last 1st's, 1st to NEW.
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newnd)
{
	if (!lst || !newnd)
		return ;
	newnd->next = *lst;
	*lst = newnd;
}

/* Test
//gcc -Wall -Werror -Wextra ft_lstadd_front.c ft_lstnew.c ft_lstsize.c && ./a
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*ptrlist;
	
	ptrlist = ft_lstnew((void *) 'a');
	printf("Number: 1, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'b'));
	ft_lstadd_front(&ptrlist, ft_lstnew((void *) 'c'));
	printf("Number: 3, lstsize: ");
	printf("%d\n", ft_lstsize(ptrlist));
	return (0);
}
//*/