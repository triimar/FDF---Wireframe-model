# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:04:13 by tmarts            #+#    #+#              #
#    Updated: 2023/02/12 22:59:16 by tmarts           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CFLAGS	= -w -Wunreachable-code -Ofast
# CFLAGS += -fsanitize=address -g3 -march=nocona -flto 
LIBMLX	= ./MLX42
LIBFT	= ./libft

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= -lglfw -L /Users/$(USER)/homebrew/Cellar/glfw/3.3.8/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
# SRCS	= $(shell find ./src -iname "*.c")
SRCS	= main.c \
initiate.c \
converter.c \
 map_utils.c \
map.c \
draw_line.c \
draw.c \
hooks.c 


OBJS	= ${SRCS:.c=.o}

# BOLD	= \033[1m
# BLACK	= \033[30;1m
# RED	= \033[31;1m
# GREEN	= \033[32;1m
# YELLOW	= \033[33;1m
# BLUE	= \033[34;1m
# MAGENTA	= \033[35;1m
# CYAN	= \033[36;1m
# WHITE	= \033[37;1m
# RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
