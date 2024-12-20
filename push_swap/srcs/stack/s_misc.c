/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_misc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:10:58 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/26 18:10:44 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int val_a, int val_b)
{
	if (val_a > val_b)
		return (val_a);
	return (val_b);
}

int	min(int val_a, int val_b)
{
	if (val_a < val_b)
		return (val_a);
	return (val_b);
}

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*tmp_node;

	size = 0;
	tmp_node = last_or_first_node(stack, false);
	while (tmp_node)
	{
		size++;
		tmp_node = tmp_node->next;
	}
	return (size);
}

int	ft_strcmp_ps(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1++ != *s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	}
	return (0);
}

void	check_exit_or_exec(t_node **stack_a, t_node **stack_b, const char *line)
{
	if (stack_a == NULL || stack_b == NULL)
		ft_printf("%s\n", line);
	if (is_stack_sorted(*stack_a, false) && stack_size(*stack_b) == 0)
	{
		clear_lst_node(*stack_a);
		clear_lst_node(*stack_b);
		exit(0);
	}
	if (line != NULL)
		ft_printf("%s\n", line);
}
