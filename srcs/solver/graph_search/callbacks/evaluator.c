/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:11:47 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/25 11:11:47 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** heuristic cost; f = g + h */
size_t	evaluator(t_node *node)
{
	size_t	cost_g;
	size_t	cost_h;

	node->lic_a = calculate_lic_length(node->stack_a);
	cost_h = node->size - node->lic_a;
	cost_g = ft_vector_size(node->operations);
	return (cost_g + (double)cost_h * 1.0);
}
