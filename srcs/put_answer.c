/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:53:01 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/16 23:53:01 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_answer(t_vector *ops)
{
	ft_vector_foreach(ops, &print_operation);
}
