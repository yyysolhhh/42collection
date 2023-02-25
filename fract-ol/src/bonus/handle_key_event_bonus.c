/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:49 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:29 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "fractol_bonus.h"

static void	move_display(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_UP)
	{
		fractal->y_min = fractal->y_min - fractal->zoom_rate;
		fractal->y_max = fractal->y_max - fractal->zoom_rate;
	}
	if (keycode == KEY_DOWN)
	{
		fractal->y_min = fractal->y_min + fractal->zoom_rate;
		fractal->y_max = fractal->y_max + fractal->zoom_rate;
	}
	if (keycode == KEY_LEFT)
	{
		fractal->x_min = fractal->x_min - fractal->zoom_rate;
		fractal->x_max = fractal->x_max - fractal->zoom_rate;
	}
	if (keycode == KEY_RIGHT)
	{
		fractal->x_min = fractal->x_min + fractal->zoom_rate;
		fractal->x_max = fractal->x_max + fractal->zoom_rate;
	}
	draw_fractal(fractal);
}

static void	shift_color(t_fractal *fractal)
{
	fractal->color = (fractal->color + 1) % 3;
	draw_fractal(fractal);
}

static void	change_iter(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_GREATER_THAN)
		fractal->max_iter += 10;
	if (keycode == KEY_LESS_THAN)
		fractal->max_iter -= 10;
	draw_fractal(fractal);
}

int	close(t_fractal *fractal)
{
	fractal->num = 0;
	exit(0);
}

int	key_event(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_display(keycode, fractal);
	if (keycode == KEY_0)
		shift_color(fractal);
	if (keycode == KEY_GREATER_THAN || keycode == KEY_LESS_THAN)
		change_iter(keycode, fractal);
	return (0);
}
