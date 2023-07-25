/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:09:39 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_str(char *str1, char *str2, char *str3, char **paths)
{
	char	*temp;
	char	*str;

	temp = ft_strjoin(str1, str2);
	if (!temp)
	{
		free_paths(paths);
		exit(1);
	}
	str = ft_strjoin(temp, str3);
	free(temp);
	if (!str)
	{
		free_paths(paths);
		exit(1);
	}
	return (str);
}

char	*get_path(char **paths, char *command, char *prog_name)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strchr(command, '/') && !access(command, X_OK))
		return (command);
	while (paths && paths[i])
	{
		str = make_str(paths[i], "/", command, paths);
		if (!access(str, X_OK))
			return (str);
		free(str);
		i++;
	}
	if (!paths || !paths[i])
	{
		str = make_str("command ", command, " does not exist", paths);
		exit_man(prog_name, str, paths);
	}
	return (NULL);
}

void	all_paths(t_commands *com, char **envp)
{
	int		i;
	int		rem;

	i = 0;
	rem = -1;
	com->paths = NULL;
	if (envp)
	{
		while (envp[i])
		{
			if (!ft_strncmp(envp[i], "PATH=", 5))
				rem = i;
			i++;
		}
		if (rem == -1)
			return ;
		com->paths = ft_split(&(envp[rem][5]), ':');
		if (!com->paths)
			exit(1);
	}
}
