/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:45 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:17:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_3_av(t_stack *a, t_stack *b)
{
	int	left;
	int	mid;
	int	right;

	left = a->top->value;
	mid = a->top->next->value;
	right = a->top->next->next->value;
	if (left < mid && left < right && mid > right)
	{
		swap(a, b, A);
		rotate(a, b, A);
	}
	else if (left > mid && left < right && mid < right)
		swap(a, b, A);
	else if (left < mid && left > right && mid > right)
		reverse_rotate(a, b, A);
	else if (left > mid && left > right && mid < right)
		rotate(a, b, A);
	else if (left > mid && left > right && mid > right)
	{
		swap(a, b, A);
		reverse_rotate(a, b, A);
	}
}

static int	find_mid(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;
	int		n;

	node = stack->top;
	while (node)
	{
		n = 0;
		temp = stack->top;
		while (temp)
		{
			if (node->value < temp->value)
				n++;
			temp = temp->next;
		}
		if (n == 2)
			return (node->value);
		node = node->next;
	}
	return (0);
}

static void	sort_4to5_av(t_stack *a, t_stack *b)
{
	int	mid;

	mid = find_mid(a);
	while (a->size > 3)
	{
		while (a->top->value >= mid)
			rotate(a, b, A);
		push(a, b, B);
	}
	sort_3_av(a, b);
	while (b->size > 0)
		push(b, a, A);
	if (a->top->value > a->top->next->value)
		swap(a, b, A);
}

void	sort_small_size(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a, b, A);
	else if (a->size == 3)
		sort_3_av(a, b);
	else
		sort_4to5_av(a, b);
}
