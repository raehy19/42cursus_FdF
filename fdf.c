/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:37:18 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/20 07:37:21 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

#define KEY_PRESS 2
#define BTN_PRESS 4

#define KEYCODE_ESC 53
#define KEYCODE_C 8

int ft_key_press_handler(int keycode, void *param)
{
	if (keycode == KEYCODE_ESC)
		exit(0);
	else if (keycode == KEYCODE_C)
		mlx_clear_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
	return (0);
};

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "FdF");
	mlx_hook(mlx.win, KEY_PRESS, 0, &ft_key_press_handler, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
