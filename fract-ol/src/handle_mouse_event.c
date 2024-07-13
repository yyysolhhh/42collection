/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:23 by                   #+#    #+#             */
/*   Updated: 2023/02/25 17:10:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractal *frt, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((double)x / WIN_WIDTH) * (frt->x_max - frt->x_min) + frt->x_min;
	yy = ((double)y / WIN_HEIGHT) * (frt->y_max - frt->y_min) + frt->y_min;
	frt->x_min = xx + (frt->x_min - xx) * zoom;
	frt->y_min = yy + (frt->y_min - yy) * zoom;
	frt->y_max = yy + (frt->y_max - yy) * zoom;
	frt->x_max = xx + (frt->x_max - xx) * zoom;
}

int	mouse_event(int button, int x, int y, t_fractal *frt)
{
	if (button == MOUSE_UP)
	{
		zoom(frt, (double)x, (double)y, 1.3);
		frt->zoom_rate *= 1.3;
	}
	if (button == MOUSE_DOWN)
	{
		zoom(frt, (double)x, (double)y, 0.7);
		frt->zoom_rate *= 0.7;
	}
	draw_fractal(frt);
	return (1);
}
