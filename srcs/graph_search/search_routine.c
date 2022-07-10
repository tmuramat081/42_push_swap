/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:31:12 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:31:12 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

#define INIT_CAPACITY 128

static t_node	*update_node(t_node *node, t_pqueue *open, t_hashset *closed)
{
	t_node	*new_node;

	new_node = copy_node(node);
	ft_priority_queue_delete(&open, delete_node);
	ft_hashset_delete(&closed);
	delete_node(node);
	return (new_node);
}

static void	select_next_node(t_pqueue *tmp_open, t_pqueue *open, size_t n)
{
	t_node	*node;
	size_t	i;

	i = 0;
	while (i < (size_t)ft_min(n, ft_priority_queue_size(tmp_open)))
	{
		node = ft_priority_queue_pop(tmp_open);
		ft_priority_queue_push(open, node);
		i++;
	}
}

static void	expand_nodes(t_node *node, t_pqueue *open, t_hashset *closed,
			const t_solver *solver)
{
	t_node		*tmp_node;
	t_pqueue	*tmp_open;
	t_operation	next_op;

	tmp_open = ft_priority_queue_init(OP_END, &priority_comparator);
	next_op = OP_SA;
	while (next_op < OP_END)
	{
		if (is_valid_operation(node, next_op) == true)
		{
			tmp_node = copy_node(node);
			exec_operation(tmp_node, next_op);
			evaluate_next_node(tmp_node, tmp_open, closed, solver->evaluator);
		}
		next_op++;
	}
	select_next_node(tmp_open, open, solver->search_width);
	ft_priority_queue_delete(&tmp_open, delete_node);
}

t_node	*search_opt_operations(t_node *first_node, const t_solver *solver)
{
	t_pqueue	*open;
	t_hashset	*closed;
	t_node		*node;

	open = ft_priority_queue_init(INIT_CAPACITY, &priority_comparator);
	closed = ft_hashset_init(&hash_node);
	evaluate_first_node(first_node, open, closed, solver->evaluator);
	while (ft_priority_queue_is_empty(open) == false)
	{
		node = ft_priority_queue_pop(open);
		print_node(node);
		if (solver->checker(node) == true)
			break ;
		expand_nodes(node, open, closed, solver);
		delete_node(node);
	}
	return (update_node(node, open, closed));
}
