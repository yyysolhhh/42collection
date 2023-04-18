/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:08 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:14:08 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

static void	del_node(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
		temp = NULL;
	}
	free(node);
	node = NULL;
}

void	free_all(t_stack *stack)
{
	if (stack->top)
		del_node(stack->top);
	free(stack);
	stack = NULL;
}
