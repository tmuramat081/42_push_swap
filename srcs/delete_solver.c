/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:46:23 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:46:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	delete_node(void *ptr)
{
	t_node	*node;

	node = (t_node *)ptr;
	ft_deque_delete(&node->stack_a);
	ft_deque_delete(&node->stack_b);
	ft_vector_delete(&node->ops);
	free(node);
}

void	hundle_error(t_node *node)
{
	if (node)
		delete_node(node);
	ft_printf("ERROR:Invalid arguments.\n");
	exit(EXIT_FAILURE);
}
