/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:54:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/10 22:23:38 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	*search_min_element(t_deque *stack)
{
	size_t	len;
	t_data	*itr;

	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	while (len--)
	{
		if (itr->value == 0)
			break ;
		itr = ft_deque_next(stack, itr, 1);
	}
	return (itr);
}

size_t	evaluate_lics(t_deque *stack)
{
	t_tab	dp_tab;
	t_data	*itr;
	size_t	lics;
	
	clear_lics_tags(stack);
	init_dp_table(&dp_tab, stack->len);
	itr = search_min_element(stack);
	dp_calculate_lic(stack, itr, &dp_tab);
	dp_construct_lic(stack, itr, &dp_tab);
	lics = ft_vector_size(dp_tab.val);
	delete_dp_table(&dp_tab);
	return (lics);
}
