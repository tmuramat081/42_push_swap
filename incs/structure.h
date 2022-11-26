/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:46:05 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 12:44:37 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "ft_deque.h"
# include "ft_vector.h"
# include "ft_pqueue.h"
# include "ft_hashset.h"

typedef struct s_node		t_node;
typedef struct s_tab		t_tab;
typedef struct s_data		t_data;
typedef struct s_solver		t_solver;
typedef struct s_pair		t_pair;
typedef size_t				(*t_eval)(t_node *);
typedef bool				(*t_check)(t_node *);

struct s_node {
	t_deque		*stack_a;
	t_deque		*stack_b;
	size_t		lic_a;
	size_t		size;
	size_t		cost;
	t_vector	*operations;
};

typedef enum e_operation {
	OP_SA,
	OP_SB,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RRA,
	OP_RRB,
	OP_SS,
	OP_RR,
	OP_RRR,
	OP_END
}	t_operation;

// For Dynamic Programming. it is utilized to calculate lic (Longest Increasing
// Circular Subsequense).
struct s_tab {
	t_vector	*val;
	t_vector	*idx;
};

// For each elements of stack_A or stack_B. the "value" is compressed number.
struct s_data {
	int		value;
	bool	is_sorted;
};

struct s_pair {
	int	a;
	int	b;
};

struct s_solver {
	t_operation	operations[OP_END + 1];
	t_eval		evaluator;
	t_check		checker;
	size_t		search_width;
};

#endif