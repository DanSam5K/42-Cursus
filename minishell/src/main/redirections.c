/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:28:09 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/17 18:23:12 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redir(t_shell_state *shell_state, t_cmd_token *token, int type)
{
	ft_close(shell_state->output_fd);
	if (type == TRUNC)
		shell_state->output_fd = open(token->content, O_CREAT
				| O_WRONLY | O_TRUNC, S_IRWXU);
	else
		shell_state->output_fd = open(token->content, O_CREAT
				| O_WRONLY | O_APPEND, S_IRWXU);
	if (shell_state->output_fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->content, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell_state->return_code = 1;
		shell_state->should_skip_exec = 1;
		return ;
	}
	dup2(shell_state->output_fd, STDOUT);
}

void	ft_input(t_shell_state *shell_state, t_cmd_token *token)
{
	if (ft_strcmp(token->content, "<") == 0)
	{
		if (token->next == NULL || token->next->type >= TRUNC)
		{
			ft_putstr_fd("syntax error near unexpected token `newline'\n", \
			STDERR);
			shell_state->return_code = 258;
			shell_state->should_skip_exec = 1;
			return ;
		}
		token = token->next;
	}
	ft_close(shell_state->input_fd);
	shell_state->input_fd = open(token->content, O_RDONLY, S_IRWXU);
	if (shell_state->input_fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->content, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell_state->return_code = 1;
		shell_state->should_skip_exec = 1;
		return ;
	}
	dup2(shell_state->input_fd, STDIN);
}

int	ft_mini_pipe(t_shell_state *shell_state)
{
	pid_t	pid;
	int		pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		ft_close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN);
		shell_state->pipe_input_fd = pipe_fd[0];
		shell_state->proc_id = -1;
		shell_state->is_parent_proc = 0;
		shell_state->should_skip_exec = 0;
		return (2);
	}
	else
	{
		ft_close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT);
		shell_state->pipe_output_fd = pipe_fd[1];
		shell_state->proc_id = pid;
		shell_state->last_exit_stat = 0;
		return (1);
	}
}
