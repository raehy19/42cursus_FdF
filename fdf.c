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
#include <printf.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_argb
{
	char	a;
	char	r;
	char	g;
	char	b;
}	t_argb;


#define KEY_PRESS 2
#define BTN_PRESS 4

#define KEYCODE_ESC 53
#define KEYCODE_C 8

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

int	main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "FdF");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	img.img_addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);


	printf("\n\n%d %d %d", img.bits_per_pixel, img.size_line, img.endian);


	ft_draw_dot(img, (t_xy){100, 100}, (t_argb){0, 255, 255, 255});
	ft_draw_dot(img, (t_xy){150, 150}, (t_argb){0, 255, 0, 0});
	ft_draw_dot(img, (t_xy){100, 150}, (t_argb){0, 255, 255, 255});
	ft_draw_dot(img, (t_xy){150, 100}, (t_argb){0, 0, 0, 255});

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);


	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, &ft_key_press_handler, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
