/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:01:44 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/01 15:22:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

/*
**	Shift up all elemnts of stack a by 1.
**	The first valueent becomes the last one.
**	[A] -> [A]
**	 1		2
**	 2		3
**	 3		1
*/

static void	stack_rotate(t_deque *stack)
{
	t_data	tmp;

	if (ft_deque_is_empty(stack) == true)
		return ;
	ft_deque_pop_front(stack, &tmp);
	ft_deque_push_back(stack, &tmp);
}

void	op_ra(t_node *node)
{
	stack_rotate(node->stack_a);
	ft_vector_push_back(node->ops, &(t_operation){OP_RA});
}

void	op_rb(t_node *node)
{
	stack_rotate(node->stack_b);
	ft_vector_push_back(node->ops, &(t_operation){OP_RB});
}

void	op_rr(t_node *node)
{
	stack_rotate(node->stack_a);
	stack_rotate(node->stack_b);
	ft_vector_push_back(node->ops, &(t_operation){OP_RR});
}
