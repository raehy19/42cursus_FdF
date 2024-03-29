/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:04:25 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:19 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "fdf_adjustment_value_bonus.h"
#include <math.h>

#define KEY_ESC 53

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14

#define KEYCODE_R 15
#define KEYCODE_C 8

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126

#define KEY_PLUS 24
#define KEY_MINUS 27

void	ft_scale_handler(int keycode, t_param *param)
{
	if (keycode == KEY_PLUS)
		param->map->scale *= ZOOM_IN_VALUE;
	else if (keycode == KEY_MINUS)
		param->map->scale *= ZOOM_OUT_VALUE;
	ft_img_reset(param->img, param->mlx);
	ft_draw_map(param, 0);
}

void	ft_rotate_handler(int keycode, t_param *param)
{
	if (keycode == KEY_A)
		ft_rotate_roll(param->map, -(M_PI / ROTATE_VALUE_RECIPROCAL));
	else if (keycode == KEY_D)
		ft_rotate_roll(param->map, (M_PI / ROTATE_VALUE_RECIPROCAL));
	else if (keycode == KEY_W)
		ft_rotate_pitch(param->map, (M_PI / ROTATE_VALUE_RECIPROCAL));
	else if (keycode == KEY_S)
		ft_rotate_pitch(param->map, -(M_PI / ROTATE_VALUE_RECIPROCAL));
	else if (keycode == KEY_Q)
		ft_rotate_yaw(param->map, -(M_PI / ROTATE_VALUE_RECIPROCAL));
	else if (keycode == KEY_E)
		ft_rotate_yaw(param->map, (M_PI / ROTATE_VALUE_RECIPROCAL));
	ft_img_reset(param->img, param->mlx);
	ft_draw_map(param, 0);
}

void	ft_move_handler(int keycode, t_param *param)
{
	if (keycode == KEY_RIGHT)
		ft_move_right(param->map);
	else if (keycode == KEY_LEFT)
		ft_move_left(param->map);
	else if (keycode == KEY_DOWN)
		ft_move_down(param->map);
	else if (keycode == KEY_UP)
		ft_move_up(param->map);
	ft_img_reset(param->img, param->mlx);
	ft_draw_map(param, 0);
}

void	ft_reset_change(int keycode, t_param *param)
{
	if (keycode == KEYCODE_R)
	{
		ft_coordinate_reset(param->map);
		param->map->scale = param->map->init_scale;
		ft_img_reset(param->img, param->mlx);
		ft_draw_map(param, 0);
	}
	else if (keycode == KEYCODE_C)
	{
		ft_img_reset(param->img, param->mlx);
		ft_draw_map(param, 1);
	}
}

int	ft_key_handler(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		ft_rotate_handler(keycode, param);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
		ft_move_handler(keycode, param);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		ft_scale_handler(keycode, param);
	else if (keycode == KEYCODE_R || keycode == KEYCODE_C)
		ft_reset_change(keycode, param);
	return (0);
}
