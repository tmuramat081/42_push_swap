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
	return (
		get_circular_index(
			(t_data *)get_max_element(node->stack_a) - top_a, len_a)
	);
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

t_pair	evaluate_min_swap_distance(t_node *node, t_pair *dist_table)
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

void	execute_opt_operations(t_node *node, t_pair min_dist)
{
	size_t		exec_times;
	t_operation	op;

	if (min_dist.a > 0 && min_dist.b > 0)
	{
		exec_times = ft_min(min_dist.a, min_dist.b);
		exec_repeated_operation(node, OP_RR, exec_times);
		min_dist.a -= exec_times;
		min_dist.b -= exec_times;
	}
	else if (min_dist.b < 0 && min_dist.b < 0)
	{
		exec_times = ft_abs(ft_max(min_dist.a, min_dist.b));
		exec_repeated_operation(node, OP_RRR, exec_times);
		min_dist.a += exec_times;
		min_dist.b += exec_times;
	}
	if (min_dist.a > 0)
		exec_repeated_operation(node, OP_RA, exec_times);
	else if (min_dist.a < 0)
		exec_repeated_operation(node, OP_RRA, exec_times);
	if (min_dist.b > 0)
		exec_repeated_operation(node, OP_RB, exec_times);
	else if (min_dist.b < 0)
		exec_repeated_operation(node, OP_RRB, exec_times);
	exec_operation(node, OP_PB);
}

void	execute_greedy_push_operation(t_node *node)
{
	size_t	len_b;
	t_pair	*dist_table;
	t_pair	min_dist;

	len_b = ft_deque_size(node->stack_b);
	dist_table = (t_pair *)ft_xmalloc(sizeof(t_pair) * len_b);
	min_dist = evaluate_min_swap_distance(node, dist_table);
	free(dist_table);
	execute_opt_operations(node, min_dist);
}
