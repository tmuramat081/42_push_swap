/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:19:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/12 23:22:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

#define OPERATION_SIZE 64
#define ERR_MSG "invalid arguments.\n"

void	hundle_error(t_node *node)
{
	if (node)
		delete_node(node);
	ft_printf(ERR_MSG);
	exit(EXIT_FAILURE);
}

void	delete_node(void *ptr)
{
	t_node	*node;

	node = (t_node *)ptr;
	ft_deque_delete(&node->stack_a);
	ft_deque_delete(&node->stack_b);
	ft_vector_delete(&node->operations);
	free(node);
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

t_node	*init_first_node(int *nums, size_t size)
{
	t_node	*node;

	node = ft_xmalloc(sizeof(t_node));
	node->stack_a = ft_deque_init(sizeof(t_data), size);
	node->stack_b = ft_deque_init(sizeof(t_data), size);
	node->operations = ft_vector_init(sizeof(t_operation), OPERATION_SIZE);
	node->size = size;
	node->lic_a = 0;
	push_input_numbers(node->stack_a, nums, size);
	free(nums);
	return (node);
}
