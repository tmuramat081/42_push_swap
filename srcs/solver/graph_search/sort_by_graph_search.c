/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_graph_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:44:41 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 11:57:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_graph_search(t_node **node)
{
	t_node	*new_node;

	new_node = search_opt_operations(*node, &g_dataset);
	*node = new_node;
}
