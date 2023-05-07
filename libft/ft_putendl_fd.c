/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:40:32 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/12 16:48:43 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	y;

	i = 0;
	while (s[i] != '\0')
	{
		y = s[i];
		write(fd, &y, 1);
		i++;
	}
	write(fd, "\n", 1);
}
