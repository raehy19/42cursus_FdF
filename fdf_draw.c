/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:04:16 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/26 13:04:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void	ft_draw_dot(t_img *img, t_xy dot, t_argb color)
{
	if (dot.x < 0 || dot.x >= VW || dot.y < 0 || dot.y >= VH)
		return ;
	if (img->endian == 0)
	{
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 0) = color.b;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 1) = color.g;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 2) = color.r;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 3) = color.a;
	}
	else if (img->endian == 1)
	{
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 0) = color.a;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 1) = color.r;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 2) = color.g;
		*(img->img_addr + (img->size_line * dot.y) + (4 * dot.x) + 3) = color.b;
	}
}

void	ft_draw_line()
{

}

t_argb	ft_cal_color(int z)
{
	if (z < -255 || z > 255)
		return ((t_argb) {0, 0, 0, 0});
	if (z < -127)
		return ((t_argb) {0, 0, 255 - 2 * ((-z) - 128), 255});
	else if (z < 0)
		return ((t_argb) {0, 255 - 2 * (-z), 255, 255});
	else if (z < 128)
		return ((t_argb) {0, 255, 255, 255 - 2 * z});
	else
		return ((t_argb) {0, 255, 255 - 2 * (z - 128), 0});
}


void	ft_draw_map(t_param *param)
{
	int		i;
	int		j;

	i = -1;
	while (++i < param->map->col)
	{
		j = -1;
		while (++j < param->map->row)
			ft_draw_dot(param->img,
				(t_xy){round(VW / 2
					+ param->map->scale * (*(param->map->map + i) + j)->vx),
				round(VH / 2
					+ param->map->scale * (*(param->map->map + i) + j)->vz)},
			ft_cal_color((*(param->map->map + i) + j)->z * 255 / param->map->max_z));
	}
	ft_put_image(param->img, param->mlx);
}
