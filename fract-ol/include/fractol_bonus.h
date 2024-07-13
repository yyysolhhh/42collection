/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:          <        @student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:28:49 by                   #+#    #+#             */
/*   Updated: 2023/02/25 17:13:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "keycode.h"

# define WIN_WIDTH	900
# define WIN_HEIGHT	900

typedef struct s_color
{
	int	channel[4];
}	t_color;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	int			num;
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom_rate;
	int			max_iter;
	int			color;
	t_img		*img;
	t_complex	j_com;
	t_complex	point;
	int			iter;
}	t_fractal;

void	error_message(int error_num);
void	create_window(t_fractal	*fractal);
void	create_img(t_fractal *fractal);
void	init_param(t_fractal *fractal);
void	get_fractal(t_fractal *fractal, int ac, char **av);
void	set_mandelbrot(t_complex p, t_fractal *frt);
void	set_julia(t_complex p, t_fractal *frt);
void	set_burningship(t_complex p, t_fractal *frt);
void	draw_fractal(t_fractal *fractal);
t_color	make_color(t_fractal *frt);
int		key_event(int keycode, t_fractal *fractal);
int		close(t_fractal *fractal);
int		mouse_event(int button, int x, int y, t_fractal *fractal);

#endif
