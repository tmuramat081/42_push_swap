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

# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>
# include <time.h>
# include "structure.h"
# include "operation.h"
# include "libft.h"
# include "ft_deque.h"
# include "ft_vector.h"
# include "ft_pqueue.h"
# include "ft_hashset.h"

extern const t_solver	g_dataset;

// ********** Main program ********** //
int		*input_arguments(char **args, size_t n);
void	format_numbers(int **arr_src, size_t n);

// ********** Solver ********** //
void	solve_push_swap_problem(int *nums, size_t size);
void	rotate_elems(t_deque *stack, t_node *node);
void	put_answer(t_vector *operations);
t_node	*init_node(int *nums, size_t size);
void	delete_node(void *ptr);

// ********** Solver(insertion) ********** //
void	sort_by_insertion(t_node *node);
t_pair	calculate_min_insert_distance(t_node *node);
void	execute_greedy_operations(t_node *node, t_pair min_dist);

// ********** Solver(graph search) ********** //
void	sort_by_graph_search(t_node **node);
t_node	*search_opt_operations(t_node *first_node, const t_solver *solver);
void	evaluate_first_node(t_node *node, t_pqueue *open, t_hashset *closed,
			t_eval evaluator);
void	evaluate_next_node(t_node *tmp_node, t_pqueue *tmp_open,
			t_hashset *closed, t_eval evaluator);
bool	is_valid_operation(t_node *node, t_operation op);
size_t	hash_node(const void *node);
t_node	*copy_node(const t_node *src);

// ******* Longest Increasing Subsequence ******* //
size_t	evaluator(t_node *node);
size_t	calculate_lic_length(t_deque *stack);
void	put_on_lic_tags(t_vector *res);
void	init_dp_table(t_tab *dp_tab, size_t size);
void	clear_dp_table(t_tab *dp_tab);
void	delete_dp_table(t_tab *dp_tab);
int		get_circular_index(size_t i, size_t len);
void	*min_element(t_deque *stack);

// ********** checker ********** //
bool	checker(t_node *node);
int		priority_comparator(const void *ptr1, const void *ptr2);

void	common_hundle_error(t_node *node);
void	print_node(t_node *node);
void	*deque_circular_next(t_deque *stack, void *i);
void	*deque_circular_prev(t_deque *stack, void *i);

#endif