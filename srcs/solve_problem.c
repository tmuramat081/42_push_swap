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

#define OPS_SIZE 256

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

static t_node	*init_node(int *nums, size_t size)
{
	t_node	*node;

	node = ft_xmalloc(sizeof(t_node));
	node->stack_a = ft_deque_init(sizeof(t_data), size);
	node->stack_b = ft_deque_init(sizeof(t_data), size);
	node->ops = ft_vector_init(sizeof(t_operation), OPS_SIZE);
	push_input_numbers(node->stack_a, nums, size);
	node->size = size;
	node->target = size / 2;
	free(nums);
	return (node);
}

void	opt_rotation(t_node *node)
{
	while (checker_3(node) == false)
	{
		op_ra(node);
		print_node(node);
	}
}

void	solve_push_swap(int *nums, size_t size)
{
	t_node	*node;

	node = init_node(nums, size);
	while (true)
	{
		node = search_opt_operations(node, &(t_solver){evaluator_2, checker_2, 3});
		if (node->lics_a == node->size)
			break ;
		node->target = (node->size - node->target) / 2;
	}
//	node = search_opt_operations(node, &(t_solver){evaluator_2, checker_2, 3});
//	opt_rotation(node);
	put_answer(node->ops);
	delete_node(node);
}
