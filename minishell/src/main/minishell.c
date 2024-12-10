/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:56:48 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:03:47 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig_handler	g_global_sig;

void	ft_redir_and_exec(t_shell_state *shell_state, t_cmd_token *cmd_token)
{
	t_cmd_token	*prev;
	t_cmd_token	*next;
	int			pipe;

	prev = ft_prev_sep(cmd_token, NOSKIP);
	next = ft_next_sep(cmd_token, NOSKIP);
	pipe = 0;
	if (ft_is_type(prev, HERE_DOC) && shell_state->here_doc_triggered == 0)
	{
		shell_state->here_doc_triggered = 1;
		ft_here_doc(shell_state, cmd_token);
	}
	else if (ft_is_type(prev, TRUNC))
		ft_redir(shell_state, cmd_token, TRUNC);
	else if (ft_is_type(prev, APPEND))
		ft_redir(shell_state, cmd_token, APPEND);
	else if (ft_is_type(prev, INPUT))
		ft_input(shell_state, cmd_token);
	else if (ft_is_type(prev, PIPE))
		pipe = ft_mini_pipe(shell_state);
	if (next && ft_is_type(next, END) == 0 && pipe != 1)
		ft_redir_and_exec(shell_state, next->next);
	if ((ft_is_type(prev, END) || ft_is_type(prev, PIPE) || \
	!prev) && pipe != 1 && shell_state->should_skip_exec == 0)
		ft_exec_cmd(shell_state, cmd_token);
}

static void	ft_set_shell(t_shell_state *shell_state, t_cmd_token *cmd_token)
{
	shell_state->is_foreground = 1;
	shell_state->is_parent_proc = 1;
	shell_state->last_exit_stat = 1;
	ft_redir_and_exec(shell_state, cmd_token);
	ft_reset_std(shell_state);
	ft_close_fds(shell_state);
	ft_reset_fds(shell_state);
}

void	ft_mini_shell(t_shell_state *shell_state)
{
	t_cmd_token	*cmd_token;
	int			status;

	cmd_token = ft_next_run(shell_state->cmd_list, NOSKIP);
	if (ft_is_types(shell_state->cmd_list, "TAI"))
		cmd_token = shell_state->cmd_list->next;
	else
		cmd_token = cmd_token;
	while (shell_state->should_exit == 0 && cmd_token)
	{
		ft_set_shell(shell_state, cmd_token);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (shell_state->last_exit_stat == 0)
			shell_state->return_code = status;
		else
			shell_state->return_code = shell_state->return_code;
		if (shell_state->is_parent_proc == 0)
		{
			ft_free_token(shell_state->cmd_list);
			exit(shell_state->return_code);
		}
		shell_state->should_skip_exec = 0;
		cmd_token = ft_next_run(cmd_token, SKIP);
	}
}

static void	ft_init_shell(t_shell_state	*shell_state)
{
	shell_state->stdin_fd = dup(STDIN);
	shell_state->stdout_fd = dup(STDOUT);
	shell_state->active_env = NULL;
	shell_state->secret_env = NULL;
	shell_state->cmd_list = NULL;
	shell_state->tilde = NULL;
	shell_state->is_foreground = 0;
	shell_state->should_exit = 0;
	shell_state->return_code = 0;
	shell_state->should_skip_exec = 0;
	shell_state->history_count = 0;
	shell_state->here_doc_triggered = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell_state	shell_state;

	(void)argc;
	(void)argv;
	ft_init_shell(&shell_state);
	ft_reset_fds(&shell_state);
	ft_env_init(&shell_state, envp);
	ft_secret_env_init(&shell_state, envp);
	ft_increment_shell_level(shell_state.active_env);
	while (shell_state.should_exit == 0)
	{
		ft_sig_init();
		if (ft_parse_input(&shell_state) == 1)
			continue ;
		if (shell_state.cmd_list != NULL
			&& ft_check_line(&shell_state, shell_state.cmd_list))
			ft_mini_shell(&shell_state);
		ft_free_token(shell_state.cmd_list);
	}
	ft_free_history(shell_state);
	if (shell_state.active_env)
		ft_free_env(shell_state.active_env);
	ft_free_env(shell_state.secret_env);
	ft_memdel(shell_state.tilde);
	return (shell_state.return_code);
}
