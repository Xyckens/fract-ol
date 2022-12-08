/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:15:37 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/08 13:15:42 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom * 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom * 1.3));
	fractal->zoom *= 1.3;
	fractal->iterations++;
}

void	ft_dezoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom / 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom / 1.3));
	fractal->zoom /= 1.3;
	fractal->iterations--;
}

int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == LEFT)
		fractal->xarrow -= 30;
	else if (keycode == DOWN)
		fractal->yarrow += 30;
	else if (keycode == RIGHT)
		fractal->xarrow += 30;
	else if (keycode == UP)
		fractal->yarrow -= 30;
	else if (keycode == PLUS)
		fractal->color += 100;
	else if (keycode == MINUS)
		fractal->color -= 100;
	else if (keycode == R)
	{
		ft_printf("Reset time!\n");
		julia_param(fractal);
	}
	else if (keycode == Z)
		fractal->zoom = 1;
	fractalsetup(fractal);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 1 && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->c.x = ((double) x / fractal->width * 4 - 2);
		fractal->c.y = ((double) y / fractal->height * 3 - 1.5);
		fractal->zoom = 1;
	}
	else if (key_code == 4)
		ft_zoom(((double) x / fractal->width * 1000 - 500),
			((double) y / fractal->height * 1000 - 500), fractal);
	else if (key_code == 5)
		ft_dezoom(((double) x / fractal->width * 1000 - 500),
			((double) y / fractal->height * 1000 - 500), fractal);
	fractalsetup(fractal);
	return (0);
}
