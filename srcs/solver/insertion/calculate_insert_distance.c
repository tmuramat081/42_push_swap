/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_min_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:27:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/13 17:27:50 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_element_index(t_deque *stack)
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
		itr = ft_deque_next(stack, itr, 1);
		i++;
	}
	if (max_i == len)
		return (0);
	return (max_i);
}

static int	calculate_insert_swaps(t_node *node, int target)
{
	t_data	*top_a;
	t_data	*itr_a;
	t_data	*itr_next;
	size_t	len_a;
	size_t	i;

	top_a = ft_deque_front(node->stack_a);
	if (top_a->value > target
		&& target > ((t_data *)ft_deque_back(node->stack_a))->value)
		return (0);
	itr_a = top_a;
	len_a = ft_deque_size(node->stack_a);
	i = 1;
	while (i < len_a)
	{
		itr_next = ft_deque_next(node->stack_a, itr_a, 1);
		if (itr_a->value < target && target < itr_next->value)
			return (get_circular_index(i, len_a));
		itr_a = ft_deque_next(node->stack_a, itr_a, 1);
		i++;
	}
	return (get_circular_index(max_element_index(node->stack_a) + 1, len_a));
}

t_pair	get_min_distance(t_pair	*dist_table, size_t len)
{
	int		min_dist;
	t_pair	min_swap_dist;
	size_t	i;

	i = 0;
	min_dist = INT_MAX;
	while (len--)
	{
		if (min_dist > (ft_abs(dist_table[i].a) + ft_abs(dist_table[i].b)))
		{
			min_dist = (ft_abs(dist_table[i].a) + ft_abs(dist_table[i].b));
			min_swap_dist = dist_table[i];
		}
		i++;
	}
	return (min_swap_dist);
}

t_pair	evaluate_min_distances(t_node *node, t_pair *dist_table)
{
	size_t	len_b;
	t_data	*itr_b;
	size_t	i;

	len_b = ft_deque_size(node->stack_b);
	itr_b = ft_deque_front(node->stack_b);
	i = 0;
	while (i < len_b)
	{
		dist_table[i].a = calculate_insert_swaps(node, itr_b->value);
		dist_table[i].b = get_circular_index(i, len_b);
		itr_b = deque_circular_next(node->stack_b, itr_b);
		i++;
	}
	return (get_min_distance(dist_table, len_b));
}

t_pair	calculate_min_insert_distance(t_node *node)
{
	size_t	len_b;
	t_pair	*dist_table;
	t_pair	min_dist;

	len_b = ft_deque_size(node->stack_b);
	dist_table = (t_pair *)ft_xmalloc(sizeof(t_pair) * len_b);
	min_dist = evaluate_min_distances(node, dist_table);
	free(dist_table);
	return (min_dist);
}
