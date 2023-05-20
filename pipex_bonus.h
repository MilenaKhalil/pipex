/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:10:57 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:29:40 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

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
	int		pid;
}	t_commands;

void	free_paths(char **paths);
void	exit_man(char *prog_name, char *str, char **paths);
void	child(t_file *info, t_commands *com, char **envp, int n);
void	make_children(t_file *info, t_commands *com, char **envp, int n);
void	file_error(char *prog_name, char *file_name, char **paths);
void	end_program(t_file *info, t_commands *com);
void	here_doc(t_commands *com, t_file *file_inf, char **envp, char **argv);
char	*get_path(char **paths, char *command, char *prog_name);
char	*make_str(char *str1, char *str2, char *str3, char **paths);

#endif
