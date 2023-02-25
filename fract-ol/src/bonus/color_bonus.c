/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:08 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:00 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_bonus.h"

t_color	make_color(t_fractal *frt)
{
	t_color	color;
	double	t;
	int		form[3];

	t = (double)frt->iter / frt->max_iter;
	color.channel[0] = 0;
	form[0] = (int)(5 * (1 - t) * pow(t, 3) * 255);
	form[1] = (int)(10 * pow((1 - t), 2) * pow(t, 2) * 255);
	form[2] = (int)(5.3 * pow((1 - t), 3) * t * 255);
	color.channel[(0 + frt->color) % 3 + 1] = form[0];
	color.channel[(1 + frt->color) % 3 + 1] = form[1];
	color.channel[(2 + frt->color) % 3 + 1] = form[2];
	return (color);
}
