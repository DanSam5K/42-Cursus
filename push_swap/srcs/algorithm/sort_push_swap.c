/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:25:16 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/26 21:07:02 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_push_swap(t_node **stack_a, t_node **stack_b,
	int positions[2], int operation_mode)
{
	if (operation_mode == 0 || operation_mode == 1)
		execute_sync_moves(stack_a, stack_b, positions, operation_mode);
	else if (operation_mode == 2)
	{
		execute_all(stack_a, stack_b, "ra", positions[0]);
		execute_all(stack_a, stack_b, "rrb",
			stack_size(*stack_b) - positions[1]);
	}
	else if (operation_mode == 3)
	{
		execute_all(stack_a, stack_b, "rra",
			stack_size(*stack_a) - positions[0]);
		execute_all(stack_a, stack_b, "rb", positions[1]);
	}
}

void	sort_three_elements(t_node *stack_a)
{
	if (stack_a->content > stack_a->next->content)
	{
		if (stack_a->content < stack_a->next->next->content)
			execute(&stack_a, NULL, "sa", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "rra", false);
		}
		else
			execute(&stack_a, NULL, "ra", false);
	}
	else if (stack_a->content < stack_a->next->content)
	{
		if (stack_a->content > stack_a->next->next->content)
			execute(&stack_a, NULL, "rra", false);
		else if (stack_a->next->content > stack_a->next->next->content)
		{
			execute(&stack_a, NULL, "sa", false);
			execute(&stack_a, NULL, "ra", false);
		}
	}
}

void	advanced_sort_three_plus(t_node *stack_a,
	t_node *stack_b, int stack_size)
{
	int	stack_to_process;

	stack_to_process = stack_size;
	while (stack_to_process-- > 3)
	{
		mnx_push_pos(stack_a, false);
		execute(&stack_a, &stack_b, "pb", false);
	}
	sort_three_elements(stack_a);
	execute_all(&stack_a, &stack_b, "pa", stack_size - 3);
}

static void	move_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	tmp_index;
	int	target_positions[2];
	int	rotation_mode;

	execute_all(stack_a, stack_b, "pb", 2);
	while (stack_size(*stack_a) > 3)
	{
		target_positions[0] = find_min_index(*stack_a, *stack_b,
				stack_size(*stack_a));
		tmp_index = -1;
		while (++tmp_index < target_positions[0])
			*stack_a = (*stack_a)->next;
		target_positions[1] = execute_calc_move(*stack_a, *stack_b,
				stack_size(*stack_a), true);
		rotation_mode = min_moves(target_positions, stack_size(*stack_a),
				stack_size(*stack_b), true);
		if (rotation_mode == 1)
			reverse_positions(stack_a, stack_b, target_positions);
		execute_push_swap(stack_a, stack_b, target_positions, rotation_mode);
		execute(stack_a, stack_b, "pb", false);
	}
}

void	perform_sort(t_node *stack_a, t_node *stack_b)
{
	move_to_stack_b(&stack_a, &stack_b);
	sort_three_elements(stack_a);
	while (stack_size(stack_b) > 0)
	{
		push_target_to_pos(stack_a, find_insertion_target(stack_b, stack_a));
		execute(&stack_a, &stack_b, "pa", false);
	}
	mnx_push_pos(stack_a, false);
}
