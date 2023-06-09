/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 19:33:06 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:10:07 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
