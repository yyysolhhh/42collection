/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:11 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:05:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "pushswap.h"

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_duplicated(t_node *node)
{
	t_node	*temp;

	while (node->next)
	{
		temp = node->next;
		while (temp)
		{
			if (temp->value == node->value)
				error_message();
			temp = temp->next;
		}
		node = node->next;
	}
}
