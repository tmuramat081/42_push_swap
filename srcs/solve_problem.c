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

const t_solver	g_dataset_forth = {
	.operations = {OP_PA, OP_SA, OP_RA, OP_RRA, OP_END},
	.evaluator = evaluator_forth,
	.checker = checker_forth,
	.search_width = 4
};

const t_solver	g_dataset_back = {
	.operations = {OP_PB, OP_SB, OP_RB, OP_RRB, OP_RA, OP_RRA, OP_END},
	.evaluator = evaluator_back,
	.checker = checker_back,
	.search_width = 4
};

void	opt_rotate_operations(t_node *node)
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
	if (node->lics_a == node->size)
		return (true);
	return (false);
}

void	update_search_condition(t_node *node)
{
	node->target += ft_sqrt(node->size - node->target);
	if (node->target >= node->size)
		node->target = node->size;
}

void	solve_push_swap(int *nums, size_t size)
{
	t_node	*node;

	node = init_first_node(nums, size);
	while (is_sorted(node) == false)
	{
		node = search_opt_operations(node, &g_dataset_forth);
		node = search_opt_operations(node, &g_dataset_back);
		update_search_condition(node);
	}
	opt_rotate_operations(node);
	put_answer(node->ops);
	delete_node(node);
}
