/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:33 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:15:42 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static void	print_push_op(int flag)
{
	if (flag == A)
		ft_putstr_fd("pa\n", 1);
	else if (flag == B)
		ft_putstr_fd("pb\n", 1);
	else
		return ;
}

static void	one_size_from(t_stack *from, t_stack *to)
{
	if (!to->size)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

static void	pop_push(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		one_size_from(from, to);
	else
	{
		if (!to->size)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size += 1;
	from->size -= 1;
}

void	push(t_stack *from, t_stack *to, int flag)
{
	if (!from->size)
		return ;
	pop_push(from, to);
	print_push_op(flag);
}
