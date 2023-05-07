/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:16:36 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/14 17:47:36 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		return (write (fd, "-2147483648", 11));
	if (n < 0)
		return (ft_putchar_fd('-', fd) + ft_putnbr_fd(n * -1, fd));
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	c = n % 10 + '0';
	return (ft_putnbr_fd(n / 10, fd) + ft_putchar_fd(c, fd));
}
/*int main()
{
	int i = ft_putnbr_fd(3, 1);
	printf("\n%d\n", i);
	return 0;
}*/
