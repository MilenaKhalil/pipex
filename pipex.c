/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/10 21:41:52 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_man(char *str, int par)
{
	write(2, str, ft_strlen(str));
	if (par)
		free(str);
	exit(EXIT_FAILURE);
}

void	check_commands(t_commands *com, char **paths)
{
	int		i;
	int		j;
	char	*temp;
	char	*str;

	com->com_paths = (char **) malloc(sizeof(char *) * (com->argc - 2));
	(com->com_paths)[com->argc - 3] = NULL;
	i = 2;
	while (i < com->argc - 1)
	{
		j = 0;
		while (paths[j])
		{
			temp = ft_strjoin(paths[j], "/");
			(com->com_paths)[i - 2] = ft_strjoin(temp, com->argv[i]);
			free(temp);
			if (!access((com->com_paths)[i - 2], X_OK))
				break ;
			free((com->com_paths)[i - 2]);
			j++;
		}
		if (!paths[j])
		{
			temp = ft_strjoin("Error: command ", com->argv[i]);
			str = ft_strjoin(temp, " does not exist");
			free(temp);
			exit_man(str, 1);
		}
		i++;
	}
}

void	get_paths(t_commands *com, char **envp)
{
	char	**paths;
	int		i;
	int		rem;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			rem = i;
		i++;
	}
	paths = ft_split(&(envp[rem][5]), ':');
	check_commands(com, paths);
}

int	main(int argc, char **argv, char **envp)
{
	t_commands	com;
	t_file		file_inf;
	int			p2;

	if (argc < 5)
		exit_man("Error: not enought arguments", 0);
	file_inf.fd_input = open(argv[1], O_RDONLY);
	if (file_inf.fd_input == -1)
		exit_man("Error: input file does not exist", 0);
	file_inf.fd_output = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	if (file_inf.fd_output == -1)
		exit_man("Error: output file does not exist", 0);
	if (pipe(file_inf.fd_pipe) == -1)
		exit_man("Error: pipe failed", 0);
	com.argv = argv;
	com.argc = argc;
	get_paths(&com, envp);
	int p1 = fork();
	printf("prosses id1 = %d\n", p1);
	if (p1 == 0)
		first_child(&file_inf, &com, envp);
	p2 = fork();
	if (p2 == 0)
		second_child(&file_inf, &com, envp);
	printf("prosses id2 = %d\n", p2);
	exit(EXIT_SUCCESS);
}