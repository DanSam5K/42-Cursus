/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:37:29 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 16:59:03 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_token(t_cmd_token *start)
{
	while (start && start->next)
	{
		ft_memdel(start->content);
		start = start->next;
		ft_memdel(start->prev);
	}
	if (start)
	{
		ft_memdel(start->content);
		ft_memdel(start);
	}
}

void	ft_free_env(t_env_variable *env)
{
	t_env_variable	*tmp;

	while (env && env->next)
	{
		tmp = env;
		env = env->next;
		ft_memdel(tmp->variable);
		ft_memdel(tmp);
	}
	ft_memdel(env->variable);
	ft_memdel(env);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			ft_memdel(tab[i]);
		i++;
	}
	if (tab)
		ft_memdel(tab);
}

int	ft_clear(void)
{
	write(STDOUT, "\033[H\033[J", 6);
	return (0);
}

char	*ft_handle_expansion(const char *input_line,
	int *i, t_shell_state *shell_state)
{
	if (input_line[*i] == '$' && input_line[*i + 1]
		&& ft_isalpha(input_line[*i + 1]))
		return (ft_expand_variable(input_line, i, shell_state));
	return (ft_expand_character(input_line[*i]));
}
