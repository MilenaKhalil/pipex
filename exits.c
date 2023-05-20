/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exits.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/20 21:09:09 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:11:54 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **paths)
{
	int	i;

	if (paths)
	{
		i = 0;
		while (paths[i])
		{
			free(paths[i]);
			i++;
		}
		free(paths);
	}
}

void	exit_man(char *prog_name, char *str, char **paths)
{
	free_paths(paths);
	if (!str)
		exit(1);
	write(2, prog_name, ft_strlen(prog_name));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
	exit(1);
}

void	file_error(char *prog_name, char *file_name, char **paths)
{
	char	*str;
	char	*temp;

	temp = make_str(file_name, ": ", strerror(errno), paths);
	str = make_str(prog_name, ": ", temp, paths);
	free(temp);
	temp = make_str("", str, "\n", paths);
	free(str);
	ft_putstr_fd(temp, 2);
	free(temp);
}

void	end_program(t_file *info, t_commands *com)
{
	int	status;

	waitpid(com->pid, &status, WUNTRACED);
	while (wait(NULL) != -1)
		continue ;
	close(info->fd_input);
	close(info->fd_output);
	free_paths(com->paths);
	exit (WEXITSTATUS(status));
}
