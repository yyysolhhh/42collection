/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:54 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:01:46 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

void	init_param(t_fractal *fractal)
{
	fractal->zoom_rate = 0.1;
	fractal->max_iter = 150;
	fractal->color = 0;
	fractal->x_min = -2.0;
	fractal->x_max = 2.0;
	fractal->y_min = -2.0;
	fractal->y_max = 2.0;
}

void	get_fractal(t_fractal *fractal, int ac, char **av)
{
	if (ac < 2)
		error_message(1);
	fractal->name = av[1];
	if (!ft_strncmp(av[1], "mandelbrot", 10)
		|| !ft_strncmp(av[1], "Mandelbrot", 10))
	{
		if (ac != 2)
			error_message(1);
		fractal->num = 1;
	}
	else if (!ft_strncmp(av[1], "julia", 5)
		|| !ft_strncmp(av[1], "Julia", 5))
	{
		if (ac != 4)
			error_message(1);
		fractal->num = 2;
		fractal->j_com.x = ft_atod(av[2]);
		fractal->j_com.y = ft_atod(av[3]);
	}
	else if (!ft_strncmp(av[1], "burningship", 11)
		|| !ft_strncmp(av[1], "Burningship", 11))
		fractal->num = 3;
	else
		error_message(1);
}
