/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:54:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/07 15:25:08 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dp_construct_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
{
	int		*idx;
	int		lis;
	t_data	*itr;
	int		i;

	ft_vector_clear(dp_tab->res);
	idx = (int *)dp_tab->idx->data;
	lis = ft_vector_size(dp_tab->val) - 1;
	itr = deque_circular_prev(stack, start);
	i = ft_deque_size(stack) - 1;
	while (i >= 0)
	{
		if (idx[i] == lis)
		{
			ft_vector_push_back(dp_tab->res, &itr);
			lis--;
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

size_t	dp_calculate_lic(t_deque *stack, t_data *start, t_tab *dp_tab)
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
	return (ft_vector_size(dp_tab->val));
}

size_t	dp_calculate_lics(t_deque *stack, t_tab *dp_tab)
{
	size_t	lic_max;
	size_t	lic;
	t_data	*itr;
	size_t	len;

	lic_max = 0;
	len = ft_deque_size(stack);
	itr = ft_deque_front(stack);
	while (len--)
	{
		clear_dp_table(dp_tab);
		lic = dp_calculate_lic(stack, itr, dp_tab);
		if (lic_max < lic)
		{
			lic_max = lic;
			dp_construct_lic(stack, itr, dp_tab);
		}
		itr = ft_deque_next(stack, itr, 1);
	}
	return (lic_max);
}

/*
size_t cound_unsorted(t_deque *stack)
{
	t_data* itr;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t 	ans;

	ans = 0;
	itr = ft_deque_front(stack);
	len = ft_deque_size(stack);
	while(len--)
	{
		if(itr->is_sorted == false)
		{
			ans += i - j;
			j++;
		}
		i++;
		itr = ft_deque_next(stack, itr, 1);
	}
	return(ans);
}
*/

size_t	evaluate_lics(t_deque *stack, size_t lics_old)
{
	t_tab	dp_tab;
	size_t	lics_new;

	init_dp_table(&dp_tab, stack->len);
	lics_new = dp_calculate_lics(stack, &dp_tab);
	if (lics_old < lics_new)
	{
		clear_lics_tags(stack);
		put_on_lics_tags(dp_tab.res);
	}
	delete_dp_table(&dp_tab);
	return (lics_new);
}
