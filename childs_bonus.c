/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 19:33:06 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:44:26 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(t_file *info, t_commands *com, char **envp, int n)
{
	char	**arg;

	if (dup2(info->fd_pipe[0][0], STDIN_FILENO) == -1)
		exit_man(com->argv[0], ft_strdup("Dup2 failure"), com->paths);
	if (dup2(info->fd_pipe[1][1], STDOUT_FILENO) == -1)
		exit_man(com->argv[0], ft_strdup("Dup2 failure"), com->paths);
	arg = ft_split(com->argv[n], ' ');
	if (!arg)
		exit_man(com->argv[0], ft_strdup("Malloc failure"), com->paths);
	if (n != 2)
		close(info->fd_pipe[0][1]);
	if (n != com->argc - 2)
		close(info->fd_pipe[1][0]);
	close(info->fd_pipe[0][0]);
	close(info->fd_pipe[1][1]);
	execve(get_path(com->paths, arg[0], com->argv[0]), arg, envp);
	free_paths(com->paths);
	exit(errno);
}

void	make_children(t_file *info, t_commands *com, char **envp, int k)
{
	int	n;

	n = k;
	while (n <= com->argc - 2)
	{
		if (n != com->argc - 2 && pipe(info->fd_pipe[1]) == -1)
			exit_man(com->argv[0], ft_strdup("Pipe failure"), com->paths);
		if (n == k)
			info->fd_pipe[0][0] = info->fd_input;
		if (n == com->argc - 2)
			info->fd_pipe[1][1] = info->fd_output;
		com->pid = fork();
		if (com->pid < 0)
			exit_man(com->argv[0], ft_strdup("Fork failure"), com->paths);
		if (com->pid == 0)
			child(info, com, envp, n);
		if (n != k)
		{
			close(info->fd_pipe[0][0]);
			close(info->fd_pipe[0][1]);
		}
		info->fd_pipe[0][0] = info->fd_pipe[1][0];
		info->fd_pipe[0][1] = info->fd_pipe[1][1];
		n++;
	}
}

void	get_here_doc(t_commands *com, t_file *info, char **envp, char *temp)
{
	char	*str;

	while (1)
	{
		str = get_next_line(1);
		if (!str)
			exit_man(com->argv[0], ft_strdup("Malloc failure"), com->paths);
		if (!ft_strncmp(temp, str, ft_strlen(temp)))
			break ;
		ft_putstr_fd(str, info->fd_pipe[0][1]);
		free(str);
	}
	free(temp);
	close(info->fd_pipe[0][1]);
	info->fd_input = info->fd_pipe[0][0];
	make_children(info, com, envp, 3);
	end_program(info, com);
}

void	here_doc(t_commands *com, t_file *info, char **envp, char **argv)
{
	char	*temp;

	info->fd_output = open(argv[com->argc - 1],
			O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (info->fd_output == -1)
		file_error(argv[0], argv[com->argc - 1], com->paths);
	if (pipe(info->fd_pipe[0]) == -1)
		exit_man(argv[0], ft_strdup("Pipe failure"), com->paths);
	temp = ft_strjoin(argv[2], "\n");
	if (!temp)
		exit_man(argv[0], ft_strdup("Malloc failure"), com->paths);
	get_here_doc(com, info, envp, temp);
}
