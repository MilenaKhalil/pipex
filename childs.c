/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 19:33:06 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/15 18:09:36 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

void	child(t_file *info, t_commands *com, char **envp, int n)
{
	char	**arg;

	if (dup2(info->fd_pipe[0][0], STDIN_FILENO) == -1)
		exit(errno);
	if (dup2(info->fd_pipe[1][1], STDOUT_FILENO) == -1)
		exit(errno);
	arg = ft_split(com->argv[n], ' ');
	if (!arg)
		exit(1);
	if (n != 2)
		close(info->fd_pipe[0][1]);
	if (n != com->argc - 2)
		close(info->fd_pipe[1][0]);
	close(info->fd_pipe[0][0]);
	close(info->fd_pipe[1][1]);
	execve(get_path(com->paths, arg[0], com->argv[0]), arg, envp);
	exit(errno);
}

int	make_children(t_file *info, t_commands *com, char **envp)
{
	int	n;
	int	p2;

	n = 2;
	while (n <= com->argc - 2)
	{
		if (n != com->argc - 2 && pipe(info->fd_pipe[1]) == -1)
			exit_man(com->argv[0], ft_strdup("Pipe failure"));
		if (n == 2)
			info->fd_pipe[0][0] = info->fd_input;
		if (n == com->argc - 2)
			info->fd_pipe[1][1] = info->fd_output;
		p2 = fork();
		if (p2 == 0)
			child(info, com, envp, n);
		if (n != 2)
		{
			close(info->fd_pipe[0][0]);
			close(info->fd_pipe[0][1]);
		}
		info->fd_pipe[0][0] = info->fd_pipe[1][0];
		info->fd_pipe[0][1] = info->fd_pipe[1][1];
		n++;
	}
	return (p2);
}
