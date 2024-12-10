/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:44:43 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/17 18:51:36 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_error(char **args)
{
	ft_putstr_fd("cd: ", STDERR);
	if (args[2])
		ft_putstr_fd("String not in pwd: ", STDERR);
	else
	{
		ft_putstr_fd(strerror(errno), STDERR);
		ft_putstr_fd(": ", STDERR);
	}
	ft_putendl_fd(args[1], STDERR);
}

static int	ft_update_old_pwd(t_env_variable *env)
{
	char	cwd[PATH_MAX];
	char	*old_pwd;

	if (getcwd(cwd, PATH_MAX) == NULL )
		return (ERROR);
	old_pwd = ft_strjoin("OLDPWD=", cwd);
	if (!old_pwd)
		return (ERROR);
	if (ft_is_in_env(env, old_pwd) == SUCCESS)
		ft_add_to_env(old_pwd, env);
	ft_memdel(old_pwd);
	return (SUCCESS);
}

static int	ft_update_pwd(t_env_variable *env)
{
	char	cwd[PATH_MAX];
	char	*new_pwd;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (ERROR);
	new_pwd = ft_strjoin("PWD=", cwd);
	if (!new_pwd)
		return (ERROR);
	if (ft_is_in_env(env, new_pwd) == SUCCESS)
		ft_add_to_env(new_pwd, env);
	ft_memdel(new_pwd);
	return (SUCCESS);
}

static int	ft_go_to_path(int is_old, t_env_variable *env)
{
	int		return_cd;
	char	*path;

	path = NULL;
	if (is_old == 0)
	{
		path = ft_get_env_path(env, "HOME", 4);
		if (!path)
			ft_putendl_fd("cd: HOME not set", STDERR);
		if (!path)
			return (ERROR);
	}
	else if (is_old == 1)
	{
		path = ft_get_env_path(env, "OLDPWD", 6);
		if (!path)
		{
			ft_putendl_fd("cd: OLDPWD not set", STDERR);
			return (ERROR);
		}
		ft_update_old_pwd(env);
	}
	return_cd = chdir(path);
	ft_memdel(path);
	return (return_cd);
}

int	ft_cd(char **args, t_shell_state *shell_state)
{
	int		return_cd;
	char	*path;

	if (!args[1])
		return (ft_go_to_path(0, shell_state->active_env));
	if (ft_strcmp(args[1], "-") == 0)
		return_cd = ft_go_to_path(1, shell_state->active_env);
	else if (args[1][0] == '~')
	{
		path = ft_strjoin(shell_state->tilde, &args[1][1]);
		ft_update_old_pwd(shell_state->active_env);
		return_cd = chdir(path);
		ft_memdel(path);
	}
	else
	{
		ft_update_old_pwd(shell_state->active_env);
		return_cd = chdir(args[1]);
	}
	if (return_cd == 0)
		ft_update_pwd(shell_state->active_env);
	else if (return_cd != 0)
		ft_print_error(args);
	return (return_cd);
}
