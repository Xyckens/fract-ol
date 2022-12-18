/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:09:36 by fvieira           #+#    #+#             */
/*   Updated: 2022/11/28 17:09:41 by fvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "burning", 7))
		burningset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void	wronginputs(void)
{
	ft_printf("Unrecognized input!!! \nThis program only takes the ");
	ft_printf("parameters: \'julia\', \'mandelbrot\' or ");
	ft_printf("\'burning\' to display any of these fractal types!");
	exit(1);
}

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10)
			mandelbrot_param(&fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
			julia_param(&fractal, argv[1]);
		else if (!ft_strncmp(argv[1], "burning", 7) && ft_strlen(argv[1]) == 7)
			burning_param(&fractal, argv[1]);
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, fractal.width,
				fractal.height, fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
		fractalsetup(&fractal);
		mlx_key_hook(fractal.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
		wronginputs();
	return (0);
}
