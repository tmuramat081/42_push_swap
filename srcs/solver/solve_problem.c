/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_problem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:42:06 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:42:06 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_elems_of_a(t_node *node)
{
	t_data		*top_a;
	t_operation	op;

	top_a = ft_deque_front(node->stack_a);
	if (node->size / 2 >= (size_t)top_a->value)
		op = OP_RRA;
	else
		op = OP_RA;
	while (top_a->value != 0)
	{
		exec_operation(node, op);
		top_a = ft_deque_front(node->stack_a);
		print_node(node);
	}
}

bool	is_sorted(t_node *node)
{
	if (node->lic_a == node->size)
		return (true);
	return (false);
}

void	push_sorted_elems_to_a(t_node *node)
{
	while (!ft_deque_is_empty(node->stack_b))
	{
		execute_greedy_push_operation(node);
		print_node(node);
	}
}

void	push_unsorted_elems_to_b(t_node *node)
{
	t_data			*top_a;

	while (ft_deque_size(node->stack_a) != evaluate_lic_length(node->stack_a))
	{
		top_a = ft_deque_front(node->stack_a);
		if (top_a->is_sorted == false)
		{
			exec_operation(node, OP_PB);
		}
		exec_operation(node, OP_RA);
		print_node(node);
	}
}

void	solve_push_swap_problem(int *nums, size_t size)
{
	t_node	*node;

	node = init_first_node(nums, size);
	if (size < 30)
	{
		node = search_opt_operations(node, &g_dataset);
	}
	else
	{
		push_unsorted_elems_to_b(node);
		push_sorted_elems_to_a(node);
	}
	rotate_elems_of_a(node);
	put_answer(node->operations);
	delete_node(node);
}
