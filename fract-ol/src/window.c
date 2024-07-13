/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:34 by                   #+#    #+#             */
/*   Updated: 2023/02/25 17:04:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "fractol.h"

void	create_img(t_fractal *f)
{
	f->img->img_ptr = mlx_new_image(f->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img->img_ptr)
		error_message(3);
	f->img->data = mlx_get_data_addr(f->img->img_ptr, &f->img->bits_per_pixel,
			&f->img->size_line, &f->img->endian);
	if (!f->img->data)
		error_message(3);
}

void	create_window(t_fractal	*f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		error_message(3);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, f->name);
	if (!f->win_ptr)
		error_message(3);
	f->img = (t_img *)malloc(sizeof(t_img));
	if (!f->img)
		error_message(4);
	init_param(f);
	mlx_hook(f->win_ptr, KEYPRESS, 1L << 0, key_event, f);
	mlx_hook(f->win_ptr, ON_DESTROY, 0, close, f);
	mlx_hook(f->win_ptr, ON_MOUSEDOWN, 0, mouse_event, f);
}
