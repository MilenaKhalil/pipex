/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 15:54:09 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/01/29 17:30:35 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	prop_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

char	*free_all(char **out, char **buf, char **save_buf)
{
	if (out)
		prop_free(out);
	if (buf)
		prop_free(buf);
	if (save_buf)
		prop_free(save_buf);
	return (NULL);
}

int	remake(char **out, char *buf, int k, int param)
{
	char	*temp;
	int		i;

	i = 1;
	if (!param || !(*out))
	{
		temp = str_join(NULL, buf, str_len(buf, '\0'));
		if (!temp && buf)
			return (0);
		prop_free(out);
		if (k)
			*out = str_join(NULL, temp, k);
		if (!(*out) && k)
			i = 0;
	}
	else
	{
		temp = str_join(NULL, *out, str_len(*out, '\0'));
		prop_free(out);
		*out = str_join(temp, buf, k);
		if (!(*out) || !temp)
			i = 0;
	}
	prop_free(&temp);
	return (i);
}

char	*gnl(int fd, char **buf, char **out, char **save)
{
	int	check;
	int	k;

	while (1)
	{
		fill(*buf, BUFFER_SIZE + 1);
		check = read(fd, *buf, BUFFER_SIZE);
		if (check == -1)
			return (free_all(out, buf, save));
		if (!check)
			break ;
		k = str_len(*buf, '\n');
		if (k == str_len(*buf, '\0') && !remake(out, *buf, k, 1))
			return (free_all(out, buf, save));
		else if (k < str_len(*buf, '\0'))
		{
			if (!remake(out, *buf, k + 1, 1)
				|| !remake(save, *buf + k + 1, check - k - 1, 0))
				free_all(out, buf, save);
			break ;
		}
	}
	prop_free(buf);
	return (*out);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save = NULL;
	char		*out;

	out = NULL;
	if (save && str_len(save, '\n') != str_len(save, '\0'))
	{
		out = str_join(NULL, save, str_len(save, '\n') + 1);
		if (!remake(&save, save + str_len(save, '\n') + 1,
				str_len(save, '\0') - str_len(save, '\n') - 1, 0) || !out)
			return (free_all(&out, NULL, &save));
		return (out);
	}
	else if (save)
	{
		out = str_join(NULL, save, str_len(save, '\0'));
		prop_free(&save);
		if (!out)
			return (free_all(&out, NULL, &save));
	}
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_all(&out, &buf, &save));
	return (gnl(fd, &buf, &out, &save));
}
