/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/14 17:58:35 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_man(char *str, int par)
{
	(void) str;

	perror("Error");
	//write(2, str, ft_strlen(str));
	if (par)
		free(str);
	exit(1);
}

char	*get_path(char **paths, char *command)
{
	int		i;
	char	*temp;
	char	*str;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		str = ft_strjoin(temp, command);
		free(temp);
		if (!access(str, X_OK))
			return (str);
		free(str);
		i++;
	}
	if (!paths[i])
	{
		temp = ft_strjoin("Error: command ", command);
		str = ft_strjoin(temp, " does not exist\n");
		free(temp);
		exit_man(str, 1);
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
}

int	main(int argc, char **argv, char **envp)
{
	t_commands	com;
	t_file		file_inf;
	int			p2;

	if (argc < 5)
		exit_man("Error: not enought arguments\n", 0);
	file_inf.fd_input = open(argv[1], O_RDONLY);
	if (file_inf.fd_input == -1)
		exit_man("Error: input file does not exist\n", 0);
	file_inf.fd_output = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (file_inf.fd_output == -1)
		exit_man("Error: output file does not exist\n", 0);
	com.argv = argv;
	com.argc = argc;
	all_paths(&com, envp);
	int n = 2;
	while (n <= argc - 2)
	{
		if (pipe(file_inf.fd_new_pipe[n]) == -1)
			exit_man("Error: pipe failed\n", 0);
		p2 = fork();
		if (p2 == 0)
		{
			if (n == 2)
				first_child(&file_inf, &com, envp);
			else if (n < argc - 2)
				middle_child(&file_inf, &com, envp, n);
			else
				last_child(&file_inf, &com, envp);
		}
		//waitpid(p2);
		//close(file_inf.fd_new_pipe[n][0]);
		//close(file_inf.fd_new_pipe[n][1]);
		n++;
	}
	close(file_inf.fd_output);
	close(file_inf.fd_input);
	exit(0);
}
