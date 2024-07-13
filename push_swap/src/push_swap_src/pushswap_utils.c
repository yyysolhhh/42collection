/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:37 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:52:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi_ps(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			error_message();
		i++;
	}
	if (str[i])
		error_message();
	return (res * sign);
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (1);
	node = stack->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	if (node->value == stack->bottom->value)
		return (1);
	else
		return (0);
}

static void	change_node_value(t_stack **a, int *idx_list)
{
	t_node	*node;
	int		i;

	node = (*a)->top;
	i = 0;
	while (node)
	{
		node->value = idx_list[i];
		node = node->next;
		i++;
	}
	free(idx_list);
}

void	index_av(t_stack **a)
{
	int		*idx_list;
	t_node	*node1;
	t_node	*node2;
	int		i;

	idx_list = (int *)ft_calloc((*a)->size, sizeof(int));
	node1 = (*a)->top;
	i = 0;
	while (node1)
	{
		node2 = (*a)->top;
		while (node2)
		{
			if (node1->value > node2->value)
				idx_list[i] += 1;
			node2 = node2->next;
		}
		node1 = node1->next;
		i++;
	}
	change_node_value(a, idx_list);
}
