/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:37:40 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/18 00:51:37 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_token	*ft_next_sep(t_cmd_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type < TRUNC)
		token = token->next;
	return (token);
}

t_cmd_token	*ft_prev_sep(t_cmd_token *token, int skip)
{
	if (token && skip)
		token = token->prev;
	while (token && token->type < TRUNC)
		token = token->prev;
	return (token);
}

t_cmd_token	*ft_next_run(t_cmd_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while (token && token->type != CMD)
	{
		token = token->next;
		if (token && token->type == CMD && token->prev == NULL)
			;
		else if (token && token->type == CMD && token->prev->type < END)
			token = token->next;
	}
	return (token);
}

void	ft_squish_helper(t_shell_state *shell_state, \
t_cmd_token *token, t_cmd_token *prev)
{
	while (ft_is_last_valid_arg(prev) == 0)
		prev = prev->prev;
	token->prev->next = token->next;
	if (token->next)
		token->next->prev = token->prev;
	token->prev = prev;
	if (prev)
		token->next = prev->next;
	else
		token->next = shell_state->cmd_list;
	if (prev)
		prev = prev;
	else
		prev = token;
	prev->next->prev = token;
	if (shell_state->cmd_list->prev)
		prev->next = prev->next;
	else
		prev->next = token;
	if (shell_state->cmd_list->prev)
		shell_state->cmd_list = shell_state->cmd_list->prev;
	else
		shell_state->cmd_list = shell_state->cmd_list;
}

t_cmd_token	*ft_finalize_token_list(t_cmd_token *last_token)
{
	if (last_token)
		last_token->next = NULL;
	while (last_token && last_token->prev)
		last_token = last_token->prev;
	return (last_token);
}
