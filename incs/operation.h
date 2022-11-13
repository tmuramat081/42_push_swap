/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:00:50 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/08 00:41:38 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "structure.h"

typedef void	(*t_op_arr[OP_END])(t_node *);

void	op_sa(t_node *node);
void	op_sb(t_node *node);
void	op_pa(t_node *node);
void	op_pb(t_node *node);
void	op_ra(t_node *node);
void	op_rb(t_node *node);
void	op_rra(t_node *node);
void	op_rrb(t_node *node);
void	op_ss(t_node *node);
void	op_rr(t_node *node);
void	op_rrr(t_node *node);
void	print_operation(void	*ptr);
void	exec_operation(t_node *node, t_operation op);

#endif
