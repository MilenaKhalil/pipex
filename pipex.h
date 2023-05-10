/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:10:57 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/10 21:32:30 by mikhalil      ########   odam.nl         */
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
	int	fd_pipe[2];
}	t_file;

typedef struct s_commands
{
	char	**argv;
	char	**com_paths;
	int		argc;
}	t_commands;

void	first_child(t_file *info, t_commands *com, char **envp);
void	second_child(t_file *info, t_commands *com, char **envp);

#endif