/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 16:42:25 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 14:57:48 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
/*#include <string.h>
int main()
{
	char a[100] = "qwiqqqe", a1[100] = "qwe";
	//char b[100] = "", b1[100] = "";
	//int i = 0, i1 = 0, n = 2;
	//i = strlcpy(a, b, n);
	//i1 = ft_strlcpy(a1, b1, n);
	ft_strlcpy(a, a1, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	return (0);
}*/
