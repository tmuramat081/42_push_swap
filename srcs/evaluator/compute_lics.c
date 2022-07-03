/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:54:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 19:34:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dp_construct_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
{
	t_data	*itr;
	int		lic;
	int		i;
	int		*idx;

	idx = (int *)dp_tab->idx->data;
	lic = dp_tab->val->len - 1;
	itr = deque_circular_prev(stack, start);
	i = ft_deque_size(stack) - 1;
	while (i >= 0)
	{
		if (idx[i] == lic)
		{
			itr->is_sorted = true;
			lic--;
		}
		itr = deque_circular_prev(stack, itr);
		i--;
	}
}

void	dp_update_table(t_tab *dp_tab, int target, size_t i)
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

void	dp_calculate_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
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

size_t	dp_calculate_lics(t_deque *stack)
{
	t_tab	dp_tab;
	size_t	lics;
	t_data	*itr;
	int		len;

	clear_lics_tags(stack);
	init_dp_table(&dp_tab, stack->len);
	lics = 0;
	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	while (len--)
	{
		clear_dp_table(&dp_tab);
		dp_calculate_lic(stack, itr, &dp_tab);
		if (lics < dp_tab.val->len)
		{
			lics = dp_tab.val->len;
			dp_construct_lic(stack, itr, &dp_tab);
		}
		itr = ft_deque_next(stack, itr, 1);
	}
	delete_dp_table(&dp_tab);
	return (lics);
}
