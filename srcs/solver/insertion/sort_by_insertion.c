/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:38:47 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 13:48:28 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sorted_elems(t_deque *stack, t_node *node)
{
	t_pair	min_dist;

	while (!ft_deque_is_empty(stack))
	{
		min_dist = calculate_min_insert_distance(node);
		execute_greedy_operations(node, min_dist);
		print_node(node);
	}
}

void	push_unsorted_elems(t_deque *stack, t_node *node)
{
	t_data			*top;
	size_t			len_unsorted;

	len_unsorted = ft_deque_size(stack) - calculate_lic_length(stack);
	while (len_unsorted)
	{
		top = ft_deque_front(stack);
		if (top->is_sorted == false)
		{
			exec_operation(node, OP_PB);
			len_unsorted--;
		}
		exec_operation(node, OP_RA);
	}
}

void	sort_by_insertion(t_node *node)
{
	push_unsorted_elems(node->stack_a, node);
	push_sorted_elems(node->stack_b, node);
}
