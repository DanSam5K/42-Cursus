/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:48 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/06 17:06:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void	err(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"), 1);
	if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "),
			err(argv[1]), err("\n"), 1);
	return (0);
}

void	set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1
			|| close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		err("error: cannot duplicate file descriptor\n");
		exit(1);
	}
}

int	exec(char **argv, int i, char **envp)
{
	int	has_pipe;
	int	fd[2];
	int	pid;
	int	status;

	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (has_pipe && !strcmp(*argv, "cd"))
		return (cd(argv, i));
	if (has_pipe && pipe(fd) == -1)
	{
		err("error: cannot create pipe\n");
		exit(1);
	}
	if (!pid)
	{
		argv[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*argv, "cd"))
			exit(cd(argv, i));
		execve(*argv, argv, envp);
		err("error: cannot execute ");
		err(*argv);
		err("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

