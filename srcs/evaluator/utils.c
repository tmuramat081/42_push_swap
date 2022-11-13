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

void	clear_lic_tags(t_deque *stack)
{
	t_data	*itr;
	size_t	len;

	itr = ft_deque_front(stack);
	len = ft_deque_size(stack);
	while (len--)
	{
		itr->is_sorted = false;
		itr = ft_deque_next(stack, itr, 1);
	}
}
