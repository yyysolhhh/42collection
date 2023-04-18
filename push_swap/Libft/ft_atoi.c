/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:46:53 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/13 00:54:26 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (res * sign);
}

double	ft_atod(const char *str)
{
	int		i;
	int		sign;
	int		len;
	double	res;
	double	temp;

	sign = 1;
	res = 0;
	len = ft_strlen(str);
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	res = ft_atoi(str);
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	temp = ft_atoi(str + i);
	i = len - i;
	while (i--)
		temp /= 10;
	return (sign * (res + temp));
}
