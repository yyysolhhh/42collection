/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:29:15 by                   #+#    #+#             */
/*   Updated: 2023/01/31 17:54:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	check_error(int ac, char **av, t_data *data)
{
	if (ac != 3)
	{
		ft_putstr_fd("invalid arguments\n", 1);
		return (1);
	}
	data->pid = ft_atoi(av[1]);
	if (data->pid <= 100)
	{
		ft_putstr_fd("invalid pid\n", 1);
		return (1);
	}
	return (0);
}

void	send_byte(int pid, char chr)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (chr >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	send_str(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		send_byte(data->pid, data->str[i]);
		i++;
	}
	send_byte(data->pid, 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_error(ac, av, &data))
		return (1);
	data.str = av[2];
	send_str(&data);
	return (0);
}
