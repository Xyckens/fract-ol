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

t_complex	mappoint(t_julia *julia, double x, double y)
{
	t_complex	c;
	int			l;

	if (julia->width < julia->height)
		l = julia->height;
	else
		l = julia->height;
	c.x = 2 * julia->radius * (x - julia->width / 2) / l;
	c.y = 2 * julia->radius * (y - julia->height / 2) / l;
	return (c);
}
