/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:46:18 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/04 20:12:24 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <unistd.h>
int main(int argc, char **argv)
{
	char k;
	(void) argc;
	k = ft_isdigit(argv[1][0]) + '0';
	write(1, &k, 1);
	return 0;
}*/
