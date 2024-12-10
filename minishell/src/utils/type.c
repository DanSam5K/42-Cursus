/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:44:42 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/26 16:17:18 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_type(t_cmd_token *token, int type)
{
	if (!token)
		return (0);
	if (token->type == type)
		return (1);
	else
		return (0);
}

int	ft_is_types(t_cmd_token *token, char *types)
{
	if (!token || !types)
		return (0);
	if (ft_strchr(types, ' ') && ft_is_type(token, EMPTY))
		return (1);
	else if (ft_strchr(types, 'X') && ft_is_type(token, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && ft_is_type(token, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && ft_is_type(token, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && ft_is_type(token, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && ft_is_type(token, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && ft_is_type(token, PIPE))
		return (1);
	else if (ft_strchr(types, 'E') && ft_is_type(token, END))
		return (1);
	else if (ft_strchr(types, 'H') && ft_is_type(token, HERE_DOC))
		return (1);
	return (0);
}

int	ft_has_pipe(t_cmd_token *token)
{
	while (token && ft_is_type(token, END) == 0)
	{
		if (ft_is_type(token, PIPE))
			return (1);
		token = token->next;
	}
	return (0);
}

int	ft_ignore_sep(char *line, int i)
{
	if (line[i] == '\\' && line[i + 1])
	{
		if (line[i + 1] == ';' || line[i + 1] == '|'
			|| line[i + 1] == '>' || line[i + 1] == '<')
		{
			if (line[i + 1] == '>' && line[i + 2] && line[i + 2] == '>')
				return (1);
			if (line[i + 1] == '<' && line[i + 2] && line[i + 2] == '<')
				return (1);
			return (1);
		}
	}
	return (0);
}
