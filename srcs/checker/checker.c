/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:46:09 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:46:09 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	checker_1(t_node *node)
{
	if (node->lics_a == ft_deque_size(node->stack_a))
		return (true);
	return (false);
}

bool	checker_2(t_node *node)
{
	if (node->lics_a >= node->target)
		return (true);
	return (false);
}

bool	checker_3(t_node *node)
{
	t_data	*itr;
	int		expected_val;
	size_t	len;

	if (node->size != ft_deque_size(node->stack_a))
		return (false);
	len = ft_deque_size(node->stack_a);
	itr = ft_deque_front(node->stack_a);
	expected_val = 0;
	while (--len)
	{
		if (itr->value != expected_val)
			return (false);
		expected_val += 1;
		itr = ft_deque_next(node->stack_a, itr, 1);
	}
	return (true);
}
