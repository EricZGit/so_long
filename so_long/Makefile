# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 06:10:28 by ezielins          #+#    #+#              #
#    Updated: 2022/07/07 19:46:51 by ezielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long

SRCS   = ./src/error.c \
		./src/gnl_map.c \
		./src/utils.c \
		./src/split.c \
		./src/images.c \
		./src/put_image.c \
		./src/keys.c
		
LMLX  = -L minilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11 -lm -lz
CFLAG = -Wall -Wextra -Werror
RM    = rm -f
CC    = gcc

OBJS  =$(SRCS:.c=.o)

HEADER        = -I inc/
FT_PRINTF     = ./inc/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF)libftprintf.a

OBJ_FILES = $(OBJS)

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAG) -o $(NAME) ./src/main.c $(OBJ_FILES) $(LMLX) $(FT_PRINTF_LIB)

clean:
	$(MAKE) -C $(FT_PRINTF) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
