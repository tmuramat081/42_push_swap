/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:54:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/12 11:58:53 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_lic_tags(t_deque *stack)
{
	t_data	*itr;
	size_t	len;

	itr = ft_deque_front(stack);
	len = ft_deque_size(stack);
	while (len--)
	{
		itr->is_sorted = false;
		itr = ft_deque_next(stack, itr, 1);
	}
}

static void	dp_construct_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
{
	int		*idx;
	int		lis;
	t_data	*itr;
	int		i;

	idx = (int *)dp_tab->idx->data;
	lis = ft_vector_size(dp_tab->val) - 1;
	itr = deque_circular_prev(stack, start);
	i = ft_deque_size(stack) - 1;
	while (i >= 0)
	{
		if (idx[i] == lis)
		{
			itr->is_sorted = true;
			lis--;
		}
		itr = deque_circular_prev(stack, itr);
		i--;
	}
}

static void	dp_update_table(t_tab *dp_tab, int target, size_t i)
{
	int			*itr;
	t_vector	*val;
	t_vector	*idx;

	val = dp_tab->val;
	idx = dp_tab->idx;
	itr = ft_lower_bound(val->data, dp_tab->val->len, target);
	if (val->end == itr)
		ft_vector_push_back(val, &target);
	else
		*itr = target;
	*((int *)idx->data + i) = itr - (int *)val->data;
}

static void	dp_calculate_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
{
	t_data	*itr;
	size_t	len;
	size_t	i;

	i = 0;
	itr = start;
	len = ft_deque_size(stack);
	while (len--)
	{
		dp_update_table(dp_tab, itr->value, i);
		itr = deque_circular_next(stack, itr);
		i++;
	}
}

size_t	evaluate_lic(t_deque *stack)
{
	t_tab	dp_table;
	t_data	*itr;
	size_t	lic_length;

	clear_lic_tags(stack);
	init_dp_table(&dp_table, stack->len);
	itr = min_element(stack);
	dp_calculate_lic(stack, itr, &dp_table);
	dp_construct_lic(stack, itr, &dp_table);
	lic_length = ft_vector_size(dp_table.val);
	delete_dp_table(&dp_table);
	return (lic_length);
}
