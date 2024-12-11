/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:09 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/19 19:41:45 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_find_path(char *cmd, char **envp)
{
	char	**poss_paths;
	char	*cmd_path;
	int		index;
	char	*temp_path;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	poss_paths = ft_split(envp[index] + 5, ':');
	index = 0;
	while (poss_paths[index])
	{
		temp_path = ft_strjoin(poss_paths[index], "/");
		cmd_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	index = -1;
	while (poss_paths[++index])
		free(poss_paths[index]);
	free(poss_paths);
	return (0);
}

void	ft_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		index;

	index = -1;
	cmd = ft_split(argv, ' ');
	cmd_path = ft_find_path(cmd[0], envp);
	if (!cmd_path)
	{
		while (cmd[++index])
			free(cmd[index]);
		free(cmd);
		ft_error();
	}
	if (execve(cmd_path, cmd, envp) == -1)
		ft_error();
}

// void	ft_execute(char *argv, char **envp)
// {
// 	char	*cmd_args[] = {"/bin/sh", "-c", argv, NULL};  
// Pass the command as a string
// 	char	*cmd_wt_path = "/bin/sh";  // Use /bin/sh to execute commands

// 	// Execute the command using /bin/sh -c to handle the full command string
// 	if (execve(cmd_wt_path, cmd_args, envp) == -1)
// 		ft_error();  // If execve fails, call error handler
// }