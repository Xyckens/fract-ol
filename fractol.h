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

typedef struct imaginary {
	double	x;
	double	y;
}			t_complex;

t_complex	sqr(t_complex a);
t_complex	add(t_complex a, t_complex b);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct s_fractal {
	t_data		img;
	int			width;
	int			height;
	t_complex	c;
	double		radius;
	int			iterations;
}				t_julia;

t_complex	mappoint(t_julia julia, int x, int y);

void		juliaset(t_data *img, t_julia julia);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif