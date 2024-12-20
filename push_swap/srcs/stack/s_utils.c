/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:28:32 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/02 14:00:04 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	print_stack(t_node *node)
{
	if (!node)
		return ;
	node = last_or_first_node(node, false);
	while (node)
	{
		ft_printf("%d ", node-> content);
		node = node->next;
	}
}

void	clear_lst_node(t_node *node)
{
	t_node	*tmp_node;

	if (!node)
		return ;
	node = last_or_first_node(node, false);
	while (node)
	{
		tmp_node = node->next;
		free(node);
		node = tmp_node;
	}
}

t_node	*add_node(t_node *node, int content)
{
	t_node	*new_node;

	new_node = create_node(content);
	if (!new_node)
		return (NULL);
	if (!node)
		return (new_node);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

/*
** last_or_first_node() returns the last or first node of a linked list
** depending on the value of the bool last.
** If last is true, the last node is returned.
*/
t_node	*last_or_first_node(t_node *node, bool is_last)
{
	if (!node)
		return (NULL);
	if (!is_last)
	{
		while (node->prev)
			node = node->prev;
		return (node);
	}
	else
	{
		while (node->next)
			node = node->next;
		return (node);
	}
}
