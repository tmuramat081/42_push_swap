/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:19:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 22:19:34 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*init_first_node(int *nums, size_t size)
{
	t_node	*node;

	node = ft_xmalloc(sizeof(t_node));
	node->stack_a = ft_deque_init(sizeof(t_data), size);
	push_input_numbers(node->stack_a, nums, size);
	node->stack_b = ft_deque_init(sizeof(t_data), size);
	node->ops = ft_vector_init(sizeof(t_operation), OPS_SIZE);
	node->size = size;
	node->target = ft_sqrt(node->size);
	free(nums);
	return (node);
}
