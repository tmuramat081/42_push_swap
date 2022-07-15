#include "push_swap.h"

static int	get_circular_index(size_t i, size_t len)
{
	if (i >= len / 2)
		return ((int)i - (int)len);
	return ((int)i);
}

static bool	can_insert(t_deque *stack, t_data *itr, int target)
{
	t_data	*itr_next;

	itr_next = deque_circular_next(stack, itr);
	if (itr->value < target && (target < itr_next->value || itr_next->value == 0))
		return (true);
	return (false);
}

static int	calculate_insert_swaps(t_node *node, int target)
{
	t_data	*itr;
	size_t	len;
	size_t	i;

	itr = ft_deque_back(node->stack_a);
	len = ft_deque_size(node->stack_a);
	i = 0;
	while (i < len)
	{
		if (can_insert(node->stack_a, itr, target) == true)
			break ;
		itr = deque_circular_next(node->stack_a, itr);
		i++;
	}
	return (get_circular_index(i, len));
}

size_t evaluate_min_swaps(t_node *node)
{
	t_data	*itr;
	size_t	i;
	int		swaps_a;
	int		swaps_b;
	size_t	len;
	size_t	swaps;

	swaps = 0;
	len = ft_deque_size(node->stack_b);
	itr = ft_deque_front(node->stack_b);
	i = 0;
	while (i < len)
	{
		swaps_a = calculate_insert_swaps(node, itr->value);
		swaps_b = get_circular_index(i, len);
		swaps += ft_max(ft_abs(swaps_a), ft_abs(swaps_b));
		itr = deque_circular_next(node->stack_b, itr);
		i++;
	}
	return (swaps);
}
