/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:26:34 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/28 16:49:09 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dest);
	while (i + j + 1 < size && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	j = ft_strlen(src);
	if (i > size)
		return (j + size);
	return (i + j);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[40];
	char b[40];
	int i = 5;
	strcpy(a, "pouic");
	strcpy(b, "sis");
	i = strlcat(a, b, 3);
	printf("%s\n%s\n%d\n", a, b, i);
	
	strcpy(a, "pouic");
	strcpy(b, "sis");
	i = ft_strlcat(a, b, 3);
	printf("%s\n%s\n%d\n", a, b, i);
	return 0;
}*/
