/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_val_level.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:54 by dsamuel           #+#    #+#             */
/*   Updated: 2024/11/27 21:05:41 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_invalid_lvl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_lvl(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	ft_skip_spacenl(str, &i);
	if (ft_invalid_lvl(str))
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

void	ft_increment_shell_level(t_env_variable *env)
{
	int		sh_lvl_size;
	char	env_name[BUFF_SIZE];
	char	*sh_lvl;
	char	*sh_lvl_val;

	sh_lvl_val = ft_get_env_value("SHLVL", env);
	if (ft_strcmp(sh_lvl_val, "") == 0)
		return ;
	sh_lvl_size = ft_get_lvl(sh_lvl_val) + 1;
	ft_memdel(sh_lvl_val);
	while (env && env->next)
	{
		ft_get_env_name(env_name, env->variable);
		if (ft_strcmp("SHLVL", env_name) == 0)
		{
			ft_memdel(env->variable);
			sh_lvl = ft_itoa(sh_lvl_size);
			env->variable = ft_strjoin("SHLVL=", sh_lvl);
			ft_memdel(sh_lvl);
			return ;
		}
		env = env->next;
	}
}
