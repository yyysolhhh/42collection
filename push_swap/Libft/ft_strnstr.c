/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:00:50 by                   #+#    #+#             */
/*   Updated: 2022/09/16 02:02:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i) && i < len)
		{
			i++;
			if (!*(needle + i))
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
