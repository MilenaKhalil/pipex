/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:05:07 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/29 17:24:34 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*out;
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
	out = 0;
	i = 0;
	if (a == '\0')
		return (str + ft_strlen(str));
	while (s[i] != '\0')
	{
		if (s[i] == a)
			out = str + i;
		i++;
	}
	return (out);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[20];
	char c;
	char *t;
	strcpy(a, "teste");
	c = 'e';
	t = strrchr("teste", 'e' + 1024);
	printf("%s\n", t);
	
	strcpy(a, "teste");
	c = 'e';
	t = ft_strrchr("teste", 'e' + 1024);
	printf("%s\n", t);
	return 0;
}*/
