/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_greedy_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:32:26 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 14:30:19 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_greedy_operations(t_node *node, t_pair min_dist)
{
	size_t		exec_times;

	if (min_dist.a > 0 && min_dist.b > 0)
	{
		exec_times = ft_min(min_dist.a, min_dist.b);
		exec_repeated_operation(node, OP_RR, exec_times);
		min_dist.a -= exec_times;
		min_dist.b -= exec_times;
	}
	else if (min_dist.a < 0 && min_dist.b < 0)
	{
		exec_times = ft_abs(ft_max(min_dist.a, min_dist.b));
		exec_repeated_operation(node, OP_RRR, exec_times);
		min_dist.a += exec_times;
		min_dist.b += exec_times;
	}
	if (min_dist.a > 0)
		exec_repeated_operation(node, OP_RA, min_dist.a);
	else if (min_dist.a < 0)
		exec_repeated_operation(node, OP_RRA, ft_abs(min_dist.a));
	if (min_dist.b > 0)
		exec_repeated_operation(node, OP_RB, min_dist.b);
	else if (min_dist.b < 0)
		exec_repeated_operation(node, OP_RRB, ft_abs(min_dist.b));
	exec_operation(node, OP_PA);
}
