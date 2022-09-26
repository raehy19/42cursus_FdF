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

int ft_key_press_handler(int keycode, void *param)
{
	if (keycode == KEYCODE_ESC)
		exit(0);
	else if (keycode == KEYCODE_C)
		mlx_clear_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win_ptr);
	return (0);
};

void	ft_draw_dot(t_img img, t_xy dot, t_argb color)
{
	if (img.endian == 0)
	{
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 0) = color.b;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 1) = color.g;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 2) = color.r;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 3) = color.a;
	}
	else if (img.endian == 1)
	{
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 0) = color.a;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 1) = color.r;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 2) = color.g;
		*(img.img_addr + (img.size_line * dot.y) + (4 * dot.x) + 3) = color.b;
	}
}

void	ft_trans(t_map *map, double angle)
{

}

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
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "FdF");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	img.img_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	printf("print map : \n");
	for (int i = 0; i < map.height; ++i)
	{
		for (int j = 0; j < map.width; ++j)
		{
//			ft_draw_dot(img, (t_xy){20 + j * 10, 20 + i * 10}, (t_argb){0, 255, 255, 255});
//			printf("%d\t", map.map[i][j]);
		}
		printf("\n");
	}
//	ft_draw_dot(img, (t_xy){100, 100}, (t_argb){0, 255, 255, 255});
//	ft_draw_dot(img, (t_xy){150, 150}, (t_argb){0, 255, 0, 0});
//	ft_draw_dot(img, (t_xy){100, 150}, (t_argb){0, 255, 255, 255});
//	ft_draw_dot(img, (t_xy){150, 100}, (t_argb){0, 0, 0, 255});

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);

	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &ft_key_press_handler, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
