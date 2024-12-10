/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:03:22 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/17 18:21:38 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_my_add_history(const char *command, t_shell_state *shell_state)
{
	int	i;

	if (shell_state->history_count < MAX_HISTORY)
	{
		shell_state->history[shell_state->history_count] = ft_strdup(command);
		shell_state->history_count++;
	}
	else
	{
		free(shell_state->history[0]);
		i = 0;
		while (++i < MAX_HISTORY)
			shell_state->history[i - 1] = shell_state->history[i];
		shell_state->history[MAX_HISTORY - 1] = ft_strdup(command);
	}
}

int	ft_print_history(t_shell_state *shell_state)
{
	int	i;

	i = -1;
	while (++i < shell_state->history_count)
		printf("%d: %s\n", i + 1, shell_state->history[i]);
	return (SUCCESS);
}

void	ft_free_history(t_shell_state shell_state)
{
	int	i;

	i = -1;
	while (++i < shell_state.history_count)
		free(shell_state.history[i]);
}
