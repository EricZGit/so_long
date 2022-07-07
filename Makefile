# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 06:10:28 by ezielins          #+#    #+#              #
#    Updated: 2022/07/07 18:14:18 by ezielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long

SRCS   = ./src/error.c \
		./src/gnl_map.c \
		./src/utils.c \
		./src/split.c \
		./src/images.c
		
LMLX  = -L minilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11 -lm -lz
MINI  = minilibx-linux

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

$(NAME): compile_lmlx $(OBJ_FILES)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAG) -o $(NAME) ./src/main.c $(OBJ_FILES) $(LMLX) $(FT_PRINTF_LIB)

compile_lmlx:
	@if [ ! -d $(MINI) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
		exit 1; \
	fi
	@make all -C minilibx-linux/
	
clean:
	$(MAKE) -C $(FT_PRINTF) clean
	@if [ -d $(MINI) ]; then \
		$(MAKE) -C $(MINI) clean; \
	fi
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) -C $(FT_PRINTF) fclean
	@if [ -d $(MINI) ]; then \
		$(MAKE) -C $(MINI) clean; \
	fi	
	$(RM) $(NAME)
	$(RM) -R $(MINI)

re: fclean
	@make all

.PHONY: all clean fclean compile_lmlx re
