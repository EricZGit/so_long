# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezielins <ezielins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 06:10:28 by ezielins          #+#    #+#              #
#    Updated: 2022/07/26 20:44:51 by ezielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long
NAME_BONUS = so_long_bonus

SRCS   = ./src/error.c \
		./src/gnl_map.c \
		./src/utils.c \
		./src/split.c \
		./src/images.c \
		./src/keys.c \
		./src/screen.c

SRCS_BONUS = ./src_bonus/error_bonus.c \
			./src_bonus/gnl_map_bonus.c \
			./src_bonus/utils_bonus.c \
			./src_bonus/split_bonus.c \
			./src_bonus/images_bonus.c \
			./src_bonus/images_two_bonus.c \
			./src_bonus/utils_three_bonus.c \
			./src_bonus/keys_bonus.c \
			./src_bonus/utils_two_bonus.c \
			./src_bonus/screen_bonus.c \
			./src_bonus/screen_two_bonus.c \
			./src_bonus/score_bonus.c 
					
LMLX  = -L minilibx-linux -lmlx_Linux -I minilibx-linux -lXext -lX11 -lm -lz
CFLAG = -Wall -Wextra -Werror
RM    = rm -f
CC    = gcc

OBJS  =$(SRCS:.c=.o)
OBJS_BONUS  =$(SRCS_BONUS:.c=.o)

FT_PRINTF     = ./inc/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF)libftprintf.a

OBJ_FILES = $(OBJS)
OBJ_FILES_BONUS = $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAG) -o $(NAME) ./src/main.c $(OBJ_FILES) $(LMLX) $(FT_PRINTF_LIB)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_FILES_BONUS)
	$(MAKE) -C $(FT_PRINTF)
	$(CC) $(CFLAG) -o $(NAME_BONUS) ./src_bonus/main_bonus.c $(OBJ_FILES_BONUS) $(LMLX) $(FT_PRINTF_LIB)

clean:
	$(MAKE) -C $(FT_PRINTF) clean
	rm -f $(OBJS)

clean_bonus:
	$(MAKE) -C $(FT_PRINTF) clean
	rm -f $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF) fclean
	rm -f $(NAME)

fclean_bonus: clean_bonus
	$(MAKE) -C $(FT_PRINTF) fclean
	rm -f $(NAME_BONUS)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean clean_bonus fclean_bonus bonus re
