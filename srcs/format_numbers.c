/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:56:13 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/04 18:56:13 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp_ascending(const void *a, const void *b)
{
	int	*ac;
	int	*bc;

	ac = (int *)a;
	bc = (int *)b;
	if (*ac > *bc)
		return (1);
	else if (*ac < *bc)
		return (-1);
	return (0);
}

static bool	array_is_unique(int *arr, size_t n)
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

static int	*coord_compression(int *arr_src, int *arr_cpy, size_t n)
{
	int		*arr_dst;
	size_t	i;

	arr_dst = (int *)ft_xmalloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		arr_dst[i] = ft_lower_bound(arr_cpy, n, arr_src[i]) - arr_cpy;
		i++;
	}
	return (arr_dst);
}

void	format_numbers(int **arr_src, size_t n)
{
	int	*arr_cpy;
	int	*arr_dst;

	arr_cpy = ft_arraydup(*arr_src, n);
	if (!arr_cpy)
		hundle_error(NULL);
	ft_qsort(arr_cpy, n, sizeof(int), cmp_ascending);
	if (array_is_unique(arr_cpy, n) == false)
		hundle_error(NULL);
	arr_dst = coord_compression(*arr_src, arr_cpy, n);
	free(*arr_src);
	free(arr_cpy);
	*arr_src = arr_dst;
}
