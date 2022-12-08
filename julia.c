/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:27:09 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/30 11:27:13 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	juliaset(t_fractal *julia)
{
	double		x;
	double		y;
	int			i;
	t_complex	z0;
	t_complex	z1;

	x = 0;
	while (++x <= julia->width)
	{
		y = 0;
		while (++y <= julia->height)
		{
			z0 = mappoint(julia, x, y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				if (sqrt(z1.x * z1.x + z1.y * z1.y) > julia->radius)
				{
					my_mlx_pixel_put(julia, x, y, (0xccf1ff * i));
					break ;
				}
				z0 = z1;
			}
		}
	}
}
