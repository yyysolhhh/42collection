/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:10:51 by                   #+#    #+#             */
/*   Updated: 2023/03/20 09:49:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	print_message(int num)
{
	if (num == 1)
		ft_putstr_fd("OK\n", 1);
	else if (num == 0)
		ft_putstr_fd("KO\n", 1);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		operate(line, a, b);
		free(line);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		check;

	if (ac < 2)
		return (0);
	parse_av(&a, &b, ac, av);
	checker(a, b);
	check = is_sorted(a);
	free_all(a);
	free_all(b);
	print_message(check);
	return (0);
}
