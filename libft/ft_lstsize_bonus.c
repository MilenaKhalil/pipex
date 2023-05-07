/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 16:09:48 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 16:25:58 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*k;

	if (!lst)
		return (0);
	i = 0;
	k = lst;
	while (k != 0)
	{
		k = k->next;
		i++;
	}
	return (i);
}
