/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojacobs <ojacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:25:18 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/27 22:03:26 by ojacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_message(char *path)
{
	DIR	*folder;
	int	fd;
	int	ret;

	fd = open(path, O_WRONLY);
	folder = opendir(path);
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	if (ft_strchr(path, '/') == NULL)
		ft_putendl_fd(": command not found", STDERR);
	else if (fd == -1 && folder == NULL)
		ft_putendl_fd(": No such file or directory", STDERR);
	else if (fd == -1 && folder != NULL)
		ft_putendl_fd(": is a directory", STDERR);
	else if (fd != -1 && folder == NULL)
		ft_putendl_fd(": Permission denied", STDERR);
	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
		ret = UNKNOWN_CMD;
	else
		ret = IS_DIRECTORY;
	if (folder)
		closedir(folder);
	ft_close(fd);
	return (ret);
}

int	ft_magic_box(char *path, char **args, t_env_variable *env,
	t_shell_state *shell_state)
{
	int		ret;

	ret = SUCCESS;
	g_global_sig.child_proc_id = fork();
	if (g_global_sig.child_proc_id == 0)
		ft_execute_command(path, args, env, shell_state);
	else
		waitpid(g_global_sig.child_proc_id, &ret, 0);
	if (g_global_sig.sigint_received == 1
		|| g_global_sig.sigquit_received == 1)
		return (g_global_sig.last_exit_stat);
	if (ret == 32256 || ret == 32512 || ret == 512)
		ret = ret / 256;
	else
		ret = !!ret;
	return (ret);
}

char	*ft_path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	ft_memdel(tmp);
	return (path);
}

char	*ft_check_dir(char *bin, char *command)
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	folder = opendir(bin);
	if (!folder)
		return (NULL);
	item = readdir(folder);
	while (item != NULL)
	{
		if (ft_strcmp(item->d_name, command) == 0)
			path = ft_path_join(bin, item->d_name);
		item = readdir(folder);
	}
	closedir(folder);
	return (path);
}

int	ft_exec_bin(char **args, t_env_variable *env, t_shell_state *shell_state)
{
	int		i;
	char	**bin;
	char	*path;
	int		ret;

	i = 0;
	ret = UNKNOWN_CMD;
	while (env && env->variable && ft_strncmp(env->variable, "PATH=", 5) != 0)
		env = env->next;
	if (env == NULL || env->next == NULL)
		return (ft_magic_box(args[0], args, env, shell_state));
	bin = ft_split(env->variable, ':');
	if (!args[0] && !bin[0])
		return (ERROR);
	i = 1;
	path = ft_check_dir(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
		path = ft_check_dir(bin[i++], args[0]);
	if (path != NULL)
		ret = ft_magic_box(path, args, env, shell_state);
	else
		ret = ft_magic_box(args[0], args, env, shell_state);
	ft_free_tab(bin);
	ft_memdel(path);
	return (ret);
}
