/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:12:04 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/26 21:27:01 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_stack_sorted(t_node *stack, bool reverse_order)
{
	t_node	*current_node;
	int		stack_length;

	stack_length = stack_size(stack);
	current_node = last_or_first_node(stack, false);
	if ((stack_length == 0) || !stack)
		return (false);
	while (current_node->next)
	{
		if (current_node->content > current_node->next->content
			&& reverse_order == false)
			return (false);
		if (current_node->content < current_node->next->content
			&& reverse_order == true)
			return (false);
		current_node = current_node->next;
	}
	return (true);
}

int	find_node_index(t_node *stack, int target_value)
{
	t_node	*tmp_node;
	int		node_index;

	node_index = 0;
	tmp_node = last_or_first_node(stack, false);
	if (stack_size(stack) == 0 || !stack)
		return (-1);
	while (tmp_node)
	{
		if (tmp_node->content == target_value)
			return (node_index);
		tmp_node = tmp_node->next;
		node_index++;
	}
	return (-1);
}

int	find_mnx_pos(t_node *stack, bool find_max, bool return_position)
{
	int		current_index;
	int		target_value;
	int		target_position;
	t_node	*current_node;

	current_index = 0;
	target_position = 0;
	current_node = last_or_first_node(stack, false);
	target_value = current_node->content;
	while (current_index < stack_size(stack))
	{
		if ((find_max && current_node->content > target_value)
			|| (!find_max && current_node->content < target_value))
		{
			target_value = current_node->content;
			target_position = current_index;
		}
		current_node = current_node->next;
		current_index++;
	}
	if (return_position)
		return (target_position);
	else
		return (target_value);
}

void	mnx_push_pos(t_node *stack, bool find_max)
{
	int	position_of_target;

	position_of_target = find_mnx_pos(stack, find_max, true);
	push_target_to_pos(stack, position_of_target);
}

int	find_min_index(t_node *stack_a, t_node *stack_b, int stack_size)
{
	int		min_value;
	int		moves_count;
	int		min_index[2];
	t_node	*tmp_node;

	tmp_node = last_or_first_node(stack_a, false);
	min_value = execute_calc_move(stack_a, stack_b, stack_size, false);
	min_index[0] = 0;
	min_index[1] = 0;
	while (tmp_node)
	{
		moves_count = execute_calc_move(tmp_node, stack_b, stack_size, false);
		if (moves_count < min_value)
		{
			min_value = moves_count;
			min_index[1] = min_index[0];
		}
		tmp_node = tmp_node->next;
		min_index[0]++;
	}
	return (min_index[1]);
}
