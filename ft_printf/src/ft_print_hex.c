/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:47:50 by yesollee          #+#    #+#             */
/*   Updated: 2022/11/07 17:23:11 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, char format)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + '0');
	else if (nbr < 16)
	{
		if (format == 'x')
			len += ft_putchar(nbr - 10 + 'a');
		else if (format == 'X')
			len += ft_putchar(nbr - 10 + 'A');
	}
	else
	{
		len += ft_print_hex(nbr / 16, format);
		len += ft_print_hex(nbr % 16, format);
	}
	return (len);
}
