/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:46:09 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:46:09 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	checker_forth(t_node *node)
{
	if(ft_deque_size(node->stack_a) == node->lics_a)
		return (true);
	return (false);
}

bool	checker_back(t_node *node)
{
	if (node->lics_a >= node->target)
		return (true);
	return (false);
}
