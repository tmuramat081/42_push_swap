/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:49:21 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/15 15:49:21 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*nums;
	size_t	size;

	if (ac == 1)
		return (0);
	size = (size_t)ac - 1;
	nums = input_arguments(&av[1], size);
	format_numbers(&nums, size);
	solve_push_swap_problem(nums, size);
	return (0);
}
