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

#define WEIGHTING 10.0

size_t	evaluator_forth(t_node *node)
{
	size_t	cost_g;
	size_t	cost_h;

	node->lics_a = evaluate_lics(node->stack_a, node->lics_a);
	cost_h = node->size - node->lics_a;
	cost_g = ft_vector_size(node->ops);
	return (cost_g + (double)cost_h * WEIGHTING);
}

size_t	evaluator_back(t_node *node)
{
	size_t	cost_g;
	size_t	cost_h;

	node->lics_a = evaluate_lics(node->stack_a, node->lics_a);
	cost_h = node->size - node->lics_a;
	cost_g = ft_vector_size(node->ops);
	return (cost_g + (double)cost_h * WEIGHTING);
}
