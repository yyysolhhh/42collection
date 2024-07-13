/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:29:02 by                   #+#    #+#             */
/*   Updated: 2023/01/31 14:29:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"

typedef struct s_byte
{
	int		curr;
	char	chr;
}	t_byte;

#endif
