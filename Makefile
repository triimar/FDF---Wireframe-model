# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:04:13 by tmarts            #+#    #+#              #
#    Updated: 2023/03/08 13:22:34 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror 
# CFLAGS += -fsanitize=address -g3
LDFLAGS = -lm
# LDFLAGS += -fsanitize=address -g3
LIBMLX	= ./MLX42
LIBFT	= ./libft
HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42 -I $(LIBFT)
LIBS	= -lglfw -L /Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a 
SRC_DIR = ./src/
SRCS	= $(addprefix $(SRC_DIR)/, \
main.c \
initiate.c \
2d_converters.c \
color.c \
rotations.c \
fdf_utils.c \
map.c \
draw_line.c \
draw.c \
hooks.c)

OBJS	= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

bonus: all

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) ${LDFLAGS}

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
