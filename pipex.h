/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:10:57 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/15 18:08:27 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_file
{
	int	fd_input;
	int	fd_output;
	int	fd_pipe[2][2];
}	t_file;

typedef struct s_commands
{
	char	**argv;
	char	**paths;
	int		argc;
}	t_commands;

void	exit_man(char *prog_name, char *str);
void	child(t_file *info, t_commands *com, char **envp, int n);
char	*get_path(char **paths, char *command, char *prog_name);
int		make_children(t_file *info, t_commands *com, char **envp);

#endif