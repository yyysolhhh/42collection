/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:29:19 by                   #+#    #+#             */
/*   Updated: 2023/01/31 15:39:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	print_pid(void)
{
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	return ;
}

void	handler(int signo)
{
	static t_byte	byte;

	if (signo == SIGUSR1)
	{
		byte.chr |= 0;
		if (byte.curr < 7)
			byte.chr <<= 1;
	}
	else if (signo == SIGUSR2)
	{
		byte.chr |= 1;
		if (byte.curr < 7)
			byte.chr <<= 1;
	}
	byte.curr++;
	if (byte.curr == 8)
	{
		write(1, &byte.chr, 1);
		byte.chr = 0;
		byte.curr = 0;
	}
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
