/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:47:53 by                   #+#    #+#             */
/*   Updated: 2022/11/12 15:47:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	ft_pointer_hex(uintptr_t nbr)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + '0');
	else if (nbr < 16)
		len += ft_putchar(nbr - 10 + 'a');
	else
	{
		len += ft_pointer_hex(nbr / 16);
		len += ft_pointer_hex(nbr % 16);
	}
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_pointer_hex((uintptr_t)ptr);
	return (len);
}
