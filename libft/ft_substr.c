/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:14:28 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 14:58:32 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
/*int main()
{
	char const	*a = "\0yyy";
	char *out = ft_substr(a, 0, 3);
	return 0;
}*/
