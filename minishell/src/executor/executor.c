/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:17:41 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/17 18:19:36 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cmd_tab(t_cmd_token *start)
{
	t_cmd_token	*token;
	char		**tab;
	int			i;

	if (!start)
		return (NULL);
	token = start->next;
	i = 2;
	while (token && token->type < TRUNC)
	{
		token = token->next;
		i++;
	}
	tab = malloc(sizeof(char *) * i);
	if (!tab)
		return (NULL);
	token = start->next;
	tab[0] = start->content;
	i = 1;
	while (token && token->type < TRUNC)
	{
		tab[i++] = token->content;
		token = token->next;
	}
	return (tab[i] = NULL, tab);
}

static void	ft_exec_cmd_close(t_shell_state *shell_state, char **cmd)
{
	ft_free_tab(cmd);
	ft_close(shell_state->pipe_input_fd);
	ft_close(shell_state->pipe_output_fd);
	shell_state->pipe_input_fd = -1;
	shell_state->pipe_output_fd = -1;
	shell_state->is_foreground = 0;
}

void	ft_exec_cmd(t_shell_state *shell_state, t_cmd_token *token)
{
	char	**cmd;
	int		i;

	if (shell_state->is_foreground == 0)
		return ;
	cmd = ft_cmd_tab(token);
	i = 0;
	while (cmd && cmd[i])
	{
		cmd[i] = ft_expansions(cmd[i], shell_state->active_env, \
		shell_state->return_code);
		i++;
	}
	if (cmd && ft_strcmp(cmd[0], "exit") == 0 && ft_has_pipe(token) == 0)
		ft_mini_exit(shell_state, cmd);
	else if (cmd && ft_is_builtin(cmd[0]))
		shell_state->return_code = ft_exec_builtin(cmd, shell_state);
	else if (cmd && ft_strcmp(cmd[0], "history") == 0)
		shell_state->return_code = ft_print_history(shell_state);
	else if (cmd)
		shell_state->return_code = ft_exec_bin(cmd, \
		shell_state->active_env, shell_state);
	ft_exec_cmd_close(shell_state, cmd);
}
