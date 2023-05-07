/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 13:38:14 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 15:55:03 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = content;
	return (new);
}
/*int main()
{
	struct s_list *test;
	void	k;
	void	*content = &k;

	test = ft_lstnew(content);
	printf("test->next = %s, test->content = %s\n", test->next, test->content);
}*/
