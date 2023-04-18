/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:23 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:15:13 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pushswap.h"

static void	link_node(t_node **temp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

static void	set_node(char *av, t_node **node, t_stack **stack)
{
	char	**av_arr;
	t_node	*temp;
	int		i;

	av_arr = ft_split(av, ' ');
	if (!av_arr || !*av_arr)
		error_message();
	i = 0;
	while (av_arr[i])
	{
		temp = init_node();
		if (!temp)
			error_message();
		temp->value = ft_atoi_ps(av_arr[i]);
		link_node(&temp, node, stack);
		(*stack)->size++;
		free(av_arr[i]);
		av_arr[i] = NULL;
		i++;
	}
	free(av_arr);
	av_arr = NULL;
}

static t_node	*fill_stack(t_stack **stack, int ac, char **av)
{
	t_node	*node;
	int		i;

	node = NULL;
	i = 1;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], "", 1))
			error_message();
		set_node(av[i], &node, stack);
		i++;
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}

void	parse_av(t_stack **a, t_stack **b, int ac, char **av)
{
	*a = init_stack();
	(*a)->top = fill_stack(a, ac, av);
	check_duplicated((*a)->top);
	*b = init_stack();
}
