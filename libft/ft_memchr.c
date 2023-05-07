/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:31:56 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/29 17:28:08 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	a;

	a = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[20];
	int c;
	void *t;
	strcpy(a, "dhfufh");
	c = '9';
	t = memchr(a, c, 20);
	printf("%s\n", t);
	
	strcpy(a, "dhfufh");
	c = '9';
	t = ft_memchr(a, c, 20);
	printf("%s\n", t);
	return 0;
}*/
