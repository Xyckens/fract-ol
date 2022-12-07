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
/* 
cc ./libft/ft_strncmp.c ./libft/ft_printf.c ./libft/ft_putchar_fd_.c ./libft/ft_putstr_fd_.c ./libft/ft_print_pointer_fd.c ./libft/ft_putnbr_fd_.c ./libft/ft_putnbr_hex_fd.c ./libft/ft_putlongnbr_fd.c ./libft/ft_itoa.c *.h *.c -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm && ./a.out

*/
void	ft_zoom(double x, double y, t_fractal *julia)
{
	julia->c.x = ((x / julia->zoom + julia->c.x) - (x / (julia->zoom * 1.3)));
	julia->c.y = ((y / julia->zoom + julia->c.y) - (y / (julia->zoom * 1.3)));
	julia->zoom *= 1.3;
	julia->iterations++;
	printf("zoomed X:%f Y: %f\n", julia->c.x, julia->c.y);
}

void	ft_dezoom(double x, double y, t_fractal *julia)
{
	julia->c.x = (x / julia->zoom + julia->c.x)  - (x / (julia->zoom / 1.3));
	julia->c.y = (y / julia->zoom + julia->c.y) - (y / (julia->zoom / 1.3));
	julia->zoom /= 1.3;
	julia->iterations--;
	printf("dezoomed X:%f Y: %f\n", julia->c.x, julia->c.y);
}
int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	fractalsetup(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length,
			&fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	/*else if (!ft_strncmp(fractal.name, "burning", 7))
		burningset(fractal);*/
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

void	julia_param(t_fractal *julia)
{
	julia->width = 1280;
	julia->height = 720;
	julia->c.x = -0.7;
	julia->c.y = 0.27015;
	julia->radius = 3;
	julia->iterations = 150;
	julia->zoom = 1;
	julia->x = 0;
	julia->y = 0;
	julia->xarrow = 0;
	julia->yarrow = 0;


}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
	{
		ft_printf("\nESC was pressed! Turning off :(\n");
		exit(EXIT_SUCCESS);
	}	
	else if (keycode == LEFT)
		fractal->xarrow -= 30;
	else if (keycode == DOWN)
		fractal->yarrow += 30;
	else if (keycode == RIGHT)
		fractal->xarrow += 30;
	else if (keycode == UP)
		fractal->yarrow -= 30;
	else if (keycode == R)
	{
		ft_printf("Reset time!");
		julia_param(fractal);
	}
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
		ft_zoom(((double) x / fractal->width * 4 - 2),((double) y / fractal->height * 3 - 1.5), fractal);
	else if (key_code == 5)
		ft_dezoom(((double) x / fractal->width * 4 - 2),((double) y / fractal->height * 3 - 1.5), fractal);
	fractalsetup(fractal);
	printf("\nX:%f Y: %f\n", fractal->c.x, fractal->c.y);
	return (0);
}

/*
void	burningparam(t_fractal burning)
{
	t_fractal		julia;

	julia.width = 1280;
	julia.height = 720;
	julia.c.x = -0.7;
	julia.c.y = 0.27015;
	julia.radius = 3;
	julia.iterations = 150;
	julia.zoom = 1;
	julia.xoffset = 0;
	julia.yoffset = 0;
}
*/

void	mandelbrot_param(t_fractal *fractal)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 50;
	fractal->zoom = 1;
	fractal->c.x = -2.05;
	fractal->c.y = -1.3;
	fractal->radius = 100;
	//fractal->color = 265;
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	fractal.name = argv[1];
	if (!ft_strncmp(fractal.name, "julia", 5))
		julia_param(&fractal);
	else if (!ft_strncmp(fractal.name, "mandelbrot", 10))
		mandelbrot_param(&fractal);
	/*else if (!ft_strncmp(fractal.name, "burning", 7))
		burningparam(&fractal);*/
	else
		return (0);
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx,  fractal.width, fractal.height, "Julia Set");
	fractalsetup(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, close_game, NULL);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
