# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:05:55 by fvieira           #+#    #+#              #
#    Updated: 2022/12/10 17:08:54 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a

SRC = ft_fractol.c \
	julia.c \
	complex_math.c \
	hooks.c \
	mandelbrot.c \
	params.c \
	burning.c \


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[1m LIBFT done \033[0m"
	$(MAKE) --no-print-directory -C ./minilibx-linux
	echo "\033[1m MiniLibX done \033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(NAME)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT:
