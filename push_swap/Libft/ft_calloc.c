/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:55:43 by yesollee          #+#    #+#             */
/*   Updated: 2023/03/19 12:30:04 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_cnt;

	size_cnt = size * count;
	ptr = malloc(size_cnt);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size_cnt);
	return (ptr);
}
