# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcos <marcos@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 20:04:27 by marcos            #+#    #+#              #
#    Updated: 2025/07/03 17:00:23 by marcos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LFLAGS =  -L./libft -lft -L./mini -lmlx -lXext -lX11 -lm

IFLAGS = -Imini -Ilibft -Ilibft/libftprintf -Ilibft/libftget_next_line

SRCS = main.c \
		free_memory.c \
		fractal_creation.c \
		fractal_events.c \
		fractal_render.c \
		fractal.c \
		math.c \
		input_parse.c \

OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft all
	@$(MAKE) -C ./mini all
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	@$(CC) -c $(IFLAGS) $(CFLAGS) $< 

clean:
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mini clean
	@rm -rf *.o

fclean: clean
	@$(MAKE) -C ./mini clean
	@$(MAKE) -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./mini re