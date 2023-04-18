/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:11:20 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/20 09:29:12 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	parse_av(&a, &b, ac, av);
	index_av(&a);
	if (!is_sorted(a))
		pushswap_sort(a, b);
	free_all(a);
	free_all(b);
	return (0);
}
