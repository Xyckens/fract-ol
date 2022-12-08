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
	//fractal->c.x = -2;
	//fractal->c.y = -1.3;
	//fractal->color = 265;
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
}

/*
void	burningparam(t_fractal burning)
{
	t_fractal		fractal;

	fractal.width = 1280;
	fractal.height = 720;
	fractal.c.x = -0.7;
	fractal.c.y = 0.27015;
	fractal.radius = 3;
	fractal.iterations = 150;
	fractal.zoom = 1;
	fractal.xoffset = 0;
	fractal.yoffset = 0;
}
*/