/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:23:49 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/26 14:46:57 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_type_arg(t_cmd_token *token, int separator)
{
	if (ft_strcmp(token->content, "") == 0)
		token->type = EMPTY;
	else if (ft_strcmp(token->content, "<<") == 0 && separator == 0)
		token->type = HERE_DOC;
	else if (ft_strcmp(token->content, ">") == 0 && separator == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->content, ">>") == 0 && separator == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->content, "<") == 0 && separator == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->content, "|") == 0 && separator == 0)
		token->type = PIPE;
	else if (ft_strcmp(token->content, ";") == 0 && separator == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

void	ft_squish_args(t_shell_state *shell_state)
{
	t_cmd_token	*token;
	t_cmd_token	*prev;

	token = shell_state->cmd_list;
	while (token)
	{
		prev = ft_prev_sep(token, NOSKIP);
		if (ft_is_type(token, ARG) && ft_is_types(prev, "TAIH"))
			ft_squish_helper(shell_state, token, prev);
		token = token->next;
	}
}

int	ft_next_alloc(char *line, int *i)
{
	int		count;
	int		j;
	char	c;

	count = 0;
	j = 0;
	c = ' ';
	while (line[*i + j] && (line[*i + j] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i + j] == '\'' || line[*i + j] == '\"'))
			c = line[*i + j++];
		else if (c != ' ' && line[*i + j] == c)
		{
			count += 2;
			c = ' ';
			j++;
		}
		else
			j++;
		if (line[*i + j - 1] == '\\')
			count--;
	}
	return (j - count + 1);
}

t_cmd_token	*ft_next_token(char *line, int *i)
{
	t_cmd_token	*token;
	int			j;
	char		c;

	j = 0;
	c = ' ';
	token = malloc(sizeof(t_cmd_token));
	token->content = malloc(sizeof(char) * ft_next_alloc(line, i));
	if (!token || !token->content)
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\' && (*i)++)
			token->content[j++] = line[(*i)++];
		else
			token->content[j++] = line[(*i)++];
	}
	return ((token->content[j] = '\0'), token);
}

t_cmd_token	*ft_get_tokens(char *line)
{
	t_cmd_token	*prev;
	t_cmd_token	*next;
	int			i;
	int			sep;

	prev = NULL;
	next = NULL;
	i = 0;
	ft_skip_spacenl(line, &i);
	while (line[i])
	{
		sep = ft_ignore_sep(line, i);
		next = ft_next_token(line, &i);
		if (!next)
			return (NULL);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		ft_type_arg(next, sep);
		ft_skip_spacenl(line, &i);
	}
	return (ft_finalize_token_list(next));
}
