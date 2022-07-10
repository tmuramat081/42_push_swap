/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:46:05 by tmuramat          #+#    #+#             */
/*   Updated: 2022/07/03 22:46:05 by tmuramat         ###   ########.fr       */
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
typedef size_t				(*t_eval)(t_node *);
typedef bool				(*t_check)(t_node *);

struct s_node {
	t_deque		*stack_a;
	t_deque		*stack_b;
	size_t		lics_a;
	size_t		size;
	size_t		cost;
	size_t		target;
	t_vector	*ops;
};


// For Dynamic Programming. it is utilized to calculate LICS (Longest Increasing Circular Subsequense). 
struct s_tab {
	t_vector	*val;
	t_vector	*idx;
};

// For each elements of stack_A or stack_B. the "value" is compressed number.
struct s_data {
	int		value;
	bool	is_sorted;
};

struct s_solver {
	t_eval		evaluator;
	t_check		checker;
	size_t		search_width;
};

#endif