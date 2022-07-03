#include "push_swap.h"
#include "operation.h"
#include "bfs.h"

# define INIT_CAPACITY 128

void	select_next_node(t_priqueue *tmp_open_list, t_priqueue *open_list, size_t search_width)
{
	t_node	*node;
	size_t	i;

	i = 0;
	while (i < (size_t)ft_min(search_width, ft_priority_queue_size(tmp_open_list)))
	{
		node = ft_priority_queue_pop(tmp_open_list);
		ft_priority_queue_push(open_list, node);
		i++;
	}
}

void	expand_next_nodes(t_node *node, t_priqueue *open_list, t_hashset *closed_list, t_solver *solver)
{
	t_node		*tmp_node;
	t_priqueue	*tmp_open_list;
	t_operation	next_op;

	tmp_open_list = ft_priority_queue_init(OP_END, &priority_comparator);
	next_op = OP_SA;
	while(next_op < OP_END)
	{
		if (is_valid_operation(node, next_op) == true)
		{
			tmp_node = copy_node(node);
			exec_operation(tmp_node, next_op);
			if (ft_hashset_insert(closed_list, tmp_node) == HASHSET_SUCCESS)
			{
				tmp_node->cost = solver->evaluator(tmp_node);
				ft_priority_queue_push(tmp_open_list, tmp_node);
			}
			else
				delete_node(tmp_node);
		}
		next_op++;
	}
	select_next_node(tmp_open_list, open_list, solver->search_width);
	ft_priority_queue_delete(&tmp_open_list, delete_node);
}

void	evaluate_first_node(t_node *node, t_priqueue *open_list, t_hashset *closed_list, t_eval evaluator)
{
	node->cost = evaluator(node);
	ft_priority_queue_push(open_list, node);
	ft_hashset_insert(closed_list, node);
}

t_node *update_node(t_node *node, t_priqueue *open_list, t_hashset *closed_list)
{
	t_node *new_node;

	new_node = copy_node(node);
	ft_priority_queue_delete(&open_list, delete_node);
	ft_hashset_delete(&closed_list);
	delete_node(node);
	return (new_node);
}

t_node	*bfs_optimize_operations(t_node *init_node, t_solver *solver)
{
	t_priqueue	*open_list;
	t_hashset	*closed_list;
	t_node		*node;

	open_list = ft_priority_queue_init(INIT_CAPACITY, &priority_comparator);
	closed_list = ft_hashset_init(&hash_node);
	evaluate_first_node(init_node, open_list, closed_list, solver->evaluator);
	while (ft_priority_queue_is_empty(open_list) == false)
	{
		node = ft_priority_queue_pop(open_list);
		print_node(node);
		if (solver->checker(node) == true)
			return (update_node(node, open_list, closed_list));
		expand_next_nodes(node, open_list, closed_list, solver);
		delete_node(node);
	}
	return (NULL);
}
