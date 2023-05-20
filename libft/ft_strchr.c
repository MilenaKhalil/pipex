/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 12:38:00 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 19:55:37 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	a;

	a = (char)c;
	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return (str + i);
		i++;
	}
	if (a == '\0')
		return (str + i);
	return (0);
}
