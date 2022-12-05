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

https://github.com/GlThibault/Fractol/blob/master/srcs/tools.c
*/
void	ft_zoom(int x, int y, t_julia *julia)
{
	julia->c.x = (x / julia->zoom + julia->c.x) - (x / (julia->zoom * 1.3));
	julia->c.y = (y / julia->zoom + julia->c.y) - (y / (julia->zoom * 1.3));
	julia->zoom *= 1.3;
	julia->iterations++;
}

void	ft_dezoom(int x, int y, t_julia *julia)
{
	julia->c.x = (x / julia->zoom + julia->c.x)  - (x / (julia->zoom / 1.3));
	julia->c.y = (y / julia->zoom + julia->c.y) - (y / (julia->zoom / 1.3));
	julia->zoom /= 1.3;
	julia->iterations--;
}
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

int	mouse_hook(int key_code, int x, int y, t_julia *julia)
{
	ft_printf("keycode%d",key_code);
	if (key_code == 1)
	{
		julia->c.x = ((double) x / julia->width * 4 - 2);
		julia->c.y = ((double) y / julia->height * 3 - 1.5);
	}
	if (key_code == 4)
		ft_zoom(x, y, julia);
	if (key_code == 5)
		ft_dezoom(x, y, julia);
	julia->img = mlx_new_image(julia->mlx , julia->width, julia->height);
	julia->addr = mlx_get_data_addr(julia->img, &julia->bits_per_pixel, &julia->line_length,
			&julia->endian);
	juliaset(julia);
	mlx_put_image_to_window(julia->mlx, julia->win, julia->img, 0, 0);
	printf("X:%f Y: %f\n", julia->c.x, julia->c.y);

	return (0);
}

int	main(void)
{
	t_julia		julia;

	julia.width = 1280;
	julia.height = 720;
	julia.c.x = -0.7;
	julia.c.y = 0.27015;
	julia.radius = 3;
	julia.iterations = 150;
	julia.mlx = mlx_init();
	julia.win = mlx_new_window(julia.mlx,  julia.width, julia.height, "Julia Set");
	julia.img = mlx_new_image(julia.mlx, julia.width, julia.height);
	julia.addr = mlx_get_data_addr(julia.img, &julia.bits_per_pixel, &julia.line_length,
			&julia.endian);
	juliaset(&julia);
	mlx_put_image_to_window(julia.mlx, julia.win, julia.img, 0, 0);
	mlx_key_hook(julia.win, key_hook, &julia);
	mlx_hook(julia.win, 17, 1L << 17, close_game, NULL);
	mlx_mouse_hook(julia.win, mouse_hook, &julia);
	mlx_loop(julia.mlx);
	return (0);
}

/*int	main(int argc, char **argv)
{
	t_data		img;
	t_julia		julia;

	julia.width = ft_atoi(argv[1]);
	julia.height = ft_atoi(argv[2]);
	julia.c.x = ft_atof(argv[3]);
	julia.c.y = ft_atof(argv[4]);
	julia.radius = ft_atof(argv[5]);
	julia.iterations = ft_atoi(argv[6]);
	julia.mlx.mlx = mlx_init();
	julia.mlx.win = mlx_new_window(julia.mlx.mlx, julia.width, julia.height, "Julia Set");
	img.img = mlx_new_image(julia.mlx.mlx, julia.width, julia.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	juliaset(&img, julia);
	mlx_put_image_to_window(julia.mlx.mlx, julia.mlx.win, img.img, 0, 0);
	mlx_key_hook(julia.mlx.win, key_hook, &img);
	mlx_hook(julia.mlx.win, 17, 1L << 17, close_game, NULL);
	mlx_mouse_hook(julia.mlx.win, mouse_hook, &img);
	mlx_loop(julia.mlx.mlx);
	return (0);
}*/