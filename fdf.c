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

#include "fdf.h"


int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	if (argc != 2)
		return (1);
	ft_parse(&map, *(argv + 1));

	printf("width height : %d %d\n",map.width, map.height);

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, VW, VH, "FdF");
	ft_image_init(&img, &mlx);

	printf("print map : \n");
	for (int i = 0; i < map.height; ++i)
	{
		for (int j = 0; j < map.width; ++j)
		{
//			ft_draw_dot(img, (t_xy){20 + j * 10, 20 + i * 10}, (t_argb){0, 255, 255, 255});
//			printf("%d\t", map.map[i][j]);
		}
//		printf("\n");
	}
//	ft_draw_dot(img, (t_xy){100, 100}, (t_argb){0, 255, 255, 255});
//	ft_draw_dot(img, (t_xy){150, 150}, (t_argb){0, 255, 0, 0});
//	ft_draw_dot(img, (t_xy){100, 150}, (t_argb){0, 255, 255, 255});
//	ft_draw_dot(img, (t_xy){150, 100}, (t_argb){0, 0, 0, 255});

	ft_draw_map(&(t_param){&mlx, &img, &map});
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);

	mlx_key_hook(mlx.win_ptr, &ft_key_handler, &(t_param) {&mlx, &img, &map});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
