/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 20:59:40 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 14:16:37 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			j;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	j = 0;
	while (j < n)
	{
		if (a[j] > b[j])
			return (1);
		else if (a[j] < b[j])
			return (-1);
		if (a[j] == '\0' || b[j] == '\0')
			break ;
		j++;
	}
	return (0);
}
/*#include <string.h>
int main()
{
	const char *s1 = "test\200";
	const char *s2 = "test\0";
	int i1, i2, n = 6;
	i1 = strncmp(s1, s2, n);
	i2 = ft_strncmp(s1, s2, n);
	printf("or = %d\nmy = %d\n", i1, i2);
	return 0;
}*/
