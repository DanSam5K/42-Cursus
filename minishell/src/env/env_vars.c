/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:16:19 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 22:02:53 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_size_env(t_env_variable *lst)
{
	size_t	lst_len;

	lst_len = 0;
	while (lst && lst->next != NULL)
	{
		if (lst->variable != NULL)
		{
			lst_len += ft_strlen(lst->variable);
			lst_len++;
		}
		lst = lst->next;
	}
	return (lst_len);
}

static void	ft_copy_env_variables(t_env_variable *lst, char *env, int *index)
{
	int	j;

	while (lst && lst->next != NULL)
	{
		if (lst->variable != NULL)
		{
			j = 0;
			while (lst->variable[j])
			{
				env[*index] = lst->variable[j];
				(*index)++;
				j++;
			}
		}
		if (lst->next->next != NULL)
			env[(*index)++] = '\n';
		lst = lst->next;
	}
}

char	*ft_env_to_str(t_env_variable *lst)
{
	char	*env;
	int		i;

	i = 0;
	env = malloc(sizeof(char) * ft_size_env(lst) + 1);
	if (!env)
		return (NULL);
	ft_copy_env_variables(lst, env, &i);
	env[i] = '\0';
	return (env);
}

static void	ft_get_home_directory(t_shell_state *shell_state, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	if (envp[i] && ft_strncmp(envp[i], "HOME=", 5) == 0)
	{
		shell_state->tilde = ft_strdup (&envp[i][5]);
		if (!shell_state->tilde)
		{
			perror("erro copying home");
			exit(EXIT_FAILURE);
		}
	}
}

int	ft_secret_env_init(t_shell_state *shell_state, char **env_array)
{
	t_env_variable	*env;
	t_env_variable	*new;
	int				i;

	env = malloc(sizeof(t_env_variable));
	if (!env)
		return (1);
	env->variable = ft_strdup(env_array[0]);
	env->next = NULL;
	shell_state->secret_env = env;
	i = 1;
	while (env_array && env_array[0] && env_array[i])
	{
		new = malloc(sizeof(t_env_variable));
		if (!new)
			return (1);
		new->variable = ft_strdup(env_array[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	ft_get_home_directory(shell_state, env_array);
	return (0);
}
