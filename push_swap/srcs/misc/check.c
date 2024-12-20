/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:48:44 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/04 18:08:31 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_node *stack_a)
{
	clear_lst_node(stack_a);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	free_meta(char *str, t_node *stack_a, t_meta *meta)
{
	if (*str != '\0')
	{
		if (meta->argc == 2)
			free_double_ptr(meta->ptr);
		ft_error(stack_a);
	}
}

int	ft_atoi_ps(char *str, t_node *stack_a, t_meta *meta)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			if (meta->argc == 2)
				free_double_ptr(meta->ptr);
			ft_error(stack_a);
		}
		str++;
	}
	return (free_meta(str, stack_a, meta), (int)(result * sign));
}

bool	is_valid_int(t_node *stack_a, char *str, t_meta *meta)
{
	t_node	*tmp_node;
	int		num;

	tmp_node = last_or_first_node(stack_a, false);
	num = ft_atoi_ps(str, stack_a, meta);
	while (tmp_node)
	{
		if (tmp_node->content == num)
			return (ft_error(stack_a), false);
		tmp_node = tmp_node->next;
	}
	return (true);
}
