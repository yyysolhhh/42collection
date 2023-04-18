/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:57 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:19:50 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static void	print_swap_op(int flag)
{
	if (flag == A)
		ft_putstr_fd("sa\n", 1);
	else if (flag == B)
		ft_putstr_fd("sb\n", 1);
	else if (flag == AB)
		ft_putstr_fd("ss\n", 1);
	else
		return ;
}

static void	swap_one(t_stack *stack, int flag)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	print_swap_op(flag);
}

void	swap(t_stack *a, t_stack *b, int flag)
{
	if (flag == A || flag == AB || flag == CA || flag == CAB)
		swap_one(a, flag);
	else if (flag == B || flag == AB || flag == CB || flag == CAB)
		swap_one(b, flag);
	else
		return ;
}
