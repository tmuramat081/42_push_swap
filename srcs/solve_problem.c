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

#define OPS_SIZE 64

static void	update_next_target(t_node *node)
{
	size_t	expected;

	expected = ft_sqrt(node->size - node->lics_a) * 2;
	if (expected <= 5)
		node->target = node->size;
	else
		node->target = node->lics_a + expected;
}

static void	push_input_numbers(t_deque *stack, int *nums, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_deque_push_back(stack, &(t_data){nums[i], false});
		i++;
	}
}

static t_node	*init_first_node(int *nums, size_t size)
{
	t_node	*node;

	node = ft_xmalloc(sizeof(t_node));
	node->stack_a = ft_deque_init(sizeof(t_data), size);
	push_input_numbers(node->stack_a, nums, size);
	node->stack_b = ft_deque_init(sizeof(t_data), size);
	node->ops = ft_vector_init(sizeof(t_operation), OPS_SIZE);
	node->size = size;
	node->target = ft_sqrt(node->size) * 2;
	free(nums);
	return (node);
}

void	opt_rotation(t_node *node)
{
	t_data		*top_a;
	t_operation	op;

	top_a = ft_deque_front(node->stack_a);
	if (node->size / 2 > (size_t)top_a->value)
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
	while (node->size != node->lics_a)
	{
		node = search_opt_operations(node, &(t_solver){evaluator_2, checker_2, 3});
		update_next_target(node);
	}
	opt_rotation(node);
	put_answer(node->ops);
	delete_node(node);
}
