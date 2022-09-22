# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 14:55:50 by rjeong            #+#    #+#              #
#    Updated: 2022/08/03 14:55:52 by rjeong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
AR := ar
ARFLAG := crs

LIBFT_SRCS := \
	ft_atoi.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_split.c \
	get_next_line.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT_OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(LIBFT_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re

