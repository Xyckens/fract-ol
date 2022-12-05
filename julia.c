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

int	put_pxl_to_img(t_julia *julia, int x, int y, int color)
{
	color = mlx_get_color_value(julia->mlx, color);
	ft_memcpy(julia->addr + 4 * julia->width * y + x * 4,
			&color, sizeof(int));
	return (0);
	
}
int	my_mlx_pixel_put(t_julia *julia, int x, int y, int color)
{
	char	*dst;

	dst = julia->addr + (y * julia->line_length + x * (julia->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	juliaset(t_julia *julia)
{
	double			x;
	double			y;
	int			i;
	t_complex	z0;
	t_complex	z1;

	x = 0;
	while (x <= julia->width)
	{
		y = 0;
		//x= x *1/2;
		while (y <= julia->height)
		{
			//y= y *1/2;
			z0 = mappoint(julia, x, y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				if (sqrt(z1.x * z1.x + z1.y * z1.y) > julia->radius)
				{
					my_mlx_pixel_put(julia, (int) x, (int)y, (0xccf1ff * i));
					//mlx_pixel_put(julia->mlx, julia->win, x, y, (0xccf1ff * i));
					//put_pxl_to_img(julia, x, y, (0xccf1ff * i));
					break ;
				}
				z0 = z1;
			}
			y++;
		}
		x++;
	}
}
