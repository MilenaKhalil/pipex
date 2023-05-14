/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/14 19:33:06 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/14 21:02:11 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h> //REMOVE

void	first_child(t_file *info, t_commands *com, char **envp)
{
	char	**arg;

	ft_putstr_fd("first\n", 2);
	dup2(info->fd_input, STDIN_FILENO);
	dup2(info->fd_new_pipe[2][1], STDOUT_FILENO);
	arg = ft_split(com->argv[2], ' ');
	close(info->fd_new_pipe[2][0]);
	close(info->fd_new_pipe[2][1]);
	close(info->fd_input);
	execve(get_path(com->paths, arg[0]), arg, envp);
	perror("arg[0]");
}

void	middle_child(t_file *info, t_commands *com, char **envp, int n)
{
	char	**arg;

	ft_putstr_fd("middle\n", 2);
	dup2(info->fd_new_pipe[n - 1][0], STDIN_FILENO);
	dup2(info->fd_new_pipe[n][1], STDOUT_FILENO);
	arg = ft_split(com->argv[n], ' ');
	close(info->fd_new_pipe[n][0]);
	close(info->fd_new_pipe[n - 1][0]);
	close(info->fd_new_pipe[n][1]);
	close(info->fd_new_pipe[n - 1][1]);
	execve(get_path(com->paths, arg[0]), arg, envp);
	perror(arg[0]);
}

void	last_child(t_file *info, t_commands *com, char **envp)
{
	char	**arg;

	ft_putstr_fd("last\n", 2);
	dup2(info->fd_new_pipe[com->argc - 3][0], STDIN_FILENO);
	dup2(info->fd_output, STDOUT_FILENO);
	arg = ft_split(com->argv[com->argc - 2], ' ');
	close(info->fd_output);
	close(info->fd_new_pipe[com->argc - 3][0]);
	if (execve(get_path(com->paths, arg[0]), arg, envp) == -1)
	{	
		perror("Command error");
		exit(1);
	}
}
