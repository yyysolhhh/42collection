/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:39 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:16:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static void	print_rev_rotate_op(int flag)
{
	if (flag == A)
		ft_putstr_fd("rra\n", 1);
	else if (flag == B)
		ft_putstr_fd("rrb\n", 1);
	else if (flag == AB)
		ft_putstr_fd("rrr\n", 1);
	else
		return ;
}

static void	reverse_rotate_one(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*second_tolast;

	if (stack->size < 2)
		return ;
	temp = stack->bottom;
	second_tolast = stack->bottom->prev;
	stack->top->prev = temp;
	temp->next = stack->top;
	temp->prev = NULL;
	stack->top = temp;
	stack->bottom = second_tolast;
	second_tolast->next = NULL;
	print_rev_rotate_op(flag);
}

void	reverse_rotate(t_stack *a, t_stack *b, int flag)
{
	if (flag == A || flag == AB || flag == CA || flag == CAB)
		reverse_rotate_one(a, flag);
	else if (flag == B || flag == AB || flag == CB || flag == CAB)
		reverse_rotate_one(b, flag);
	else
		return ;
}
