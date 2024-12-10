/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:36:33 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/18 00:37:01 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_command(char *path, char **args, t_env_variable *env, \
t_shell_state *shell_state)
{
	char	**env_array;
	char	*env_string;
	int		ret;

	env_string = ft_env_to_str(env);
	env_array = ft_split(env_string, '\n');
	ft_memdel(env_string);
	if (ft_strchr(path, '/') != NULL)
		execve(path, args, env_array);
	ret = ft_error_message(path);
	ft_free_tab(env_array);
	ft_free_token(shell_state->cmd_list);
	exit(ret);
}
