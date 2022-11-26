/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:00:48 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/01 13:00:48 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*min_element(t_deque *stack)
{
	size_t	len;
	t_data	*itr;
	int		min_value;
	t_data	*min_elem;

	min_value = INT_MAX;
	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	while (len--)
	{
		if (min_value > itr->value)
		{
			min_value = itr->value;
			min_elem = itr;
		}
		itr = ft_deque_next(stack, itr, 1);
	}
	return (min_elem);
}

void	*deque_circular_prev(t_deque *stack, void *itr)
{
	if (itr == stack->begin)
		itr = stack->end;
	itr = ft_deque_prev(stack, itr, 1);
	return (itr);
}

void	*deque_circular_next(t_deque *stack, void *itr)
{
	itr = ft_deque_next(stack, itr, 1);
	if (itr == stack->end)
		itr = stack->begin;
	return (itr);
}
