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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	juliaset(t_data *img, t_julia julia)
{
	int			x;
	int			y;
	int			i;
	t_complex	z0;
	t_complex	z1;

	x = 0;
	while (x++ <= julia.width)
	{
		y = 0;
		while (y++ <= julia.height)
		{
			z0 = mappoint(julia, x, y);
			i = 1;
			while (i++ <= julia.iterations)
			{
				z1 = add(sqr(z0), julia.c);
				if (sqrt(z1.x * z1.x + z1.y * z1.y) > julia.radius)
				{
					my_mlx_pixel_put(img, x, y, (0xccf1ff * i));
					break ;
				}
				z0 = z1;
			}
		}
	}
}
