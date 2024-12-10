/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:10:24 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:47:23 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hd_sig_handler(int sig_nal)
{
	(void)sig_nal;
	write(2, "\n", 1);
	exit(130);
}

char	*ft_strrstr(const char *haystack, const char *needle)
{
	const char	*last_occurrence = NULL;
	const char	*current_pos;
	size_t		needle_len;

	if (!*needle)
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	current_pos = haystack;
	while (*current_pos)
	{
		if (*current_pos == *needle
			&& !ft_strncmp(current_pos, needle, needle_len))
			last_occurrence = current_pos;
		current_pos++;
	}
	return ((char *)last_occurrence);
}

char	*ft_getenv(const char *var_name, t_env_variable *env)
{
	t_env_variable	*current_env;
	size_t			var_len;

	current_env = env;
	var_len = ft_strlen(var_name);
	while (current_env)
	{
		if (ft_strncmp(current_env->variable, var_name, var_len) == 0
			&& current_env->variable[var_len] == '=')
			return (current_env->variable + var_len + 1);
		current_env = current_env->next;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	free(s1);
	return (new_str);
}

int	ft_is_quoted_delimiter(char *delimiter, t_shell_state *shell_state)
{
	char	*raw_input;
	char	*last_occurrence;
	int		in_quotes;
	int		last_index;

	last_index = shell_state->history_count - 1;
	if (last_index < 0)
		return (0);
	raw_input = shell_state->history[last_index];
	if (!raw_input)
		return (0);
	last_occurrence = ft_strrstr(raw_input, "<<");
	if (!last_occurrence)
		return (0);
	in_quotes = 0;
	while (*last_occurrence)
	{
		if (*last_occurrence == '"' || *last_occurrence == '\'')
			in_quotes = !in_quotes;
		if (ft_strncmp(last_occurrence, delimiter, ft_strlen(delimiter)) == 0)
			return (in_quotes);
		last_occurrence++;
	}
	return (0);
}
