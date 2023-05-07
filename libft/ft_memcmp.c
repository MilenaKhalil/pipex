/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:15:44 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/29 17:04:30 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	size_t			j;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	j = 0;
	i = 0;
	while (j < n)
	{
		i = a[j] - b[j];
		if (a[j] != b[j])
			break ;
		j++;
	}
	return (i);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[50] = "aaaaaa0aaaaa";
	char b[50] = "aaaaaaaaaaaaaaaaaa";
	int t;

	t = memcmp(a, b, 6);
	printf("%d\n", t);
	
	t = ft_memcmp(a, b, 6);
	printf("\n%d\n", t);
	return 0;
}*/
