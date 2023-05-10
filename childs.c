/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 20:56:50 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/10 21:42:21 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_file *info, t_commands *com, char **envp)
{
	char	**argv;

	dup2(info->fd_input, STDIN_FILENO);
	dup2(info->fd_pipe[1], STDOUT_FILENO);
	argv = ft_split(com->argv[2], ' ');
	//printf("%s\n", com->com_paths[0]);
	execve(com->com_paths[0], argv, envp);
	exit(0);
}

void	second_child(t_file *info, t_commands *com, char **envp)
{
	char	**argv;

	dup2(info->fd_output, STDOUT_FILENO);
	dup2(info->fd_pipe[0], STDIN_FILENO);
	argv = ft_split(com->argv[3], ' ');
	//get_paths(&com, envp);
	//printf("%s\n", com->com_paths[0]);
	execve(com->com_paths[0], argv, envp);
	exit(0);
}