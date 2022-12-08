/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:13:19 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/08 13:13:20 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_param(t_fractal *fractal)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xccf1ff;
}

void	julia_param(t_fractal *fractal)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->c.x = -0.7;
	fractal->c.y = 0.27015;
	fractal->radius = 3;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xccf1ff;
}

void	burning_param(t_fractal *fractal)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 8.157307;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 1710.0;
	fractal->yarrow = 4530.0;
	fractal->color = 0xccf1ff;
}
