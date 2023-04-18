/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:10:55 by yesollee          #+#    #+#             */
/*   Updated: 2023/04/18 00:50:02 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	op_swap(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa\n", line, 3))
		swap(a, b, CA);
	else if (!ft_strncmp("sb\n", line, 3))
		swap(a, b, CB);
	else
		swap(a, b, CAB);
}

void	op_push(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("pa\n", line, 3))
		push(a, b, CA);
	else
		push(a, b, CB);
}

void	op_rotate(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra\n", line, 3))
		rotate(a, b, CA);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate(a, b, CB);
	else
		rotate(a, b, CAB);
}

void	op_reverse_rotate(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("rra\n", line, 4))
		reverse_rotate(a, b, CA);
	else if (!ft_strncmp("rrb\n", line, 4))
		reverse_rotate(a, b, CB);
	else
		reverse_rotate(a, b, CAB);
}

void	operate(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa\n", line, 3) || !ft_strncmp("sb\n", line, 3)
		|| !ft_strncmp("ss\n", line, 3))
		op_swap(line, a, b);
	else if (!ft_strncmp("pa\n", line, 3) || !ft_strncmp("pb\n", line, 3))
		op_push(line, a, b);
	else if (!ft_strncmp("ra\n", line, 3) || !ft_strncmp("rb\n", line, 3)
		|| !ft_strncmp("rr\n", line, 3))
		op_rotate(line, a, b);
	else if (!ft_strncmp("rra\n", line, 4) || !ft_strncmp("rrb\n", line, 4)
		|| !ft_strncmp("rrr\n", line, 4))
		op_reverse_rotate(line, a, b);
	else
		print_message(2);
}
