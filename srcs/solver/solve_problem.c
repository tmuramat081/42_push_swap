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
#define THRESHOLD_SIZE 10

void	solve_push_swap_problem(int *nums, size_t size)
{
	t_node	*node;

	node = init_first_node(nums, size);
	if (size <= THRESHOLD_SIZE)
		sort_by_graph_search(&node);
	else
		sort_by_insertion(node);
	rotate_elems(node->stack_a, node);
	put_answer(node->operations);
	delete_node(node);
}
