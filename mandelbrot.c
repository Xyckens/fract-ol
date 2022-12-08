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

/*int	put_pxl_to_img2(t_fractal *julia, int x, int y, int color)
{
	color = mlx_get_color_value(julia->mlx, color);
	ft_memcpy(julia->addr + 4 * julia->width * y + x * 4,
			&color, sizeof(int));
	return (0);
	
}
int	my_mlx_pixel_put2(t_fractal *julia, int x, int y, int color)
{
	char	*dst;

	dst = julia->addr + (y * julia->line_length + x * (julia->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}
*/
void	mandelbrotset(t_fractal *mandel)
{
	int	x;
	int	y;
	int		i;
	double	z0;
	double	z1;
	double	tempz0;
	t_complex	c;

	x = -1;
	i = 0;
	while (++x <= mandel->width)
	{
		y = -1;
		while (++y <= mandel->height)
		{
			mandel->c.x = (x + mandel->xarrow) / mandel->zoom * (0.47 + 2.0) / (mandel->width - 1) - 2.0;
			mandel->c.y = (y + mandel->yarrow) / mandel->zoom * (1.12 + 1.12) / (mandel->width - 1) - 1.12;
			z0 = mandel->c.x;
			z1 = mandel->c.y;
			i = 0;
			while (i++ < mandel->iterations)
			{
				tempz0 = z0 * z0 - z1 * z1 + mandel->c.x;
				z1 = 2.0 * z0 * z1 + mandel->c.y;
				z0 = tempz0;
				if (z0 * z0 + z1 * z1 > 4)
				{
					my_mlx_pixel_put(mandel, (int) x, (int) y, (0xccf1ff * i));
					break ;
				}
			}
		}
	}
}
/*{
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
			z1.y = 2.0 * z1.x * z1.y 
			z1.x = temp;
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
}*/