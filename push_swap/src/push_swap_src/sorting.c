/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:12:13 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:18:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	move_atob(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (a->size)
	{
		if (a->top->value <= i)
		{
			push(a, b, B);
			i++;
		}
		else if (i < a->top->value && a->top->value <= i + chunk)
		{
			push(a, b, B);
			rotate(a, b, B);
			i++;
		}
		else if (i + chunk < a->top->value)
		{
			if (i < a->size / 2 && 0 <= i)
				reverse_rotate(a, b, A);
			else
				rotate(a, b, A);
		}
	}
}

static int	search_max(t_stack *b, int max)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = b->top;
	while (temp)
	{
		if (temp->value == max)
			break ;
		i++;
		temp = temp->next;
	}
	if (i <= b->size / 2)
		return (1);
	return (0);
}

static void	move_btoa(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		if (search_max(b, b->size - 1))
		{
			while (b->top->value != b->size - 1)
				rotate(a, b, B);
		}
		else
		{
			while (b->top->value != b->size - 1)
				reverse_rotate(a, b, B);
		}
		push(b, a, A);
	}
}

static void	sort_general(t_stack *a, t_stack *b)
{
	int	x;
	int	chunk;

	x = a->size;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	move_atob(a, b, chunk);
	move_btoa(a, b);
}

void	pushswap_sort(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
		sort_small_size(a, b);
	else
		sort_general(a, b);
	return ;
}
