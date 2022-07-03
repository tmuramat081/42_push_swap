/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalatoruate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:11:47 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/25 11:11:47 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bfs.h"

size_t	evaluator_1(t_node *node)
{
	size_t	cost_g;
	size_t	cost_h;
	
	node->lics_a = dp_calculate_lics(node->stack_a);
	cost_h = ft_deque_size(node->stack_a) - node->lics_a;
	cost_g = ft_vector_size(node->ops);
	return (cost_g + (double)cost_h * 5.0);
}

size_t	evaluator_2(t_node *node)
{
	size_t	cost_g;
	size_t	cost_h;
	
	node->lics_a = dp_calculate_lics(node->stack_a);
	cost_h = node->size - node->lics_a;
	cost_g = ft_vector_size(node->ops);
	return (cost_g + (double)cost_h * 5.0);
}

size_t evaluator_3(t_node *node)
{
	size_t	len;
	int		*itr;
	size_t	diff;
	size_t	i;

	diff = 0;
	len = ft_deque_size(node->stack_a);
	if (len != node->size)
		return (SIZE_MAX);
	itr = ft_deque_front(node->stack_a);
	while (len--)
	{
		diff += ft_abs(*itr - i);
		itr = ft_deque_next(node->stack_a, itr, 1);
		i++;
	}
	return(diff);
}
