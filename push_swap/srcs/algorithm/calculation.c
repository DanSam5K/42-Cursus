/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:43:18 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/27 18:44:40 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_move(int *arr, int size, bool return_index)
{
	int	min;
	int	index;
	int	target_index;

	index = 0;
	target_index = 0;
	min = arr[0];
	while (++index < size)
	{
		if (arr[index] < min && arr[index] >= 0)
		{
			min = arr[index];
			target_index = index;
		}
	}
	if (return_index == true)
		return (target_index);
	return (min);
}

int	min_moves(int positions[2], int stack_a_length, int stack_b_length,
		bool return_optimal_move)
{
	int	move_counts[4];
	int	original_pos_b;

	original_pos_b = -1;
	if (positions[1] == 0)
	{
		original_pos_b = positions[1];
		positions[1] = positions[0];
	}
	if (positions[0] < positions[1])
		move_counts[0] = positions[1];
	else
		move_counts[0] = positions[0];
	if (stack_a_length - positions[0] < stack_b_length - positions[1])
		move_counts[1] = (stack_b_length - positions[1]);
	else
		move_counts[1] = (stack_a_length - positions[0]);
	move_counts[2] = positions[0] + (stack_b_length - positions[1]);
	move_counts[3] = (stack_a_length - positions[0]) + positions[1];
	if (original_pos_b != -1)
		positions[1] = original_pos_b;
	if (return_optimal_move == true)
		return (get_min_move(move_counts, 4, true));
	else
		return (get_min_move(move_counts, 4, false));
}

int	calculate_moves(t_node *a, t_node *b, int len_a, bool ret_pos_b)
{
	t_node	*tmp_b;
	int		mv_a;
	int		mv_b;
	int		tgt;

	mv_a = find_node_index(a, a->content);
	if (b)
	{
		tmp_b = last_or_first_node(b, false);
		tgt = tmp_b->content;
		while (tmp_b)
		{
			if ((tmp_b->content < tgt && tmp_b->content > a->content)
				|| (tmp_b->content > a->content && tgt < a->content))
				tgt = tmp_b->content;
			tmp_b = tmp_b->next;
		}
		mv_b = find_node_index(b, tgt);
		if (ret_pos_b)
			return (mv_b);
		return (min_moves((int [2]){mv_a, mv_b}, len_a,
			stack_size(b), false) + 1);
	}
	return (mv_a + 1);
}

int	execute_calc_move(t_node *stack_a, t_node *stack_b,
	int stack_a_len, bool return_position_b)
{
	int	move_count;
	int	positions[2];

	if ((stack_a->content < find_mnx_pos(stack_b, false, false))
		|| (stack_a->content > find_mnx_pos(stack_b, true, false)))
	{
		positions[0] = find_node_index(stack_a, stack_a->content);
		positions[1] = find_mnx_pos(stack_b, true, true);
		if (return_position_b == true)
			move_count = positions[1];
		else
			move_count = (min_moves(positions, stack_a_len,
						stack_size(stack_b), false) + 1);
	}
	else
		move_count = calculate_moves(stack_a, stack_b,
				stack_a_len, return_position_b);
	return (move_count);
}
