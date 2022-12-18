/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:12:18 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/06 22:12:21 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	minimandel(int x, int y, t_fractal *mandel)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	mandel->c.x = (x + mandel->xarrow) / mandel->zoom
		* (0.47 + 2.0) / (mandel->width - 1) - 2.0;
	mandel->c.y = (y + mandel->yarrow) / mandel->zoom
		* (1.12 + 1.12) / (mandel->width - 1) - 1.12;
	z0 = mandel->c.x;
	z1 = mandel->c.y;
	while (i++ < mandel->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + mandel->c.x;
		z1 = 2.0 * z0 * z1 + mandel->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(mandel, (int) x, (int) y, (mandel->color * i));
			break ;
		}
	}
}

void	mandelbrotset(t_fractal *mandel)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= mandel->width)
	{
		y = -1;
		while (++y <= mandel->height)
		{
			minimandel(x, y, mandel);
		}
	}
}
