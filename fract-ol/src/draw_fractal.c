/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:40 by                   #+#    #+#             */
/*   Updated: 2023/02/25 17:07:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "libft.h"
#include "fractol.h"

static void	put_pixel(t_fractal *f, int x, int y)
{
	int		pixel;
	t_color	color;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = x * f->img->bits_per_pixel / 8 + y * f->img->size_line;
	if (f->iter == f->max_iter)
	{
		f->img->data[pixel] = 0x00;
		return ;
	}
	color = make_color(f);
	f->img->data[pixel] = color.channel[3];
	f->img->data[pixel + 1] = color.channel[2];
	f->img->data[pixel + 2] = color.channel[1];
	f->img->data[pixel + 3] = color.channel[0];
}

void	draw_fractal(t_fractal *f)
{
	int	x;
	int	y;

	create_img(f);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			f->point.x = f->x_min + x * ((f->x_max - f->x_min) / WIN_WIDTH);
			f->point.y = f->y_min + y * ((f->y_max - f->y_min) / WIN_HEIGHT);
			if (f->num == 1)
				set_mandelbrot(f->point, f);
			else if (f->num == 2)
				set_julia(f->point, f);
			else if (f->num == 3)
				set_burningship(f->point, f);
			put_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img->img_ptr, 0, 0);
	mlx_destroy_image(f->mlx_ptr, f->img->img_ptr);
}
