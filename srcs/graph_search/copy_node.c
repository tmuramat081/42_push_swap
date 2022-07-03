/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:40:45 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:40:45 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static	t_deque	*deque_copy(t_deque *src)
{
	t_deque	*dst;
	size_t	len;
	t_data	*itr;

	dst = ft_deque_init(src->data_size, src->cap);
	len = ft_deque_size(src);
	itr = ft_deque_front(src);
	while (len--)
	{
		ft_deque_push_back(dst, itr);
		itr = ft_deque_next(src, itr, 1);
	}
	return (dst);
}

static	t_vector	*vector_copy(t_vector *src)
{
	t_vector	*dst;
	size_t		len;
	t_data		*itr;

	dst = ft_vector_init(src->data_size, src->cap);
	len = ft_vector_size(src);
	itr = ft_vector_front(src);
	while (len--)
	{
		ft_vector_push_back(dst, itr);
		itr = ft_vector_next(src, itr, 1);
	}
	return (dst);
}

t_node	*copy_node(const t_node *src)
{
	t_node	*dst;

	dst = malloc(sizeof(t_node));
	dst->stack_a = deque_copy(src->stack_a);
	dst->stack_b = deque_copy(src->stack_b);
	dst->lics_a = src->lics_a;
	dst->size = src->size;
	dst->cost = src->cost;
	dst->target = src->target;
	dst->ops = vector_copy(src->ops);
	return (dst);
}
