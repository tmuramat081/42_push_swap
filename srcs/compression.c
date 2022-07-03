/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:11:18 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 22:11:18 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_ascending(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a < *(int *)b)
		return (-1);
	return (0);
}

int	*coord_compression(int *arr_src, size_t n)
{
	int *arr_cpy;
	int *arr_dst;
	size_t	i;

	arr_dst = (int *)xmalloc(sizeof(int) * n);
	ft_qsort(arr_cpy, n, sizeof(int), cmp_ascending);
	i = 0;
	while (i < n)
	{
		arr_dst[i] = ft_lower_bound(arr_cpy, n, arr_src[i]);
		i++;
	}
	free(arr_src);
	free(arr_cpy);
	return (arr_dst);
}
