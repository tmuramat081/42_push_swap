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

const t_solver	g_dataset = {
	.operations = {OP_PB, OP_SA, OP_SB, OP_RB, OP_RRB, OP_RA, OP_RRA, OP_END},
	.evaluator = evaluator,
	.checker = checker,
	.search_width = 4,
};

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

void	push_unsorted_elems_to_b(t_node *node)
{
	t_data			*top_a;
	int				len_unsorted;

	len_unsorted = ft_deque_size(node->stack_a) - evaluate_lic(node->stack_a);
	while (len_unsorted)
	{
		top_a = ft_deque_front(node->stack_a);
		if (top_a->is_sorted == false)
		{
			exec_operation(node, OP_PA);
			len_unsorted--;
		}
		print_node(node);
		exec_operation(node, OP_RA);
	}
}

void	push_sorted_elems_to_a(t_node *node)
{
	size_t	len;

	len = ft_deque_size(node->stack_b);
	while (len--)
	{
		execute_greedy_push_operation(node);
		print_node(node);
	}
}

void	solve_push_swap_problem(int *nums, size_t size)
{
	t_node	*node;

	node = init_first_node(nums, size);
	push_unsorted_elems_to_b(node);
	push_sorted_elems_to_a(node);
	rotate_elems_of_a(node);
	put_answer(node->operations);
	delete_node(node);
}
