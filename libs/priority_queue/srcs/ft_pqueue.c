/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:42:15 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/20 10:42:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pqueue.h"
#include "ft_heap.h"

t_pqueue	*ft_priority_queue_init(size_t cap,
	int (*cmp)(const void *, const void *))
{
	t_pqueue	*new;

	new = malloc(sizeof(t_pqueue));
	if (!new)
		return (NULL);
	new->heap = ft_heap_init(cap, cmp);
	return (new);
}

void	ft_priority_queue_delete(t_pqueue **queue, void(*del)(void *))
{
	ft_heap_delete(&(*queue)->heap, del);
	free(*queue);
	*queue = NULL;
}

int	ft_priority_queue_push(t_pqueue *queue, void *data)
{
	if (ft_heap_push(queue->heap, data) == HEAP_FAILURE)
		return (PQUEUE_FAILURE);
	return (PQUEUE_SUCCESS);
}

void	*ft_priority_queue_pop(t_pqueue *queue)
{
	void	*data;

	if (ft_heap_pop(queue->heap, &data) == HEAP_FAILURE)
		return (PQUEUE_FAILURE);
	return (data);
}

bool	ft_priority_queue_is_empty(t_pqueue *queue)
{
	if (ft_heap_is_empty(queue->heap) == true)
		return (true);
	return (false);
}

size_t	ft_priority_queue_size(t_pqueue *queue)
{
	return (ft_heap_size(queue->heap));
}
