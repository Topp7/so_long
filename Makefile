# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stopp <stopp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:08:04 by stopp             #+#    #+#              #
#    Updated: 2024/03/22 19:11:16 by stopp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

LIBFTPRINTF = lib/libftprintf.a
LIBMLX = ./MLX42

HEADERS = -I ./mlx/include -I $(LIBMLX)/include
SRCS = main.c errors.c map_chk.c map_contents.c path_chk.c util_fncs.c render.c game_controls.c
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

all: libmlx $(NAME)

libmlx:
	@if [ ! -d "MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
	else \
		echo "Directory MLX42 already exists."; \
	fi
		@cd MLX42 && cmake -B build && cmake --build build -j4 \

$(NAME): $(OBJS)
	make -C lib
	$(CC) $(CFLAGS) $(LIBFTPRINTF) $(OBJS) $(LIBS) $(HEADER) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -f $(OBJS)
	rm -rf $(LIBMLX)/build
	make -C lib clean

fclean: clean
	rm -f $(NAME)
	make -C lib fclean
	rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re libmlx
