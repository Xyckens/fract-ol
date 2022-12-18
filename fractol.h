/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:09:50 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/28 17:09:52 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>

# define ESC 65307

# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);

typedef struct s_fractal {
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;

t_complex	mappoint(t_fractal *julia, double x, double y);

void		juliaset(t_fractal *julia);
void		mandelbrotset(t_fractal *mandel);
void		burningset(t_fractal *burning);

int			my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);

void		fractalsetup(t_fractal *fractal);

void		mandelbrot_param(t_fractal *fractal, char *name);
void		julia_param(t_fractal *fractal, char *name);
void		burning_param(t_fractal *fractal, char *name);

void		ft_zoom(double x, double y, t_fractal *fractal);
void		ft_dezoom(double x, double y, t_fractal *fractal);
int			key_hook(int keycode, t_fractal *fractal);
int			mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int			close_game(t_fractal *fractal);

int			freeall(t_fractal *fractal);
#endif