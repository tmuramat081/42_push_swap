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

static void	expand_nodes(t_node *node, t_pqueue *open, t_hashset *closed,
			const t_solver *solver)
{
	t_node		*tmp_node;
	size_t		i;

	i = 0;
	while (solver->operations[i] < OP_END)
	{
		if (is_valid_operation(node, solver->operations[i]) == true)
		{
			tmp_node = copy_node(node);
			exec_operation(tmp_node, solver->operations[i]);
			evaluate_next_node(tmp_node, open, closed, solver->evaluator);
		}
		i++;
	}
}

t_node	*search_opt_operations(t_node *first_node, const t_solver *solver)
{
	t_pqueue	*open;
	t_hashset	*closed;
	t_node		*node;

	open = ft_priority_queue_init(INIT_CAPACITY, priority_comparator);
	closed = ft_hashset_init(&hash_node);
	evaluate_first_node(first_node, open, closed, solver->evaluator);
	while (ft_priority_queue_is_empty(open) == false)
	{
		node = ft_priority_queue_pop(open);
		print_node(node);
		if (solver->checker(node) == true)
			return (update_node(node, open, closed));
		expand_nodes(node, open, closed, solver);
		delete_node(node);
	}
	return (NULL);
}
