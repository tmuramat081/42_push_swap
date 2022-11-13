/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:40:52 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/22 23:40:52 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

#define ITALIC "\033[3m"
#define ULINE "\033[4m"
#define DEFAULT "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

#ifdef FOR_DEBUG

static void	print_data(t_data *data, int offset)
{
	if (data->is_sorted == true)
		ft_printf("%s", GREEN);
	ft_printf("%-*d", offset, data->value);
	ft_printf("%s", DEFAULT);
}

static void	print_two_stacks(t_deque *stack_a, t_deque *stack_b)
{
	t_data	*itr_a;
	t_data	*itr_b;
	size_t	i;

	ft_printf("%-15s%s", "[A]", "[B]\n");
	itr_a = ft_deque_front(stack_a);
	itr_b = ft_deque_front(stack_b);
	i = 0;
	while (i < (size_t)ft_max(stack_a->len, stack_b->len))
	{
		if (i < stack_a->len)
			print_data(itr_a, 15);
		if (i < stack_b->len)
		{
			if (i >= stack_a->len)
				ft_printf("               ");
			print_data(itr_b, 0);
		}
		ft_printf("\n");
		itr_a = ft_deque_next(stack_a, itr_a, 1);
		itr_b = ft_deque_next(stack_b, itr_b, 1);
		i++;
	}
}

void	print_node(t_node *node)
{
	static int	i;

	ft_printf("\033[2J\033[1H\n");
	ft_printf("node.%d\n", i++);
	ft_printf("size:%d\n", node->size);
	ft_printf("------stack------\n");
	print_two_stacks(node->stack_a, node->stack_b);
	ft_printf("lic:%d\n", node->lic_a);
	ft_printf("----operation----\n");
//	put_answer(node->operations);
	ft_printf("result:%d\n", node->operations->len);
	ft_printf("---cost(f=g+h)---\n");
	ft_printf("%s", ULINE);
	ft_printf("f(total):%d\n", node->cost);
	ft_printf("%s", DEFAULT);
	ft_printf("g(actual):%d\n", node->operations->len);
	ft_printf("h(expected):%d\n", node->cost - node->operations->len);
	ft_printf("\n");
//	usleep(1000000);
}
#else

void	print_node(t_node *node)
{
	(void)node;
}
#endif
