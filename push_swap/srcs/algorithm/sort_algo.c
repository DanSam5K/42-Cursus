/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:20:01 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/30 12:55:54 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insertion_target(t_node *src_stack, t_node *dest_stack)
{
	t_node	*tmp_node;
	int		target_value;
	int		target_position;

	tmp_node = last_or_first_node(dest_stack, false);
	target_value = tmp_node->content;
	target_position = find_mnx_pos(dest_stack, true, false);
	if (src_stack->content > target_position)
		return (find_mnx_pos(dest_stack, false, true));
	while (tmp_node)
	{
		if ((tmp_node->content < target_value
				&& tmp_node->content > src_stack->content)
			|| (tmp_node->content > src_stack->content
				&& target_value < src_stack->content))
			target_value = tmp_node->content;
		tmp_node = tmp_node->next;
	}
	return (find_node_index(dest_stack, target_value));
}

void	push_target_to_pos(t_node *stack, int target_position)
{
	int	stack_length;

	stack = last_or_first_node(stack, false);
	stack_length = stack_size(stack);
	if (target_position <= stack_length / 2)
	{
		while (target_position--)
			execute(&stack, NULL, "ra", false);
	}
	else
	{
		target_position = stack_length - target_position;
		while (target_position--)
			execute(&stack, NULL, "rra", false);
	}
}

void	execute_sync_moves(t_node **stack_a, t_node **stack_b,
	int positions[2], int rotation_mode)
{
	if (rotation_mode == 0)
	{
		execute_all(stack_a, stack_b, "rr",
			min(positions[0], positions[1]));
		if (max(positions[0], positions[1]) == positions[0]
			&& positions[0] != positions[1])
			execute_all(stack_a, stack_a, "ra", positions[0] - positions[1]);
		else if (max(positions[0], positions[1]) == positions[1]
			&& positions[0] != positions[1])
			execute_all(stack_a, stack_b, "rb", positions[1] - positions[0]);
	}
	else if (rotation_mode == 1)
	{
		execute_all(stack_a, stack_b, "rrr", min(positions[0], positions[1]));
		if (max(positions[0], positions[1]) == positions[0]
			&& positions[0] != positions[1])
			execute_all(stack_a, stack_a, "rra", positions[0] - positions[1]);
		else if (max(positions[0], positions[1]) == positions[1]
			&& positions[0] != positions[1]
			&& positions[1] != 0)
			execute_all(stack_a, stack_b, "rrb", positions[1] - positions[0]);
	}
}

void	reverse_positions(t_node **stack_a, t_node **stack_b, int positions[2])
{
	positions[0] = stack_size(*stack_a) - positions[0];
	if (positions[1] != 0)
		positions[1] = stack_size(*stack_b) - positions[1];
}
