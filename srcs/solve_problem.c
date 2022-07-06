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
	.evaluator = evaluator_forth,
	.checker = checker_forth,
	.search_width = 4
};

const t_solver	g_dataset_back = {
	.evaluator = evaluator_back,
	.checker = checker_back,
	.search_width = 4
};

static void	update_next_target(t_node *node)
{
	size_t	expected;

	expected = ft_sqrt(node->size - node->lics_a);
	node->target = node->lics_a + expected;
}

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

void	solve_push_swap(int *nums, size_t size)
{
	t_node	*node;

	node = init_first_node(nums, size);
	node = search_opt_operations(node, &g_dataset_forth);
	while (node->size != node->lics_a)
	{
		node = search_opt_operations(node, &g_dataset_back);
		update_next_target(node);
	}
	opt_rotate_operations(node);
	put_answer(node->ops);
	delete_node(node);
}
