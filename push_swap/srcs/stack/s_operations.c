/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:45:48 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/27 17:41:22 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_node **stack)
{
	t_node	*first_node;

	*stack = last_or_first_node(*stack, false);
	if (!stack || !*stack || !(*stack)->next)
		return (true);
	first_node = (*stack)->next;
	(*stack)->next = first_node->next;
	if (first_node->next != NULL)
		first_node->next->prev = *stack;
	first_node->next = *stack;
	first_node->prev = NULL;
	(*stack)->prev = first_node;
	*stack = first_node;
	return (true);
}

bool	push(t_node **src_stack, t_node **dest_stack)
{
	t_node	*top_node;

	if (src_stack == NULL || *src_stack == NULL)
		return (true);
	*src_stack = last_or_first_node(*src_stack, false);
	*dest_stack = last_or_first_node(*dest_stack, false);
	top_node = (*src_stack)->next;
	if (top_node != NULL)
		top_node->prev = NULL;
	(*src_stack)->next = *dest_stack;
	if (*dest_stack != NULL)
		(*dest_stack)->prev = *src_stack;
	*dest_stack = *src_stack;
	*src_stack = top_node;
	return (true);
}

bool	rotate(t_node **stack, bool reverse)
{
	t_node	*top_node;

	*stack = last_or_first_node(*stack, false);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (true);
	top_node = *stack;
	if (!reverse)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		top_node->next = NULL;
		top_node->prev = last_or_first_node(*stack, true);
		last_or_first_node(*stack, true)->next = top_node;
	}
	else
	{
		*stack = last_or_first_node(*stack, true);
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = top_node;
		top_node->prev = *stack;
	}
	return (true);
}

bool	execute(t_node **stack_a, t_node **stack_b, char *line, bool s_print)
{
	if (!s_print)
		ft_printf("%s\n", line);
	if (ft_strcmp_ps(line, "sa") == 0)
		return (swap(stack_a));
	else if (ft_strcmp_ps(line, "sb") == 0)
		return (swap(stack_b));
	else if (ft_strcmp_ps(line, "ss") == 0)
		return (swap(stack_a) && swap(stack_b));
	else if (ft_strcmp_ps(line, "pa") == 0)
		return (push(stack_b, stack_a));
	else if (ft_strcmp_ps(line, "pb") == 0)
		return (push(stack_a, stack_b));
	else if (ft_strcmp_ps(line, "ra") == 0)
		return (rotate(stack_a, false));
	else if (ft_strcmp_ps(line, "rb") == 0)
		return (rotate(stack_b, false));
	else if (ft_strcmp_ps(line, "rr") == 0)
		return (rotate(stack_a, false) && rotate(stack_b, false));
	else if (ft_strcmp_ps(line, "rra") == 0)
		return (rotate(stack_a, true));
	else if (ft_strcmp_ps(line, "rrb") == 0)
		return (rotate(stack_b, true));
	else if (ft_strcmp_ps(line, "rrr") == 0)
		return (rotate(stack_a, true) && rotate(stack_b, true));
	return (false);
}

bool	execute_all(t_node **stack_a, t_node **stack_b, char *line, int n)
{
	while (n--)
	{
		if (!execute(stack_a, stack_b, line, false))
			return (false);
	}
	return (true);
}
