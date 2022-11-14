/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:44:33 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/06 20:44:33 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "ft_printf.h"

const char		*g_op_strs[OP_END] = {
	"sa",
	"sb",
	"pa",
	"pb",
	"ra",
	"rb",
	"rra",
	"rrb",
	"ss",
	"rr",
	"rrr"
};

const t_op_arr	g_op_exec = {
	op_sa,
	op_sb,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rra,
	op_rrb,
	op_ss,
	op_rr,
	op_rrr
};

void	print_operation(void	*ptr)
{
	t_operation	*op;

	op = (t_operation *)ptr;
	ft_printf("%s\n", g_op_strs[*op]);
	return ;
}

void	exec_repeated_operation(t_node *node, t_operation op, size_t n)
{
	while (n--)
	{
		g_op_exec[op](node);
	}
}

void	exec_operation(t_node *node, t_operation op)
{
	g_op_exec[op](node);
}
