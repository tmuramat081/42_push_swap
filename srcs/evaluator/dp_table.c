/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:36:15 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 22:36:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_on_lics_tags(t_vector *res)
{
	size_t	len;
	t_data	**itr;

	len = ft_vector_size(res);
	itr = ft_vector_front(res);
	while (len--)
	{
		(*itr)->is_sorted = true;
		itr = ft_vector_next(res, itr, 1);
	}
}

void	init_dp_table(t_tab *dp_tab, size_t size)
{
	dp_tab->val = ft_vector_init(sizeof(int), size);
	dp_tab->idx = ft_vector_init(sizeof(int), size);
	dp_tab->res = ft_vector_init(sizeof(t_data *), size);
}

void	clear_dp_table(t_tab *dp_tab)
{
	ft_vector_clear(dp_tab->val);
	ft_vector_clear(dp_tab->idx);
}

void	delete_dp_table(t_tab *dp_tab)
{
	ft_vector_delete(&dp_tab->val);
	ft_vector_delete(&dp_tab->idx);
	ft_vector_delete(&dp_tab->res);
}
