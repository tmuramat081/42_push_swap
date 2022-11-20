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

int	get_circular_index(size_t i, size_t len)
{
	if (i == 0)
		return (0);
	if (i >= len / 2)
		return ((int)i - (int)len);
	return ((int)i);
}

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

size_t	max_element_index(t_deque *stack)
{
	size_t	len;
	t_data	*itr;
	int		max_value;
	size_t	max_i;
	size_t	i;

	max_value = INT_MIN;
	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	i = 0;
	while (i < len)
	{
		if (max_value < itr->value)
		{
			max_value = itr->value;
			max_i = i;
		}
		i++;
		itr = ft_deque_next(stack, itr, 1);
	}
	return (max_i);
}

void	*max_element(t_deque *stack)
{
	size_t	len;
	t_data	*itr;
	int		max_value;
	t_data	*max_elem;

	max_value = INT_MIN;
	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	while (len--)
	{
		if (max_value < itr->value)
		{
			max_value = itr->value;
			max_elem = itr;
		}
		itr = ft_deque_next(stack, itr, 1);
	}
	return (max_elem);
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
