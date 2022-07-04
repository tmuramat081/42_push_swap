/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:59:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/17 11:59:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_ARGS "invalid arguments."

# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>
# include "structure.h"
# include "operation.h"
# include "libft.h"
# include "ft_deque.h"
# include "ft_vector.h"
# include "ft_pqueue.h"
# include "ft_hashset.h"

// ********** Main solver ********** //
int		*input_numbers(char **args, size_t n);
int		*format_numbers(int *arr_src, size_t n);
void	solve_push_swap(int *nums, size_t size);

// ********** Solver algorithm ********** //
t_node	*search_opt_operations(t_node *first_node, t_solver *solver);
size_t	hash_node(const void *node);
int		priority_comparator(const void *ptr1, const void *ptr2);
void	evalatoruate_cost(t_node *node, t_vector *dp_tab);
bool	is_valid_operation(t_node *node, t_operation op);
t_node	*copy_node(const t_node *src);

// ********** Dynamic Programming ********** //
size_t	dp_calculate_lics(t_deque *stack);
void	init_dp_table(t_tab *dp_tab, size_t size);
void	clear_dp_table(t_tab *dp_tab);
void	delete_dp_table(t_tab *dp_tab);
void	clear_lics_tags(t_deque *stack);

void	put_answer(t_vector *ops);
void	calculate_lics(t_deque *stack, t_vector *dp_tab);
void	print_operation(void *op);

void	print_node(t_node *node);
void	*deque_circular_next(t_deque *stack, void *i);
void	*deque_circular_prev(t_deque *stack, void *i);

void	delete_node(void *ptr);
void	hundle_error(t_node *node);

size_t	evaluator_1(t_node *node);
size_t	evaluator_2(t_node *node);
size_t	evaluator_3(t_node *node);
bool	checker_1(t_node *node);
bool	checker_2(t_node *node);
bool	checker_3(t_node *node);

#endif