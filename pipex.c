/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/15 18:11:57 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

void	exit_man(char *prog_name, char *str)
{
	if (!str)
		exit(1);
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
	exit(1);
}

char	*make_str(char *str1, char *str2, char *str3)
{
	char	*temp;
	char	*str;

	temp = ft_strjoin(str1, str2);
	if (!temp)
		exit(1);
	str = ft_strjoin(temp, str3);
	if (!str)
		exit(1);
	free(temp);
	return (str);
}

char	*get_path(char **paths, char *command, char *prog_name)
{
	int		i;
	char	*str;

	i = 0;
	while (paths[i])
	{
		str = make_str(paths[i], "/", command);
		if (!access(str, X_OK))
			return (str);
		free(str);
		i++;
	}
	if (!paths[i])
	{
		str = make_str("command ", command, " does not exist");
		exit_man(prog_name, str);
	}
	return (NULL);
}

void	all_paths(t_commands *com, char **envp)
{
	int		i;
	int		rem;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			rem = i;
		i++;
	}
	com->paths = ft_split(&(envp[rem][5]), ':');
	if (!com->paths)
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_commands	com;
	t_file		file_inf;
	int			p2;
	int			status;

	if (argc < 5)
		exit_man(argv[0], ft_strdup("Invalid arguments"));
	file_inf.fd_input = open(argv[1], O_RDONLY);
	if (file_inf.fd_input == -1)
		exit_man(argv[0], ft_strdup("Failed open input file"));
	file_inf.fd_output = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (file_inf.fd_output == -1)
		exit_man(argv[0], ft_strdup("Failed open output file"));
	com.argv = argv;
	com.argc = argc;
	all_paths(&com, envp);
	p2 = make_children(&file_inf, &com, envp);
	waitpid(p2, &status, WUNTRACED);
	while (wait(NULL) != -1)
	{
	}
	close(file_inf.fd_input);
	close(file_inf.fd_output);
	return (WEXITSTATUS(status));
}
