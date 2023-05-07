/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 15:42:27 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/29 18:53:01 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strrev(char *str, size_t size)
{
	size_t	i;
	size_t	min;
	char	temp;

	min = 0;
	if (str[0] == '-')
		min = 1;
	i = min;
	while (i < size / 2 + min)
	{
		temp = str[i];
		str[i] = str[size - i - 1 + min];
		str[size - i - 1 + min] = temp;
		i++;
	}
}

char	*check(char *out, size_t *i, int *n)
{
	if (*n == 0)
	{
		out[0] = '0';
		*i = 1;
	}
	if (*n == INT_MIN)
	{
		ft_memcpy(out, "-2147483648", 12);
		*n = 0;
		*i = 12;
	}
	return (out);
}

int	siize(int n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*out;
	size_t	i;

	i = 0;
	out = malloc(sizeof(char) * siize(n));
	if (!out)
		return (0);
	out = check(out, &i, &n);
	if (n < 0)
	{
		i++;
		n *= -1;
		out[0] = '-';
	}
	while (n != 0)
	{
		out[i++] = n % 10 + '0';
		n /= 10;
	}
	if (i != 12)
	{
		strrev(out, i);
		out[i] = '\0';
	}
	return (out);
}
/*int main()
{
	int	n = -2147483648;
	char	*t = ft_itoa(n);
	printf("\nn = %d, out = %s, size = %d\n", n, t, siize(n));
	return 0;
}*/
