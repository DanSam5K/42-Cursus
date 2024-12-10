/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:22 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:06:18 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quotes(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (line[i] && i != index && (index == 2147483647 || i < index))
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (open == 0 && line[i] == '\"')
			open = 1;
		else if (open == 0 && line[i] == '\'')
			open = 2;
		else if (open == 1 && line[i] == '\"')
			open = 0;
		else if (open == 2 && line[i] == '\'')
			open = 0;
		i++;
	}
	return (open);
}

int	ft_is_last_valid_arg(t_cmd_token *token)
{
	t_cmd_token	*prev;

	if (!token || ft_is_type(token, CMD) || ft_is_type(token, ARG))
	{
		prev = ft_prev_sep(token, NOSKIP);
		if (!prev || ft_is_type(prev, END) || ft_is_type(prev, PIPE))
			return (1);
		return (0);
	}
	else
		return (0);
}

int	ft_is_sep(char *line, int i)
{
	if (i > 0 && line[i - 1] == '\\' && ft_strchr("<>|;", line[i]))
		return (0);
	else if (ft_strchr("<>|;", line[i]) && ft_quotes(line, i) == 0)
		return (1);
	return (0);
}

static int	ft_check_syntax_error(t_shell_state *shell_state,
		t_cmd_token *token, char *types, char *unexpected_types)
{
	if (ft_is_types(token, types) && (!token->prev
			|| !token->next || ft_is_types(token->prev, unexpected_types)))
	{
		ft_putstr_fd("mini: syntax error near unexpected token `", STDERR);
		ft_putstr_fd(token->content, STDERR);
		ft_putendl_fd("'", STDERR);
		shell_state->return_code = 258;
		return (0);
	}
	return (1);
}

int	ft_check_line(t_shell_state *shell_state, t_cmd_token *token)
{
	while (token)
	{
		if (ft_is_types(token, "TAIH")
			&& (!token->next || ft_is_types(token->next, "TAIPE")))
		{
			ft_putstr_fd("mini: syntax error near unexpected token `", STDERR);
			if (token->next)
				ft_putstr_fd(token->next->content, STDERR);
			else
				ft_putstr_fd("newline", STDERR);
			ft_putendl_fd("'", STDERR);
			shell_state->return_code = 2;
			return (0);
		}
		if (!ft_check_syntax_error(shell_state, token, "PE", "TAIPE"))
			return (0);
		token = token->next;
	}
	return (1);
}
