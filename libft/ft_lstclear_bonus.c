/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:49:39 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/02 12:51:44 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;
	t_list	*temp;

	if (!lst)
		return ;
	iter = *lst;
	while (iter != 0)
	{
		temp = iter->next;
		del(iter->content);
		free(iter);
		iter = temp;
	}
	*lst = 0;
}
