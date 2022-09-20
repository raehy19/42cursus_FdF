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
CC := cc
CFLAGS := -Wall -Wextra -Werror -Imlx
LIB_INCLUDE_FLAG := -L ./minilibx_mms_20191025_beta
RM := rm -f

FDF_SRCS := \
	fdf.c \

FDF_SRCS_BONUS := \

FDF_OBJS := $(FDF_SRCS:.c=.o)

FDF_OBJS_BONUS := $(FDF_SRCS_BONUS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(FDF_OBJS)
	$(RM) $(FDF_OBJS_BONUS)

fclean : clean
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

bonus : $(BONUS_NAME)

$(NAME) : $(FDF_OBJS)
	$(CC) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(BONUS_NAME) : $(FDF_OBJS_BONUS)

run : $(NAME)
	./$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

.PHONY : all bonus clean fclean re

