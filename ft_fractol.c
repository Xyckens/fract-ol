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
cc ./libft/ft_strncmp.c ./libft/ft_printf.c ./libft/ft_putchar_fd_.c ./libft/ft_putstr_fd_.c ./libft/ft_print_pointer_fd.c ./libft/ft_putnbr_fd_.c ./libft/ft_putnbr_hex_fd.c ./libft/ft_putlongnbr_fd.c ./libft/ft_itoa.c *.h *.c -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm && ./a.out julia

*/

void	fractalsetup(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	/*else if (!ft_strncmp(fractal.name, "burning", 7))
		burningset(fractal);*/
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
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
	fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, "Julia Set");
	fractalsetup(&fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, close_game, NULL);
	mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
