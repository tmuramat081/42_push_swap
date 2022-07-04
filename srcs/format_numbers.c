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

bool	array_is_unique(int *arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n)
	{
		if (arr[i] == arr[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	*coord_compression(int *arr_src, int *arr_cpy, size_t n)
{
	int		*arr_dst;
	size_t	i;

	arr_dst = (int *)ft_xmalloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		arr_dst[i] = (int *)ft_lower_bound(arr_cpy, n, arr_src[i]) - arr_cpy;
		i++;
	}
	return (arr_dst);
}

int	*format_numbers(int *arr_src, size_t n)
{
	int	*arr_cpy;
	int	*arr_dst;

	arr_cpy = ft_arraydup(arr_src, n);
	ft_qsort(arr_cpy, n, sizeof(int), cmp_ascending);
	if (array_is_unique(arr_cpy, n) == false)
		hundle_error(NULL);
	arr_dst = coord_compression(arr_src, arr_cpy, n);
	free(arr_src);
	free(arr_cpy);
	return (arr_dst);
}
