/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/06 21:34:50 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool 

int main (int argc, char **argv, char **envp)
{
	char **paths;
	int i = 0;
	int rem;

	(void)argc;
	(void)argv;

	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			rem = i;
			//printf("%s\n", envp[i]);
		i++;
		//(void)*envp++;
	}
	paths = ft_split(&(envp[rem][5]), ':');
	while (*paths)
		printf("%s\n", *paths++);
}