/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:53 by ojacobs           #+#    #+#             */
/*   Updated: 2024/12/10 11:07:27 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (1);
	if (ft_strcmp(command, "cd") == 0)
		return (1);
	if (ft_strcmp(command, "pwd") == 0)
		return (1);
	if (ft_strcmp(command, "env") == 0)
		return (1);
	if (ft_strcmp(command, "export") == 0)
		return (1);
	if (ft_strcmp(command, "unset") == 0)
		return (1);
	if (ft_strcmp(command, "clear") == 0)
		return (1);
	return (0);
}

int	ft_exec_builtin(char **args, t_shell_state *shell_state)
{
	int		result;

	result = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		result = ft_echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		result = ft_cd(args, shell_state);
	if (ft_strcmp(args[0], "pwd") == 0)
		result = ft_pwd();
	if (ft_strcmp(args[0], "env") == 0)
		ft_env(shell_state->active_env);
	if (ft_strcmp(args[0], "export") == 0)
		ft_export(args, shell_state->active_env, shell_state->secret_env);
	if (ft_strcmp(args[0], "unset") == 0)
		ft_unset(args, shell_state);
	if (ft_strcmp(args[0], "clear") == 0)
		ft_clear();
	return (result);
}
