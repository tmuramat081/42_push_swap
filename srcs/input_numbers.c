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

int	convert_str_to_int(char *str)
{
	char	*end_ptr;
	long	long_num;

	end_ptr = NULL;
	long_num = ft_strtol_d(str, &end_ptr);
	if (long_num < INT_MIN || INT_MAX < long_num)
		hundle_error(NULL);
	else if (*end_ptr || end_ptr == str)
		hundle_error(NULL);
	return ((int)long_num);
}

/** When strings are received, convert to int value. */
int	*input_multiple_string(char **str, size_t len)
{
	int		*nums;
	size_t	i;

	nums = (int *)ft_xmalloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		nums[i] = convert_str_to_int(str[i]);
		i++;
	}
	return (nums);
}

/** When a string is received, split and convert to int value. */
int	*input_single_string(char *str)
{
	int		*nums;
	char	*save_ptr;
	char	*token;
	size_t	i;

	nums = (int *)ft_xmalloc(sizeof(int) * ft_strlen(str));
	save_ptr = NULL;
	token = ft_strtok_r(str, " ", &save_ptr);
	i = 0;
	while (token)
	{
		nums[i] = convert_str_to_int(token);
		token = ft_strtok_r(NULL, " ", &save_ptr);
		i++;
	}
	return (nums);
}

int	*input_arguments(char **args, size_t len)
{
	int		*nums;

	if (len == 1)
		nums = input_single_string(args[0]);
	else
		nums = input_multiple_string(args, len);
	return (nums);
}
