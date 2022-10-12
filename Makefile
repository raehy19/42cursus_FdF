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

LIBFT := ./libft/libft.a
LIBFT_DIR := libft

MLX_LIB_NAME := libmlx.dylib
MLX_LIB_DIR := mlx

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP -Imlx -g
RM := rm -f

FDF_SRCS := \
	fdf.c \
	fdf_parse.c \
	fdf_img_ctrl.c \
	fdf_map_init.c \
	fdf_key_handle.c \
	fdf_draw.c \
	fdf_draw_utils.c \
	fdf_rotate.c \
	fdf_move.c \

FDF_SRCS_BONUS := \
	fdf_bonus.c \
	fdf_parse_bonus.c \
	fdf_img_ctrl_bonus.c \
	fdf_map_init_bonus.c \
	fdf_key_handle_bonus.c \
	fdf_draw_bonus.c \
	fdf_draw_utils_bonus.c \
	fdf_rotate_bonus.c \
	fdf_move_bonus.c \

all : $(NAME)

bonus : $(BONUS_NAME)

FDF_OBJS := $(FDF_SRCS:.c=.o)

FDF_OBJS_BONUS := $(FDF_SRCS_BONUS:.c=.o)

FDF_DEPS := $(FDF_SRCS:.c=.d)

FDF_DEPS_BONUS := $(FDF_SRCS_BONUS:.c=.d)

clean :
	make -C $(MLX_LIB_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(MLX_LIB_NAME)
	$(RM) $(FDF_OBJS)
	$(RM) $(FDF_OBJS_BONUS)
	$(RM) $(FDF_DEPS)
	$(RM) $(FDF_DEPS_BONUS)

fclean : clean
	$(RM) $(LIBFT)
	$(RM) $(BONUS_NAME)
	$(RM) $(NAME)

re : fclean
	make all

-include $(FDF_DEPS) $(FDF_DEPS_BONUS)

$(LIBFT) :
	make -C $(LIBFT_DIR) all

$(NAME) : $(LIBFT) $(MLX_LIB_NAME) $(FDF_OBJS)
	$(CC) $^ -L$(LIBFT_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(BONUS_NAME) : $(LIBFT) $(MLX_LIB_NAME) $(FDF_OBJS_BONUS)
	$(CC) $^ -L$(LIBFT_DIR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	cp $(BONUS_NAME) ./$(NAME)

$(MLX_LIB_NAME) :
	make -C $(MLX_LIB_DIR) all
	cp ./mlx/$(MLX_LIB_NAME) ./$(MLX_LIB_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

.PHONY : all bonus clean fclean re
