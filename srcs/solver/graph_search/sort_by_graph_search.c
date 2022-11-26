/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_graph_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:44:41 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 14:18:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const t_solver	g_dataset = {
	.operations = {OP_PA, OP_PB, OP_SA, OP_SB, OP_SS, OP_RA,
	OP_RB, OP_RR, OP_RRA, OP_RRB, OP_RRR, OP_END},
	.evaluator = evaluator,
	.checker = checker,
	.search_width = 12,
};

void	sort_by_graph_search(t_node **node)
{
	t_node	*new_node;

	new_node = search_opt_operations(*node, &g_dataset);
	*node = new_node;
}
