/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 13:13:55 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/27 13:33:17 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	funk(unsigned int i, char *a)
{
	printf("a = %c\n", *a);
	*a = 'a';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		f((unsigned int)i, s + i);
		i++;
	}
}
/*int main()
{
	char *str = "Hjfjsu8-";
	printf("before = %s\n", str);
	ft_striteri(str, funk);
	printf("after = %s\n", str);
	return 0;
}*/
