/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:37:00 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/07 14:00:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mini_exit(t_shell_state *shell_state, char **cmd_args)
{
	shell_state->should_exit = 1;
	ft_putstr_fd("exit\n", STDERR);
	if (cmd_args[1])
		ft_putendl_fd("❤️", STDERR);
	else
		ft_putendl_fd("💚", STDERR);
	if (cmd_args[1] && cmd_args[2])
	{
		shell_state->return_code = 1;
		ft_putendl_fd("exit: too many arguments", STDERR);
	}
	else if (cmd_args[1] && ft_strisnum(cmd_args[1]) == 0)
	{
		shell_state->return_code = 255;
		ft_putstr_fd("exit: ", STDERR);
		ft_putstr_fd(cmd_args[1], STDERR);
		ft_putendl_fd(": numeric argument required", STDERR);
	}
	else if (cmd_args[1])
		shell_state->return_code = ft_atoi(cmd_args[1]);
	else
		shell_state->return_code = 0;
}
