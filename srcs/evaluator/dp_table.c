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

void	init_dp_table(t_tab *dp_tab, size_t size)
{
	dp_tab->val = ft_vector_init(sizeof(int), size);
	dp_tab->idx = ft_vector_init(sizeof(int), size);
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
}
