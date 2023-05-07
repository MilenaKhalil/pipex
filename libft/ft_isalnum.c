/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:47:57 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/04 20:54:01 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*#include <unistd.h>
int main(int argc, char **argv)
{
	char k;
	(void) argc;
	k = ft_isalnum(argv[1][0]) + '0';
	write(1, &k, 1);
	return 0;
}*/
