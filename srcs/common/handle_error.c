/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:58:54 by tmuramat          #+#    #+#             */
/*   Updated: 2022/11/26 11:13:05 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define OPERATION_SIZE 64
#define ERR_MSG "Error"

void	common_hundle_error(t_node *node)
{
	if (node)
		delete_node(node);
	ft_putendl_fd(ERR_MSG, 2);
	exit(EXIT_FAILURE);
}
