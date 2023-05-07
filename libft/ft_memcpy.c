/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:48:57 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/28 16:48:37 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (dst == 0 && src == 0)
		return (dst);
	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char *a = "sjd";
	char *b = "sjd";
	char *c = 0;
	void *t;

	t = memcpy(a, c, 0);
	printf("%s\n%p\n", a, t);
	
	t = ft_memcpy(b, c, 0);
	printf("\n%s\n%p\n", b, t);
	return 0;
}*/
