/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:45:31 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/22 06:54:01 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const t_solver	g_dataset = {
	.operations = {OP_PA, OP_PB, OP_SA, OP_SB, OP_SS, OP_RA,
	OP_RB, OP_RR, OP_RRA, OP_RRB, OP_RRR, OP_END},
	.evaluator = evaluator,
	.checker = checker,
	.search_width = 4,
};
