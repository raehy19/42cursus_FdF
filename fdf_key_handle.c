/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 2rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:04:25 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/26 10:04:27 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

#define KEY_ESC 53

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14

#define KEYCODE_R 15

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126

void	ft_reset(t_param *param)
{
	ft_rotate_reset(param->map);
	ft_image_reset(param->img, param->mlx);
	ft_draw_map(param);
}

void	ft_rotate_handler(int keycode, t_param *param)
{
	if (keycode == KEY_A)
		ft_rotate_roll(param->map, M_PI / 12);
	else if (keycode == KEY_D)
		ft_rotate_roll(param->map, -M_PI / 12);
	else if (keycode == KEY_W)
		ft_rotate_pitch(param->map, M_PI / 12);
	else if (keycode == KEY_S)
		ft_rotate_pitch(param->map, -M_PI / 12);
	else if (keycode == KEY_Q)
		ft_rotate_yaw(param->map, M_PI / 12);
	else if (keycode == KEY_E)
		ft_rotate_yaw(param->map, -M_PI / 12);
	ft_image_reset(param->img, param->mlx);
	ft_draw_map(param);
}

void	ft_move_handler(int keycode, void *param)
{
	if (keycode)
		return;
	if (param)
		return;
}

int ft_key_handler(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		ft_rotate_handler(keycode, param);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
		ft_move_handler(keycode, param);
	else if (keycode == KEYCODE_R)
		ft_reset(param);
	return (0);
};
