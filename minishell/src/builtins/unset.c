/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:30:16 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/27 22:02:36 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_env_size(char *env)
{
	size_t	size;

	size = 0;
	while (env[size] && env[size] != '=')
		size++;
	return (size);
}

static void	ft_remove_env(t_shell_state *shell_state, t_env_variable *env)
{
	if (shell_state->active_env == env && env->next == NULL)
	{
		ft_memdel(shell_state->active_env->variable);
		shell_state->active_env->variable = NULL;
		shell_state->active_env->next = NULL;
		return ;
	}
	ft_memdel(env->variable);
	ft_memdel(env);
}

static int	ft_remove_env_variable(t_shell_state *shell_state, char *arg)
{
	t_env_variable	*env;
	t_env_variable	*tmp;

	env = shell_state->active_env;
	while (env && env->next)
	{
		if (ft_strncmp(arg, env->next->variable,
				ft_env_size(env->next->variable)) == 0)
		{
			tmp = env->next->next;
			ft_remove_env(shell_state, env->next);
			env->next = tmp;
			return (SUCCESS);
		}
		env = env->next;
	}
	return (SUCCESS);
}

int	ft_unset(char **args, t_shell_state *shell_state)
{
	t_env_variable	*env;

	env = shell_state->active_env;
	if (!args[1])
		return (SUCCESS);
	if (ft_strncmp(args[1], env->variable, ft_env_size(env->variable)) == 0)
	{
		if (env->next)
			shell_state->active_env = env->next;
		else
			shell_state->active_env = shell_state->active_env;
		ft_remove_env(shell_state, env);
		return (SUCCESS);
	}
	return (ft_remove_env_variable(shell_state, args[1]));
}
