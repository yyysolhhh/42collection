/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:28 by yesollee          #+#    #+#             */
/*   Updated: 2023/02/25 17:15:56 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	get_fractal(&fractal, ac, av);
	create_window(&fractal);
	draw_fractal(&fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
