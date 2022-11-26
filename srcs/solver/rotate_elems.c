/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:00:08 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 12:03:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_elems(t_deque *stack, t_node *node)
{
	t_data		*top;
	t_operation	op;

	top = ft_deque_front(stack);
	if (node->size / 2 >= (size_t)top->value)
		op = OP_RRA;
	else
		op = OP_RA;
	while (top->value != 0)
	{
		exec_operation(node, op);
		top = ft_deque_front(node->stack_a);
	}
}
