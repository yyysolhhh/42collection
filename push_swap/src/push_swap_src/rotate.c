/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:42 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:16:56 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static void	print_rotate_op(int flag)
{
	if (flag == A)
		ft_putstr_fd("ra\n", 1);
	else if (flag == B)
		ft_putstr_fd("rb\n", 1);
	else if (flag == AB)
		ft_putstr_fd("rr\n", 1);
	else
		return ;
}

static void	rotate_one(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*second;

	if (stack->size < 2)
		return ;
	temp = stack->top;
	second = stack->top->next;
	stack->bottom->next = temp;
	temp->prev = stack->bottom;
	temp->next = NULL;
	stack->bottom = temp;
	stack->top = second;
	second->prev = NULL;
	print_rotate_op(flag);
}

void	rotate(t_stack *a, t_stack *b, int flag)
{
	if (flag == A || flag == AB || flag == CA || flag == CAB)
		rotate_one(a, flag);
	else if (flag == B || flag == AB || flag == CB || flag == CAB)
		rotate_one(b, flag);
	else
		return ;
}
