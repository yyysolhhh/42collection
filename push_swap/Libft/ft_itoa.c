/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:56:53 by                   #+#    #+#             */
/*   Updated: 2022/08/13 15:24:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long long nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			i;
	long long	nbr;

	nbr = n;
	i = nbr_len(nbr);
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!(arr))
		return (NULL);
	arr[i] = 0;
	if (nbr == 0)
		arr[0] = '0';
	else if (nbr < 0)
	{
		arr[0] = '-';
		nbr *= -1;
	}
	i--;
	while (nbr > 0)
	{
		arr[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	return (arr);
}
