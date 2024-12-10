/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:04:46 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/27 22:02:17 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_print_err_export(int return_err, const char *arg)
{
	int	i;

	if (return_err == -1)
		ft_putstr_fd("export: not a valid identifier: ", STDERR);
	else if (return_err == 0 || return_err == -3)
		ft_putstr_fd("not a valid identifier: ", STDERR);
	i = 0;
	while (arg[i] && (arg[i] != '=' || return_err == -3))
	{
		write(STDERR, &arg[i], 1);
		i++;
	}
	write(STDERR, "\n", 1);
	return (ERROR);
}

static void	ft_add_new_env_variable(char *arg, int error_ret,
	t_env_variable *env, t_env_variable *secret)
{
	if (error_ret == 1)
		ft_add_to_env(arg, env);
	ft_add_to_env(arg, secret);
}

int	ft_export(char **args, t_env_variable *env, t_env_variable *secret)
{
	int	new_env;
	int	error_ret;

	new_env = 0;
	if (!args[1])
	{
		ft_print_sorted_env(secret);
		return (SUCCESS);
	}
	else
	{
		error_ret = ft_is_valid_env(args[1]);
		if (args[1][0] == '=')
			error_ret = -3;
		if (error_ret <= 0)
			return (ft_print_err_export(error_ret, args[1]));
		if (error_ret == 2)
			new_env = 1;
		else
			new_env = ft_is_in_env(env, args[1]);
		if (new_env == 0)
			ft_add_new_env_variable(args[1], error_ret, env, secret);
	}
	return (SUCCESS);
}
