/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:38:00 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/30 12:48:22 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return (str + i);
		i++;
	}
	if (a == '\0')
		return (str + i);
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
	char a[20];
	char c;
	char *t;
	strcpy(a, "figid");
	c = 'g';
	t = strchr(a, c);
	printf("%s\n", t);
	
	strcpy(a, "figid");
	c = 'g';
	t = ft_strchr(a, c);
	printf("%s\n", t);
	return 0;
}*/
