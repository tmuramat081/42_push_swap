#include "push_swap.h"

bool	checker_1(t_node *node)
{
	if (node->lics_a == ft_deque_size(node->stack_a))
		return (true);
	return (false);
}

bool	checker_2(t_node *node)
{
	if (node->lics_a == node->size)
		return (true);
	return (false);
}

bool	checker_3(t_node *node)
{
	t_data	*itr;
	t_data	*next_itr;
	size_t	 len;
	
	if (node->size != ft_deque_size(node->stack_a))
		return (false);
	len = ft_deque_size(node->stack_a);
	itr = ft_deque_front(node->stack_a);
	while (--len)
	{
		next_itr = ft_deque_next(node->stack_a, itr, 1);
		if (itr->value > next_itr->value)
			return (false);
		itr = next_itr;
	}
	return (true);
}