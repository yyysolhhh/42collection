/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:09 by yesollee          #+#    #+#             */
/*   Updated: 2022/11/12 16:19:41 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	handle_format(char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_print_pointer(va_arg(ap, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	parse_str(const char *str, va_list ap)
{
	int	i;
	int	print_len;

	print_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_len += handle_format(str[i], ap);
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, str);
	print_len = parse_str(str, ap);
	va_end(ap);
	return (print_len);
}
