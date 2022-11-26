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

static int	cmp_ascending(const void *a, const void *b)
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

static bool	is_array_unique(int *nums, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n)
	{
		if (nums[i] == nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}

static int	*coord_compression(int *src_nums, int *cpy_nums, size_t n)
{
	int		*dst_nums;
	size_t	i;

	dst_nums = (int *)ft_xmalloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		dst_nums[i] = ft_lower_bound(cpy_nums, n, src_nums[i]) - cpy_nums;
		i++;
	}
	return (dst_nums);
}

void	format_numbers(int **src_nums, size_t n)
{
	int	*cpy_nums;
	int	*dst_nums;

	cpy_nums = ft_arraydup(*src_nums, n);
	if (!cpy_nums)
		common_hundle_error(NULL);
	ft_qsort(cpy_nums, n, sizeof(int), cmp_ascending);
	if (is_array_unique(cpy_nums, n) == false)
		common_hundle_error(NULL);
	dst_nums = coord_compression(*src_nums, cpy_nums, n);
	free(*src_nums);
	free(cpy_nums);
	*src_nums = dst_nums;
}
