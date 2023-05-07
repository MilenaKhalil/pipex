/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 19:21:21 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/02 14:40:37 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*iter1;
	t_list	*new;

	lst2 = 0;
	iter1 = lst;
	while (iter1 != 0)
	{
		new = ft_lstnew(f(iter1->content));
		if (!new)
		{
			ft_lstclear(&lst2, del);
			return (0);
		}
		ft_lstadd_back(&lst2, new);
		iter1 = iter1->next;
	}
	return (lst2);
}
