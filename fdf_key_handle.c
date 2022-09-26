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

#define KEY_ESC 53
#define KEY_C 8

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


int ft_key_handler(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_C)
		mlx_clear_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win_ptr);

	return (0);
};
