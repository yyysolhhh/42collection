/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:25:28 by                   #+#    #+#             */
/*   Updated: 2023/02/25 14:25:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	get_fractal(&fractal, ac, av);
	create_window(&fractal);
	draw_fractal(&fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
