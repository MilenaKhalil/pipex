/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 19:46:25 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/04 20:12:42 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*#include <unistd.h>
int main(int argc, char **argv)
{
	char k;
	(void) argc;
	k = ft_isalpha(argv[1][0]) + '0';
	write(1, &k, 1);
	return 0;
}*/
