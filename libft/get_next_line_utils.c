/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 21:29:23 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/01/28 19:24:06 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

int	str_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != c && str[i])
		i++;
	return (i);
}

void	str_n_cpy(char *dest, char *sour, int k)
{
	int	i;

	i = 0;
	if (!dest || !sour)
		return ;
	while (sour[i] != 0 && i < k)
	{
		dest[i] = sour[i];
		i++;
	}
	dest[i] = 0;
}

char	*str_join(char *out, char *buf, int k)
{
	char	*output;
	int		i;

	if (!out && buf)
	{
		output = malloc(k + 1);
		if (!output)
			return (NULL);
		str_n_cpy(output, buf, k);
		return (output);
	}
	output = malloc(str_len(out, '\0') + k + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (out[i] != 0)
	{
		output[i] = out[i];
		i++;
	}
	str_n_cpy(&output[i], buf, k);
	return (output);
}
