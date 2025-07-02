# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcos <marcos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 20:04:27 by marcos            #+#    #+#              #
#    Updated: 2025/07/02 20:22:45 by marcos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LFLAGS =  -L./libft -lft -L./minilibx -lmlx -lXext -lX11 -lm

IFLAGS = -Iminilibx -Ilibft -Ilibft/libftprintf -Ilibft/libftget_next_line

SRCS = main.c \
		free_memory.c \
		fractol_creation.c \
		fractol_events.c \
		fractal.c \
		math.c \
		mandelbrot.c \

OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./minilibx all
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	@$(CC) -c $(IFLAGS) $(CFLAGS) $< 

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./minilibx clean
	@rm -rf *.o

fclean: clean
	@$(MAKE) -C ./minilibx clean
	@$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./minilibx re