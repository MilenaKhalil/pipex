/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 20:56:50 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/14 18:27:00 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h> //REMOVE

void	first_child(t_file *info, t_commands *com, char **envp)
{
	char	**argv;

	dup2(info->fd_input, STDIN_FILENO);
	dup2(info->fd_new_pipe[2][1], STDOUT_FILENO);
	argv = ft_split(com->argv[2], ' ');
	// close(info->fd_new_pipe[2][0]);
	// close(info->fd_new_pipe[2][1]);
	execve(get_path(com->paths, argv[0]), argv, envp);
	exit(0);
}

void	middle_child(t_file *info, t_commands *com, char **envp, int n)
{
	char	**argv;

//(void)n;
	
	//close(info->fd_new_pipe[n][0]);
	dup2(info->fd_new_pipe[n - 1][0], STDIN_FILENO);
	dup2(info->fd_input, STDOUT_FILENO);
	dprintf(2, "pipe write: %i\n", n);
	//dup2(info->fd_new_pipe[n][1], STDOUT_FILENO);
	close(info->fd_new_pipe[n - 1][1]);
	argv = ft_split(com->argv[n], ' ');
	close(info->fd_new_pipe[n][1]);
	close(info->fd_new_pipe[n - 1][0]);
	execve(get_path(com->paths, argv[0]), argv, envp);
	exit(0);
}

void	last_child(t_file *info, t_commands *com, char **envp)
{
	char	**argv;

	//ft_putstr_fd("last\n", 2);
	dprintf(2, "pipe read: %i\n", com->argc - 3);
	dup2(info->fd_output, STDOUT_FILENO);
	close(info->fd_new_pipe[com->argc - 3][1]);
	dup2(info->fd_input, STDIN_FILENO);
	//dup2(info->fd_new_pipe[com->argc - 3][0], STDIN_FILENO);
	argv = ft_split(com->argv[com->argc - 2], ' ');
	// close(info->fd_new_pipe[com->argc - 2][0]);
	// close(info->fd_new_pipe[com->argc - 2][1]);
	close(info->fd_new_pipe[com->argc - 3][0]);
	execve(get_path(com->paths, argv[0]), argv, envp);
	exit(0);
}
