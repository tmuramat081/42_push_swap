/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:01:44 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/08 23:21:44 by tmuramat         ###   ########.fr       */
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
	if (!ft_deque_pop_front(stack, &tmp))
		exit(EXIT_FAILURE);
	if (!ft_deque_push_back(stack, &tmp))
		exit(EXIT_FAILURE);
}

void	op_ra(t_node *node)
{
	stack_rotate(node->stack_a);
	if (!ft_vector_push_back(node->operations, &(t_operation){OP_RA}))
		exit(EXIT_FAILURE);
}

void	op_rb(t_node *node)
{
	stack_rotate(node->stack_b);
	if (!ft_vector_push_back(node->operations, &(t_operation){OP_RB}))
		exit(EXIT_FAILURE);
}

void	op_rr(t_node *node)
{
	stack_rotate(node->stack_a);
	stack_rotate(node->stack_b);
	if (!ft_vector_push_back(node->operations, &(t_operation){OP_RR}))
		exit(EXIT_FAILURE);
}
