/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:25:22 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/02 14:21:34 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*out;

	i = 0;
	k = (int)(ft_strlen(s1));
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[k]) && k)
		k--;
	if (i > k || (i == 0 && k == 0))
		k = i - 1;
	out = malloc(sizeof(char) * (k - i + 2));
	if (!out)
		return (0);
	j = i;
	while (i <= k)
	{
		out[i - j] = s1[i];
		i++;
	}
	out[i - j] = '\0';
	return (out);
}
/*int main()
{
	char const *a = "";
	char const *b = "";
	printf("out = %s\n", ft_strtrim(a, b));
	return 0;
}*/
