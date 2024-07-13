/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:59:14 by                   #+#    #+#             */
/*   Updated: 2022/08/06 15:36:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;

	if (dst == src || !len)
		return (dst);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (to > from)
		while (len--)
			*(to + len) = *(from + len);
	else
		while (len--)
			*to++ = *from++;
	return (dst);
}
