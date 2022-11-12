/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:00:29 by yesollee          #+#    #+#             */
/*   Updated: 2022/11/07 14:22:33 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int n)
{
	int			len;
	long long	num;

	len = 0;
	num = n;
	if (num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		len += ft_putnbr(num / 10);
		len += ft_putnbr(num % 10);
	}
	else
		len += ft_putchar(num + '0');
	return (len);
}
