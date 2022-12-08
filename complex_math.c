/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:53:17 by fvieira           #+#    #+#             */
/*   Updated: 2022/12/02 13:53:19 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_complex	mappoint(t_fractal *fractal, double x, double y)
{
	t_complex	c;
	double		l;

	if (fractal->width < fractal->height)
		l = fractal->height * fractal->zoom;
	else
		l = fractal->height * fractal->zoom;
	x += fractal->xarrow ;
	y += fractal->yarrow ;
	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
	return (c);
}
