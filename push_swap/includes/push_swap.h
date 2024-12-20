/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:44:04 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/02 10:18:44 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_meta
{
	int		argc;
	char	**ptr;
}	t_meta;

/***** stack/s_utils.c *****/
t_node	*create_node(int content);
t_node	*add_node(t_node *node, int content);
t_node	*last_or_first_node(t_node *node, bool last);
void	print_stack(t_node *stack);
void	clear_lst_node(t_node *node);

/***** stack/s_operations.c *****/
bool	swap(t_node **stack);
bool	push(t_node **src_stack, t_node **dest_stack);
bool	rotate(t_node **stack, bool reverse);
bool	execute(t_node **stack_a, t_node **stack_b, char *line, bool s_print);
bool	execute_all(t_node **stack_a, t_node **stack_b, char *line, int n);

/*****  stack/s_misc.c  *****/
int		max(int val_a, int val_b);
int		min(int val_a, int val_b);
int		stack_size(t_node *stack);
int		ft_strcmp_ps(const char *s1, const char *s2);
void	check_exit_or_exec(t_node **stack_a, t_node **stack_b,
			const char *line);

/***** algorithm/calculations.c *****/
int		min_moves(int positions[2], int stack_a_length,
			int stack_b_length, bool return_optimal_move);
int		calculate_moves(t_node *a, t_node *b, int len_a, bool ret_pos_b);
int		execute_calc_move(t_node *stack_a, t_node *stack_b,
			int stack_a_len, bool return_position_b);

/***** algorithm/sort_algo.c *****/
int		find_insertion_target(t_node *src_stack, t_node *dest_stack);
void	push_target_to_pos(t_node *stack, int target_position);
void	execute_sync_moves(t_node **stack_a, t_node **stack_b,
			int positions[2], int rotation_mode);
void	reverse_positions(t_node **stack_a, t_node **stack_b, int positions[2]);

/***** algorithm/sort_algo_utils.c *****/
bool	is_stack_sorted(t_node *stack, bool reverse_order);
void	mnx_push_pos(t_node *stack, bool find_max);
int		find_node_index(t_node *stack, int target_value);
int		find_mnx_pos(t_node *stack, bool find_max, bool return_position);
int		find_min_index(t_node *stack_a, t_node *stack_b, int stack_size);

/***** algorithm/push_swap.c *****/
void	execute_push_swap(t_node **stack_a, t_node **stack_b,
			int positions[2], int operation_mode);
void	sort_three_elements(t_node *stack_a);
void	advanced_sort_three_plus(t_node *stack_a, t_node *stack_b,
			int stack_size);
void	perform_sort(t_node *stack_a, t_node *stack_b);
void	push_swap(t_node *stack_a, t_node *stack_b, int stack_size);

/***** Generic functions *****/
int		ft_atoi_ps(char *str, t_node *stack_a, t_meta *meta_data);
bool	is_valid_int(t_node *stack_a, char *str, t_meta *meta_data);
void	ft_error(t_node *stack_a);
void	free_double_ptr(char **ptr);
void	free_meta(char *str, t_node *stack_a, t_meta *meta);

#endif