/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:26:04 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:16:03 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_mandelbrot(t_complex p, t_fractal *frt)
{
	t_complex	z;
	double		x_temp;
	int			i;

	z.x = p.x;
	z.y = p.y;
	i = 0;
	while (i < frt->max_iter && (z.x * z.x) + (z.y * z.y) < 4)
	{
		x_temp = z.x * z.x - z.y * z.y + p.x;
		z.y = 2 * z.x * z.y + p.y;
		z.x = x_temp;
		i++;
	}
	frt->iter = i;
}

void	set_julia(t_complex p, t_fractal *frt)
{
	t_complex	z;
	double		x_temp;
	int			i;

	i = 0;
	z.x = p.x;
	z.y = p.y;
	while (i < frt->max_iter && z.x * z.x + z.y * z.y < 4)
	{
		x_temp = z.x;
		z.x = z.x * z.x - z.y * z.y + frt->j_com.x;
		z.y = 2 * x_temp * z.y + frt->j_com.y;
		i++;
	}
	frt->iter = i;
}

void	set_burningship(t_complex p, t_fractal *frt)
{
	t_complex	z;
	double		x_temp;
	double		y_temp;
	int			i;

	z.x = p.x;
	z.y = p.y;
	i = 0;
	while (i < frt->max_iter && (z.x * z.x) + (z.y * z.y) < 4)
	{
		x_temp = z.x * z.x - z.y * z.y + p.x;
		y_temp = 2 * z.x * z.y;
		if (y_temp < 0)
			y_temp = -y_temp;
		z.y = y_temp + p.y;
		z.x = x_temp;
		i++;
	}
	frt->iter = i;
}
