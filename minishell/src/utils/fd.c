/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:36:33 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 16:46:59 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_reset_std(t_shell_state *shell_state)
{
	dup2(shell_state->stdin_fd, STDIN);
	dup2(shell_state->stdout_fd, STDOUT);
}

void	ft_close_fds(t_shell_state *shell_state)
{
	ft_close(shell_state->input_fd);
	ft_close(shell_state->output_fd);
	ft_close(shell_state->pipe_input_fd);
	ft_close(shell_state->pipe_output_fd);
}

void	ft_reset_fds(t_shell_state *shell_state)
{
	shell_state->input_fd = -1;
	shell_state->output_fd = -1;
	shell_state->pipe_input_fd = -1;
	shell_state->pipe_output_fd = -1;
	shell_state->proc_id = -1;
}

char	*ft_expand_character(char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (ft_strdup(tmp));
}
