/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:38:28 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/19 22:01:48 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	process_id;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		ft_error();
	process_id = fork();
	if (process_id == -1)
		ft_error();
	if (process_id == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		ft_execute(argv, envp);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(process_id, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	reader_proc;
	int		pipe_fd[2];
	char	*cur_line;

	if (argc < 6)
		ft_usage();
	if (pipe(pipe_fd) == -1)
		ft_error();
	reader_proc = fork();
	if (reader_proc == 0)
	{
		close(pipe_fd[0]);
		while (ft_get_next_line(&cur_line))
		{
			if (ft_strncmp(cur_line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipe_fd[1], cur_line, ft_strlen(cur_line));
		}
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	arg_index;
	int	file_in;
	int	file_out;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			arg_index = 3;
			file_out = ft_open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			arg_index = 2;
			file_out = ft_open_file(argv[argc - 1], 1);
			file_in = ft_open_file(argv[1], 2);
			dup2(file_in, STDIN_FILENO);
		}
		while (arg_index < argc - 2)
			child_process(argv[arg_index++], envp);
		dup2(file_out, STDOUT_FILENO);
		ft_execute(argv[argc - 2], envp);
	}
	ft_usage();
}
