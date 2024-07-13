/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:47:56 by                   #+#    #+#             */
/*   Updated: 2022/11/07 18:44:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int			len;

	len = 0;
	if (num >= 10)
	{
		len += ft_print_unsigned(num / 10);
		len += ft_putchar(num % 10 + '0');
	}
	else
		len += ft_putchar(num + '0');
	return (len);
}
