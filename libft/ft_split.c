/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 18:40:14 by mikhalil      #+#    #+#                 */
/*   Updated: 2022/11/01 13:57:52 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_words(char const *s, char c)
{
	size_t	i;
	int		num;

	i = 0;
	num = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	while (1)
	{
		if (s[i] == c || s[i] == '\0')
		{
			num++;
			if (s[i] == 0)
				break ;
			while (s[i] == c && i <= ft_strlen(s))
				i++;
		}
		if (s[i] == 0)
			break ;
		i++;
	}
	return (num);
}

int	slen(char const *b, char d)
{
	int	i;

	i = 0;
	while (b[i] != d && b[i] != '\0')
		i++;
	return (i);
}

void	str_cpy(char const *src, char *dest, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**mem_c(char **t, int i)
{
	while (i >= 0)
	{
		free(t[i]);
		i--;
	}
	free(t);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		j;

	out = malloc(sizeof(char *) * (num_words(s, c) + 1));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (i < num_words(s, c))
	{
		while (s[j] == c)
			j += 1;
		out[i] = malloc(sizeof(char) * (slen(s + j, c) + 1));
		if (!out[i])
			return (mem_c(out, i));
		str_cpy(s + j, out[i], c);
		j += slen(s + j, c) + 1;
		i++;
	}
	out[i] = 0;
	return (out);
}
/*int main()       
{
	char **t;
	char c = '\0';
	char const *str = "\0jj\0jjjj";
	t = ft_split(str, c);
	for (int i = 0; i <= num_words(str, c); i++)
		printf("%s\n", t[i]);
	return 0;
}*/
