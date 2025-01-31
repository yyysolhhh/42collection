/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:59:07 by                   #+#    #+#             */
/*   Updated: 2022/08/06 15:36:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*to;
	char	*from;

	if (dst == src)
		return (dst);
	to = (char *)dst;
	from = (char *)src;
	while (n--)
		*to++ = *from++;
	return (dst);
}
