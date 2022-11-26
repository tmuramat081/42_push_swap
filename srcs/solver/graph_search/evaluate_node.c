/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 03:01:37 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/07 08:54:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	evaluate_first_node(t_node *node, t_pqueue *open, t_hashset *closed,
			t_eval evaluator)
{
	node->cost = evaluator(node);
	ft_priority_queue_push(open, node);
	ft_hashset_insert(closed, node);
}

void	evaluate_next_node(t_node *tmp_node, t_pqueue *tmp_open,
			t_hashset *closed, t_eval evaluator)
{
	if (ft_hashset_insert(closed, tmp_node) == HASHSET_FAILURE)
	{
		delete_node(tmp_node);
		return ;
	}
	tmp_node->cost = evaluator(tmp_node);
	ft_priority_queue_push(tmp_open, tmp_node);
}
