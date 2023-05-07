/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 13:39:56 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/27 13:41:52 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)str1;
	s = (char *)str2;
	if (d == s)
		return (str1);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
		return (str1);
	}
	while (n--)
		*d++ = *s++;
	return (str1);
}
