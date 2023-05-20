/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:44:50 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

int	main(int argc, char **argv, char **envp)
{
	t_commands	com;
	t_file		file_inf;

	if (argc < 5 || (argc < 6 && !ft_strncmp(argv[1], "here_doc", 8)))
		exit_man(argv[0], ft_strdup("Invalid arguments"), NULL);
	com.argv = argv;
	com.argc = argc;
	all_paths(&com, envp);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(&com, &file_inf, envp, argv);
	if (file_inf.fd_input == -1)
		file_error(argv[0], argv[1], com.paths);
	file_inf.fd_output = open(argv[argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_inf.fd_output == -1)
		file_error(argv[0], argv[argc - 1], com.paths);
	file_inf.fd_input = open(argv[1], O_RDONLY);
	make_children(&file_inf, &com, envp, 2);
	end_program(&file_inf, &com);
}
