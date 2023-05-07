/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 20:42:01 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/25 15:56:03 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
	char k;
	(void) argc;
	k = ft_strlen(argv[1]) + '0';
	write(1, &k, 1);
	return 0;
}*/
