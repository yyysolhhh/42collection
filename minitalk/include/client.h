/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:28:49 by                   #+#    #+#             */
/*   Updated: 2023/01/31 14:28:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"

typedef struct s_data
{
	int		pid;
	char	*str;
}	t_data;

#endif
