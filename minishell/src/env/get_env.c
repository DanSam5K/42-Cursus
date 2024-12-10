/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:58:58 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/26 14:13:35 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_env_char(int c)
{
	if (ft_isalnum(c) == 1 || c == '_')
		return (1);
	return (0);
}

int	ft_is_valid_env(const char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[i]) == 1)
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (ft_is_env_char(env[i]) == 0)
			return (-1);
		i++;
	}
	if (env[i] != '=')
		return (2);
	return (1);
}

int	ft_env_value_len(const char *env)
{
	int	i;
	int	size_name;

	size_name = 0;
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	while (env[i])
	{
		i++;
		size_name++;
	}
	return (size_name);
}

char	*ft_env_value(char *env)
{
	int		i;
	int		j;
	int		size_alloc;
	char	*env_value;

	size_alloc = ft_env_value_len(env) + 1;
	env_value = malloc(sizeof(char) * size_alloc);
	if (!env_value)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i += 1;
	j = 0;
	while (env[i])
		env_value[j++] = env[i++];
	env_value[j] = '\0';
	return (env_value);
}

char	*ft_get_env_value(char *arg, t_env_variable *env)
{
	char	env_name[BUFF_SIZE];
	char	*env_val;

	env_val = ft_strdup("");
	while (env && env->variable)
	{
		ft_get_env_name(env_name, env->variable);
		if (ft_strcmp(arg, env_name) == 0)
		{
			ft_memdel(env_val);
			env_val = ft_env_value(env->variable);
			return (env_val);
		}
		env = env->next;
	}
	return (env_val);
}
