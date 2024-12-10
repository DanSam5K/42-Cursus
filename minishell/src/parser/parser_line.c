/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:15:14 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:05:19 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_space_alloc(char *line)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (ft_is_sep(line, i))
			count++;
		i++;
	}
	new = malloc(sizeof(char) * (i + 2 * count + 1));
	if (!new)
		return (NULL);
	return (new);
}

char	*ft_space_line(char *ln)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_space_alloc(ln);
	while (new && ln[i])
	{
		if (ft_quotes(ln, i) != 2 && ln[i] == '$' && i && ln[i - 1] != '\\')
			new[j++] = (char)(-ln[i++]);
		else if (ft_quotes(ln, i) == 0 && ft_is_sep(ln, i))
		{
			new[j++] = ' ';
			new[j++] = ln[i++];
			if (ln[i - 1] == '>' && ln[i] == '>')
				new[j++] = ln[i++];
			else if (ln[i - 1] == '<' && ln[i] == '<')
				new[j++] = ln[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = ln[i++];
	}
	return (new[j] = '\0', ft_memdel(ln), new);
}

int	ft_quote_check(t_shell_state *shell_state, char **line)
{
	if (ft_quotes(*line, 2147483647))
	{
		ft_putendl_fd("syntax error with open quotes", STDERR);
		ft_memdel(*line);
		shell_state->return_code = 2;
		return (1);
	}
	return (0);
}

static int	ft_parse_helper(t_shell_state *shell_state, char *line)
{
	t_cmd_token	*token;

	if (g_global_sig.sigint_received == 1)
		shell_state->return_code = g_global_sig.last_exit_stat;
	else
		shell_state->return_code = shell_state->return_code;
	if (ft_quote_check(shell_state, &line) == 1)
		return (1);
	line = ft_space_line(line);
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);
	shell_state->cmd_list = ft_get_tokens(line);
	ft_memdel(line);
	ft_squish_args(shell_state);
	token = shell_state->cmd_list;
	while (token)
	{
		if (ft_is_type(token, ARG))
			ft_type_arg(token, 0);
		token = token->next;
	}
	return (0);
}

int	ft_parse_input(t_shell_state *shell_state)
{
	char		*line;

	signal(SIGINT, &ft_sig_integer);
	signal(SIGQUIT, &ft_sig_exit);
	signal(SIGQUIT, SIG_IGN);
	if (shell_state->return_code)
		ft_putstr_fd("🤬 ", STDERR);
	else
		ft_putstr_fd("😎 ", STDERR);
	line = readline("\033[0;36m\033[1mminishell ▸ \033[0m");
	if (!line)
	{
		shell_state->should_exit = 1;
		return (ft_putendl_fd("exit", STDERR), 1);
	}
	if (*line)
	{
		add_history(line);
		ft_my_add_history(line, shell_state);
	}
	if (ft_parse_helper(shell_state, line) == 1)
		return (1);
	shell_state->here_doc_triggered = 0;
	return (0);
}
