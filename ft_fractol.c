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
cc -lm ./libft/ft_printf.c ./libft/ft_putchar_fd_.c ./libft/ft_putstr_fd_.c ./libft/ft_print_pointer_fd.c ./libft/ft_putnbr_fd_.c ./libft/ft_putnbr_hex_fd.c ./libft/ft_putlongnbr_fd.c ./libft/ft_itoa.c *.h *.c -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 && ./a.out

*/
int	close_game(void)
{
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_hook(int keycode)
{
	if (keycode == ESC)
	{
		ft_printf("\nESC was pressed! Bye :(\n\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_julia julia)
{
	
	julia.c.x = (double) x / 1920 * 4 - 2;
	julia.c.y = (double) y / 1080 * 4 - 2;
	ft_printf("Code:%d\n", keycode);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_julia		julia;

	julia.width = 1920;
	julia.height = 1080;
	julia.c.x = -0.7;
	julia.c.y = 0.27015;
	julia.radius = 1;
	julia.iterations = 150;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, julia.width, julia.height, "Julia Set");
	img.img = mlx_new_image(mlx, julia.width, julia.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	juliaset(&img, julia);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, key_hook, &img);
	mlx_hook(mlx_win, 17, 1L << 17, close_game, NULL);
	mlx_mouse_hook(mlx_win, mouse_hook, &img);
	mlx_loop(mlx);
	return (0);
}
