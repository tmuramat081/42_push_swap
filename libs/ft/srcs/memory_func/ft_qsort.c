/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 03:34:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/07 03:34:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef int	(*t_comparator)(const void *, const void *);

static void	do_qsort(char *v, t_binary bin, size_t size, t_comparator cmp)
{
	int		i;
	int		j;
	void	*pivot;

	if (bin.lo >= bin.hi)
		return ;
	pivot = v + size * ((bin.lo + bin.hi) / 2);
	i = bin.lo;
	j = bin.hi;
	while (true)
	{
		while (cmp(v + size * i, pivot) < 0)
			i++;
		while (cmp(v + size * j, pivot) > 0)
			j--;
		if (i >= j)
			break ;
		ft_memswap(v + size * i, v + size * j, size);
		i++;
		j--;
	}
	do_qsort(v, (t_binary){bin.lo, i - 1}, size, cmp);
	do_qsort(v, (t_binary){j + 1, bin.hi}, size, cmp);
}

void	ft_qsort(void *base, size_t n, size_t size, t_comparator cmp)
{
	char		*v;
	t_binary	bin;

	bin.lo = 0;
	bin.hi = n - 1;
	v = (char *)base;
	do_qsort(v, bin, size, cmp);
}
