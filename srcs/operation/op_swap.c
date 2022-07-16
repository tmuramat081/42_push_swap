/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:13:42 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/16 02:40:14 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "push_swap.h"
#include "libft.h"

/*
**	Swap the first 2 valueents at the top of stack.
**	[A]	-> [A]
**	 1		2
**	 2		1
**	 3		3
*/

static void	stack_swap(t_deque *stack)
{
	t_data	*it1;
	t_data	*it2;

	if (stack->len <= 1)
		return ;
	it1 = ft_deque_front(stack);
	it2 = ft_deque_next(stack, it1, 1);
	ft_memswap(it1, it2, sizeof(int));
}

void	op_sa(t_node *node)
{
	stack_swap(node->stack_a);
	if (!ft_vector_push_back(node->ops, &(t_operation){OP_SA}))
		exit(EXIT_FAILURE);
}

void	op_sb(t_node *node)
{
	stack_swap(node->stack_b);
	if (!ft_vector_push_back(node->ops, &(t_operation){OP_SB}))
		exit(EXIT_FAILURE);
}

void	op_ss(t_node *node)
{
	stack_swap(node->stack_a);
	stack_swap(node->stack_b);
	if (!ft_vector_push_back(node->ops, &(t_operation){OP_SS}))
		exit(EXIT_FAILURE);
}
