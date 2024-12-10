/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:31:30 by ojacobs           #+#    #+#             */
/*   Updated: 2024/11/17 18:39:07 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nb_args(char **args)
{
	int	size;

	size = 0;
	while (args[size])
		size++;
	return (size);
}

int	ft_add_to_env(const char *args, t_env_variable *env)
{
	t_env_variable	*new_env;
	t_env_variable	*tmp;

	if (env && env->variable == NULL)
	{
		env->variable = ft_strdup(args);
		return (SUCCESS);
	}
	new_env = malloc(sizeof(t_env_variable));
	if (!new_env)
		return (-1);
	new_env->variable = ft_strdup(args);
	while (env && env->next && env->next->next)
		env = env->next;
	tmp = env->next;
	env->next = new_env;
	new_env->next = tmp;
	return (SUCCESS);
}

char	*ft_get_env_name(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFF_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_echo(char **args)
{
	int		i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (nb_args(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (SUCCESS);
}
