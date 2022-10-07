/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 07:37:18 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:41:50 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_adjustment_value.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	if (argc != 2)
		return (1);
	ft_parse(&map, *(argv + 1));
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, VW, VH, "FdF");
	ft_img_init(&img, &mlx);
	ft_init_map(&map);
	ft_draw_map(&(t_param){&mlx, &img, &map}, 0);
	mlx_key_hook(mlx.win_ptr, &ft_key_handler, &(t_param){&mlx, &img, &map});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
