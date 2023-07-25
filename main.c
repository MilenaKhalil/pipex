/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/06 21:11:02 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/05/20 21:09:39 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_commands	com;
	t_file		file_inf;

	if (argc != 5)
		exit_man(argv[0], ft_strdup("Invalid arguments"), NULL);
	com.argv = argv;
	com.argc = argc;
	all_paths(&com, envp);
	file_inf.fd_input = open(argv[1], O_RDONLY);
	if (file_inf.fd_input == -1)
		file_error(argv[0], argv[1], com.paths);
	file_inf.fd_output = open(argv[argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_inf.fd_output == -1)
		file_error(argv[0], argv[argc - 1], com.paths);
	make_children(&file_inf, &com, envp, 2);
	end_program(&file_inf, &com);
}
