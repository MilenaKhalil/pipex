/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 12:59:22 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/28 16:17:06 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	funk(unsigned int i, char c)
{
	char a = c;
	a = (c + i) % 128;
	if (!ft_isprint(a))
		a = (a + 50) % 128;
	return (a);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	size_t	i;

	t = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!t)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		t[i] = f((unsigned int)i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
