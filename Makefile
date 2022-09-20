# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 07:37:02 by rjeong            #+#    #+#              #
#    Updated: 2022/09/20 07:37:06 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
BONUS_NAME := fdf_bonus
MLX_LIB_NAME := libmlx.dylib
MLX_LIB_DIR := mlx

CC := cc
CFLAGS := -Wall -Wextra -Werror -Imlx
RM := rm -f

FDF_SRCS := \
	fdf.c \

FDF_SRCS_BONUS := \

FDF_OBJS := $(FDF_SRCS:.c=.o)

FDF_OBJS_BONUS := $(FDF_SRCS_BONUS:.c=.o)

all : $(NAME)

clean :
	make -C $(MLX_LIB_DIR) clean
	$(RM) $(MLX_LIB_NAME)
	$(RM) $(FDF_OBJS)
	$(RM) $(FDF_OBJS_BONUS)

fclean : clean
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

bonus : $(BONUS_NAME)

$(NAME) : $(MLX_LIB_NAME) $(FDF_OBJS)
	$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(BONUS_NAME) : $(FDF_OBJS_BONUS)

$(MLX_LIB_NAME) :
	make -C $(MLX_LIB_DIR) all
	cp ./mlx/$(MLX_LIB_NAME) ./$(MLX_LIB_NAME)

run : $(NAME)
	./$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

.PHONY : all bonus clean fclean re

