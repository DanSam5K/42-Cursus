/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:07:35 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/27 22:01:57 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env_path(t_env_variable *env, const char *var, size_t len)
{
	char	*old_pwd;
	size_t	s_alloc;

	while (env && env->next)
	{
		if (ft_strncmp(env->variable, var, len) == 0)
		{
			s_alloc = ft_strlen(env->variable) - len;
			old_pwd = malloc(s_alloc + 1);
			if (!old_pwd)
				return (NULL);
			ft_strlcpy(old_pwd, env->variable + len, s_alloc + 1);
			return (old_pwd);
		}
		env = env->next;
	}
	return (NULL);
}

int	ft_is_in_env(t_env_variable *env, char *args)
{
	char	var_name[BUFF_SIZE];
	char	env_name[BUFF_SIZE];

	ft_get_env_name(var_name, args);
	while (env && env->next)
	{
		ft_get_env_name(env_name, env->variable);
		if (ft_strcmp(var_name, env_name) == 0)
		{
			ft_memdel(env->variable);
			env->variable = ft_strdup(args);
			return (1);
		}
		env = env->next;
	}
	return (SUCCESS);
}

int	ft_env(t_env_variable *env)
{
	while (env && env->next != NULL)
	{
		ft_putendl(env->variable);
		env = env->next;
	}
	if (env)
		ft_putendl(env->variable);
	return (SUCCESS);
}
