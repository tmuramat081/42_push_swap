/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:46:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/22 17:46:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

# include "push_swap.h"
# include "operation.h"

// ********** Best First Search Algorithm ********** //
t_node	*optimize_operations(t_node *first_node, t_solver *solver);
size_t	hash_node(const void *node);
int		priority_comparator(const void *ptr1, const void *ptr2);
void	evalatoruate_cost(t_node *node, t_vector *dp_tab);

bool	is_valid_operation(t_node *node, t_operation op);
t_node	*copy_node(const t_node *src);
bool	is_solved(t_node *node, t_vector *dp_tab);

#endif