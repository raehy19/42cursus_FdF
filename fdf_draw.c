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

void	ft_draw_map(t_param *param)
{
	int		i;
	int		j;
	t_argb	color;

	color = (t_argb){0, 255, 255, 255};
	i = -1;
	while (++i < param->map->height)
	{
		j = -1;
		while (++j < param->map->width)
			ft_draw_dot(param->img,
				(t_xy){round(VW / 2
					+ param->map->scale * (*(param->map->map + i) + j)->vx),
				round(VH / 2
					- param->map->scale * (*(param->map->map + i) + j)->vz)},
				color);
	}
	ft_put_image(param->img, param->mlx);
}
