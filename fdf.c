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
#include "math.h"


int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	printf("sin cos test : %f %f %f %f\n", M_PI, sin(M_PI), cos(M_PI), sin(M_PI / 2));
	if (argc != 2)
		return (1);
	ft_parse(&map, *(argv + 1));
	printf("width height scale : %d %d %f\n", map.width, map.height, map.scale);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, VW, VH, "FdF");
	ft_image_init(&img, &mlx);
//	for (int i = 0; i < map.height; ++i)
//	{
//		for (int j = 0; j < map.width; ++j)
//		{
//			printf("%f %f %f\t", (*(*(map.map + i) + j)).vx, (*(*(map.map + i) + j)).vy, (*(*(map.map + i) + j)).vy);
//		}
//		printf("\n");
//	}
	printf("\n\n\n");
	ft_rotate_isometric(&map);
//	for (int i = 0; i < map.height; ++i)
//	{
//		for (int j = 0; j < map.width; ++j)
//		{
//			printf("%f %f %f\t", (*(*(map.map + i) + j)).vx, (*(*(map.map + i) + j)).vy, (*(*(map.map + i) + j)).vy);
//		}
//		printf("\n");
//	}
	ft_draw_map(&(t_param){&mlx, &img, &map});
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_key_hook(mlx.win_ptr, &ft_key_handler, &(t_param){&mlx, &img, &map});
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
