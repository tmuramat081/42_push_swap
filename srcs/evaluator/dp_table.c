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

void	init_dp_table(t_tab *dp_table, size_t size)
{
	dp_table->val = ft_vector_init(sizeof(int), size);
	dp_table->idx = ft_vector_init(sizeof(int), size);
}

void	clear_dp_table(t_tab *dp_table)
{
	ft_vector_clear(dp_table->val);
	ft_vector_clear(dp_table->idx);
}

void	delete_dp_table(t_tab *dp_table)
{
	ft_vector_delete(&dp_table->val);
	ft_vector_delete(&dp_table->idx);
}
