/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:05:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 14:06:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_circular_index(size_t i, size_t len)
{
	if (i == 0)
		return (0);
	if (i >= len / 2)
		return ((int)i - (int)len);
	return ((int)i);
}
