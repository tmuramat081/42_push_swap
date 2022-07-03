/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:08:55 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/24 14:08:55 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bfs.h"

int priority_comparator(const void *ptr1, const void *ptr2)
{
	t_node *node1;
	t_node *node2;

	node1 = (t_node *)ptr1;
	node2 = (t_node *)ptr2;
	if (node1->cost > node2->cost)
		return (1);
	else if (node1->cost < node2->cost)
		return (-1);
	if (ft_vector_size(node1->ops) > ft_vector_size(node2->ops))
		return (1);
	else if (ft_vector_size(node1->ops) < ft_vector_size(node2->ops))
		return (-1);
	return (0);
}
