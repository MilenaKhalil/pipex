/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:32:37 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/10/28 15:44:32 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*out;

	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		out[i + j] = s2[j];
		j++;
	}
	out[i + j] = '\0';
	return (out);
}
/*#include <string.h>
int main()
{
	char const	*a = "";
	char const	*b = "";

	printf("%s\n", strjoin(a, b));
	return 0;
}*/
