/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:17 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:16 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol_bonus.h"

void	error_message(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd("./fractol [fractal_name] {}\n"
			"Fractal List:\n"
			"	- Mandelbrot (mandelbrot)\n"
			"	- Julia (julia) {0.285 0.01} {-0.75 0.11} {-0.8 0.156}\n"
			"	- Burningship (burningship)\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("mlx fail\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("malloc fail\n", 2);
	exit(1);
}
