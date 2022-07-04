/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:44:16 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 13:44:16 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	convert_number(char *str)
{
	char	*endptr;
	long	l_num;

	endptr = NULL;
	l_num = ft_strtol_d(str, &endptr);
	if (l_num < INT_MIN || INT_MAX < l_num)
		hundle_error(NULL);
	else if (*endptr || endptr == str)
		hundle_error(NULL);
	return ((int)l_num);
}

int	*input_numbers(char **args, size_t n)
{
	size_t	i;
	int		*arr;

	arr = (int *)ft_xmalloc(sizeof(int) * (n));
	i = 0;
	while (i < n)
	{
		arr[i] = convert_number(args[i]);
		i++;
	}
	return (arr);
}
