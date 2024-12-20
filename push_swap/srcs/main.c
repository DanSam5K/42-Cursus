/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:16:37 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/02 11:52:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_ptr(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	init(char **argv, int argc, t_meta *meta)
{
	int	i;

	i = 0;
	if (argc > 2)
		i = 1;
	meta->ptr = argv;
	meta->argc = argc;
	if (argc == 2)
		meta->ptr = ft_split(argv[1], ' ');
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;
	t_meta	meta;

	stack_a = NULL;
	stack_b = NULL;
	i = init(argv, argc, &meta);
	if (argc > 1)
	{
		while (meta.ptr[i])
		{
			if (is_valid_int(stack_a, meta.ptr[i], &meta) == false)
				return (free_double_ptr(meta.ptr), ft_error(stack_a), 1);
			stack_a = add_node(stack_a, ft_atoi(meta.ptr[i]));
			i++;
		}
		push_swap(stack_a, stack_b, stack_size(stack_a));
		clear_lst_node(stack_a);
		clear_lst_node(stack_b);
	}
	if (meta.ptr && argc == 2)
		free_double_ptr(meta.ptr);
	return (0);
}
