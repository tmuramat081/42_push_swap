/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:01:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/01 15:22:29 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

/*
**	Take the first valueents at the top of one stack, and
**	put it at the top of another stack.
**	[A] [B] -> [A] [B]
**	 1	 -		2	1
**	 2	 -		3
**	 3	 -
*/

static void	stack_push(t_deque *stack1, t_deque *stack2)
{
	t_data	tmp;

	if (ft_deque_is_empty(stack1) == true)
		return ;
	ft_deque_pop_front(stack1, &tmp);
	ft_deque_push_front(stack2, &tmp);
}

void	op_pa(t_node *node)
{
	stack_push(node->stack_a, node->stack_b);
	ft_vector_push_back(node->ops, &(t_operation){OP_PA});
}

void	op_pb(t_node *node)
{
	stack_push(node->stack_b, node->stack_a);
	ft_vector_push_back(node->ops, &(t_operation){OP_PB});
}
