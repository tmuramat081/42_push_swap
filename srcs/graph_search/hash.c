/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_hasher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:15:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/24 12:15:16 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_hashset.h"

static size_t	convert_deque_to_hash(t_deque *deque)
{
	size_t	hash;
	size_t	len;
	t_data	*itr;

	if (ft_deque_is_empty(deque) == true)
		return (0);
	hash = 5381;
	len = ft_deque_size(deque);
	itr = ft_deque_front(deque);
	while (len--)
	{
		hash = ((hash << 5) + hash) + itr->value;
		itr = ft_deque_next(deque, itr, 1);
	}
	return (hash % (SIZE_MAX / 2));
}

size_t	hash_node(const void *ptr)
{
	t_node	*node;
	size_t	hash;

	node = (t_node *)ptr;
	hash = convert_deque_to_hash(node->stack_a);
	hash <<= 5;
	hash += convert_deque_to_hash(node->stack_b);
	return (hash);
}
