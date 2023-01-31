/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:05:59 by yesollee          #+#    #+#             */
/*   Updated: 2022/08/03 16:56:55 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*fresh;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!fresh)
		return (NULL);
	i = 0;
	while (*s1)
		fresh[i++] = *s1++;
	while (*s2)
		fresh[i++] = *s2++;
	fresh[i] = '\0';
	return (fresh);
}
