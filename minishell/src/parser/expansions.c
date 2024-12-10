/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:44:20 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 23:17:44 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_var_val_cpy(char *new_arg, const char *env_value, int pos)
{
	int	i;

	i = 0;
	while (env_value[i])
		new_arg[pos++] = env_value[i++];
	return (i);
}

static void	ft_insert_var(t_expand_data *data, char *arg, \
t_env_variable *env, int ret)
{
	char	*env_value;

	env_value = ft_get_var_value(arg, data->dest_index, env, ret);
	if (env_value)
		data->src_index += ft_var_val_cpy(data->expanded_str, \
		env_value, data->src_index);
	else
		data->src_index += 0;
	ft_memdel(env_value);
	if (arg[data->dest_index] == '?')
		data->dest_index++;
	if (ft_isdigit(arg[data->dest_index]) == 0 && \
	arg[data->dest_index - 1] != '?')
	{
		while (ft_is_env_char(arg[data->dest_index]) == 1)
			data->dest_index++;
	}
	else
	{
		if (arg[data->dest_index - 1] != '?')
			data->dest_index++;
	}
}

char	*ft_expand_variable(const char *input_line,
	int *index, t_shell_state *shell_state)
{
	int		start;
	char	*var_name;
	char	*var_value;
	char	*exp_part;

	start = *index + 1;
	while (input_line[*index + 1] && (ft_isalnum(input_line[*index + 1])
			|| input_line[*index + 1] == '_'))
		(*index)++;
	var_name = ft_substr(input_line, start, *index - start + 1);
	var_value = ft_getenv(var_name, shell_state->active_env);
	if (var_value)
		exp_part = ft_strdup(var_value);
	else
		exp_part = ft_strdup("");
	free(var_name);
	return (exp_part);
}

void	ft_handle_delimited_warning(char *delimiter)
{
	char	*warning_msg;

	warning_msg = ft_strjoin("minishell: warning: \
	here-doc delimited by end-of-file (wanted `", delimiter);
	if (!warning_msg)
		return ;
	warning_msg = ft_strjoin_free(warning_msg, "`)\n");
	if (warning_msg)
	{
		ft_putstr_fd(warning_msg, STDERR_FILENO);
		free(warning_msg);
	}
}

char	*ft_expansions(char *arg, t_env_variable *env, int ret)
{
	t_expand_data	data;
	int				new_arg_len;

	new_arg_len = ft_arg_alloc_len(arg, env, ret);
	data.expanded_str = malloc(sizeof(char) * (new_arg_len + 1));
	if (!data.expanded_str)
		return (NULL);
	data.src_index = 0;
	data.dest_index = 0;
	while (data.src_index < new_arg_len && arg[data.dest_index])
	{
		while (arg[data.dest_index] == EXPANSION)
		{
			data.dest_index++;
			if ((arg[data.dest_index] == '\0' || \
			ft_isalnum(arg[data.dest_index]) == 0) \
			&& arg[data.dest_index] != '?')
				data.expanded_str[data.src_index++] = '$';
			else
				ft_insert_var(&data, arg, env, ret);
		}
		data.expanded_str[data.src_index++] = arg[data.dest_index++];
	}
	data.expanded_str[data.src_index] = '\0';
	return (data.expanded_str);
}
