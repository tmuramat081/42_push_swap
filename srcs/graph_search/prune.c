/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prune.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:37:44 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:37:44 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static bool	is_empty_operation(t_node *node, t_operation next)
{
	if (ft_deque_is_empty(node->stack_a) == true)
	{
		if (next == OP_SA || next == OP_PA || next == OP_RA || next == OP_RRA
			|| next == OP_SS || next == OP_RR || next == OP_RRR)
			return (true);
	}
	else if (ft_deque_is_empty(node->stack_b) == true)
	{
		if (next == OP_SB || next == OP_PB || next == OP_RB || next == OP_RRB
			|| next == OP_SS || next == OP_RR || next == OP_RRR)
			return (true);
	}
	else if (ft_deque_size(node->stack_a) == 1)
	{
		if (next == OP_SA || next == OP_RA || next == OP_RRA
			|| next == OP_SS || next == OP_RR || next == OP_RRR)
			return (true);
	}
	else if (ft_deque_size(node->stack_b) == 1)
	{
		if (next == OP_SB || next == OP_RB || next == OP_RRB
			|| next == OP_SS || next == OP_RR || next == OP_RRR)
			return (true);
	}
	return (false);
}

static bool	is_reverse_operation(t_node *node, t_operation next)
{
	t_operation	prev;

	prev = (t_operation)ft_vector_back(node->ops);
	if (!prev)
		return (false);
	if ((prev == OP_SA && next == OP_SA)
		|| (prev == OP_SB && next == OP_SB)
		|| (prev == OP_SS && next == OP_SS)
		|| (prev == OP_PA && next == OP_PB)
		|| (prev == OP_PB && next == OP_PA)
		|| (prev == OP_RA && next == OP_RRA)
		|| (prev == OP_RRA && next == OP_RA)
		|| (prev == OP_RB && next == OP_RRB)
		|| (prev == OP_RRB && next == OP_RB)
		|| (prev == OP_RR && next == OP_RRR)
		|| (prev == OP_RRR && prev == OP_RR))
		return (true);
	return (false);
}

static bool	is_locked_operation(t_node *node, t_operation next)
{
	t_data	*top_a;
	t_data	*bottom_a;
	t_data	*top_b;

	top_a = ft_deque_front(node->stack_a);
	bottom_a = ft_deque_back(node->stack_a);
	top_b = ft_deque_front(node->stack_b);
	if (next == OP_PA && top_a->is_sorted == true)
		return (true);
//	if (next == OP_PB
//		&& ((top_a->value != 0 && bottom_a->value != 0
//		&& (bottom_a->value > top_b->value || top_b->value > top_a->value))
//			|| (top_a->value == 0 && bottom_a->value > top_b->value)
//			|| (bottom_a->value == 0 && top_b->value > top_a->value)))
//		return (true);
	return (false);
}

bool	is_valid_operation(t_node *node, t_operation op)
{
	if (is_reverse_operation(node, op) == true)
		return (false);
	else if (is_empty_operation(node, op) == true)
		return (false);
	else if (is_locked_operation(node, op) == true)
		return (false);
	return (true);
}
