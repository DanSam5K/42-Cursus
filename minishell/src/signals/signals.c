/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:00:14 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 18:12:37 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_integer(int sig_nal)
{
	(void)sig_nal;
	if (g_global_sig.child_proc_id == 0)
	{
		ft_putstr_fd("\b\b", STDERR);
		if (g_global_sig.print_prompt != 1)
		{
			g_global_sig.print_prompt = 0;
			rl_replace_line("", 0);
			rl_on_new_line();
			ft_putstr_fd("\n", STDERR);
			rl_redisplay();
		}
		g_global_sig.last_exit_stat = 130;
	}
	else
	{
		ft_putstr_fd("\n", STDERR);
		g_global_sig.last_exit_stat = 130;
	}
	g_global_sig.sigint_received = 1;
}

void	ft_sig_exit(int sig_nal)
{
	char	*nbr;

	nbr = ft_itoa(sig_nal);
	if (g_global_sig.child_proc_id != 0)
	{
		ft_putstr_fd("Quit:", STDERR);
		ft_putendl_fd(nbr, STDERR);
		g_global_sig.last_exit_stat = 131;
		g_global_sig.sigquit_received = 1;
	}
	else
		ft_putstr_fd("\b\b  \b\b", STDERR);
	ft_memdel(nbr);
}

void	ft_sig_init(void)
{
	g_global_sig.sigint_received = 0;
	g_global_sig.sigquit_received = 0;
	g_global_sig.child_proc_id = 0;
	g_global_sig.last_exit_stat = 0;
	g_global_sig.print_prompt = 0;
}
