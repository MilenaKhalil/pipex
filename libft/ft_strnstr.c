/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:27:54 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/16 14:06:12 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		j = 0;
		i++;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[20];
	char b[20];
	char *t;
	strcpy(a, "ty");
	strcpy(b, "ty");
	t = strnstr(a, b, 0);
	printf("%s\n%s\n%s\n\n", a, b, t);
	
	strcpy(a, "ty");
	strcpy(b, "ty");
	t = ft_strnstr(a, b, 0);
	printf("%s\n%s\n%s\n", a, b, t);
	return 0;
}*/
