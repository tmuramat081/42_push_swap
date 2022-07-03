/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 09:33:41 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/05 09:33:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

/*ws
**	Shift down all elements of stack a by 1.
**	The last valueent becomes the first one.
**	[A] -> [A]
**	 1		3
**	 2		1
**	 3		2
*/

static void	stack_rev_rotate(t_deque *stack)
{
	t_data	tmp;

	if (ft_deque_is_empty(stack) == true)
		return ;
	ft_deque_pop_back(stack, &tmp);
	ft_deque_push_front(stack, &tmp);
}

void	op_rra(t_node *node)
{
	stack_rev_rotate(node->stack_a);
	ft_vector_push_back(node->ops, &(t_operation){OP_RRA});
}

void	op_rrb(t_node *node)
{
	stack_rev_rotate(node->stack_b);
	ft_vector_push_back(node->ops, &(t_operation){OP_RRB});
}

void	op_rrr(t_node *node)
{
	stack_rev_rotate(node->stack_a);
	stack_rev_rotate(node->stack_b);
	ft_vector_push_back(node->ops, &(t_operation){OP_RRR});
}
