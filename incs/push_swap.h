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
# include <stdio.h>
# include <assert.h>
# include "libft.h"
# include "ft_deque.h"
# include "ft_vector.h"
# include "ft_pqueue.h"
# include "ft_hashset.h"

typedef struct s_tab {
	t_vector	*val;
	t_vector	*idx;
}	t_tab;

typedef struct s_data {
	int		value;
	bool	is_sorted;
}	t_data;

typedef struct s_node {
	t_deque		*stack_a;
	t_deque		*stack_b;
	size_t		lics_a;
	size_t		size;
	size_t		cost;
	t_vector	*ops;
}	t_node;

typedef size_t	(*t_eval)(t_node *);
typedef bool	(*t_check)(t_node *);

typedef struct t_solver {
	t_eval		evaluator;
	t_check		checker;
	size_t		search_width;
}	t_solver;

// ********** Main solver ********** //
int		*input_numbers(char **args, size_t n);
void	solve_push_swap(int *nums, size_t size);

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
void	print_vector(t_vector *tab);
void	print_deque(t_deque *stack);

void	push_number(t_deque *stack, int *arr);
void	delete_node(void *ptr);
void	hundle_error(t_node *node);

size_t	evaluator_1(t_node *node);
size_t	evaluator_2(t_node *node);
size_t	evaluator_3(t_node *node);
bool	checker_1(t_node *node);
bool	checker_2(t_node *node);
bool	checker_3(t_node *node);

#endif