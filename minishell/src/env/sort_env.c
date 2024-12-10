/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:15:58 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/17 19:07:16 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	ft_sort_env(char **tab, int env_len)
{
	int		ordered;
	int		i;
	char	*tmp;

	ordered = 0;
	while (tab && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		env_len--;
	}
}

int	ft_env_init(t_shell_state *shell_state, char **env_array)
{
	t_env_variable	*env;
	t_env_variable	*new;
	int				i;

	env = malloc(sizeof(t_env_variable));
	if (!env)
		return (1);
	env->variable = ft_strdup(env_array[0]);
	env->next = NULL;
	shell_state->active_env = env;
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
	return (0);
}

void	ft_print_sorted_env(t_env_variable *env)
{
	int		i;
	char	**tab;
	char	*str_env;

	str_env = ft_env_to_str(env);
	tab = ft_split(str_env, '\n');
	ft_memdel(str_env);
	ft_sort_env(tab, ft_str_env_len(tab));
	i = 0;
	while (tab[i])
	{
		ft_putstr("declare -x ");
		ft_putendl(tab[i]);
		i++;
	}
	ft_free_tab(tab);
}
