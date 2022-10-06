/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:12:56 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:09 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_argb	ft_cal_color(double z, int max_z)
{
	if (max_z)
		z = z * 255 / max_z;
	if (z < -255 || z > 255)
		return ((t_argb){0, 0, 0, 0});
	if (z < -127)
		return ((t_argb){0, 255, 255 - 2 * ((-z) - 128), 0});
	else if (z < 0)
		return ((t_argb){0, 255, 255, 255 - 2 * (-z)});
	else if (z < 128)
		return ((t_argb){0, 255 - 2 * (z), 255, 255});
	else
		return ((t_argb){0, 0, 255 - 2 * ((z) - 128), 255});
}

void	ft_draw_dot(t_img *img, t_xy dot, t_argb color)
{
	if (dot.x < 0 || dot.x >= VW || dot.y < 0 || dot.y >= VH)
		return ;
	if (img->endian == 0)
	{
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 0) = color.b;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 1) = color.g;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 2) = color.r;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 3) = color.a;
	}
	else if (img->endian == 1)
	{
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 0) = color.a;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 1) = color.r;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 2) = color.g;
		*(img->img_adr + (img->width * dot.y) + (4 * dot.x) + 3) = color.b;
	}
}

t_xy	*ft_cal_increment(t_xyz *start, t_xyz *end)
{
	t_xy	*xy;

	xy = malloc(sizeof(t_xy));
	xy->x = 1;
	xy->y = 1;
	if (start->x > end->x)
		xy->x = -1;
	if (start->y > end->y)
		xy->y = -1;
	return (xy);
}

void	ft_draw_line_high(t_xyz *st, t_xyz *en, t_img *img, int max_z)
{
	int		w;
	double	h;
	t_xy	*increment_xy;
	int		discriminant;
	int		i;

	w = abs(st->x - en->x);
	h = abs(st->y - en->y);
	increment_xy = ft_cal_increment(st, en);
	discriminant = 2 * w - h;
	i = -1;
	while (++i < h)
	{
		if (discriminant < 0)
			discriminant += 2 * w;
		else
		{
			st->x += increment_xy->x;
			discriminant += (2 * w - 2 * h);
		}
		ft_draw_dot(img, (t_xy){st->x, st->y},
			ft_cal_color((st->z + (i * (en->z - st->z)) / h), max_z));
		st->y += increment_xy->y;
	}
	free(increment_xy);
}

void	ft_draw_line_low(t_xyz *st, t_xyz *en, t_img *img, int max_z)
{
	double	w;
	int		h;
	t_xy	*increment_xy;
	int		discriminant;
	int		i;

	w = abs(st->x - en->x);
	h = abs(st->y - en->y);
	increment_xy = ft_cal_increment(st, en);
	discriminant = 2 * h - w;
	i = -1;
	while (++i < w)
	{
		if (discriminant < 0)
			discriminant += 2 * h;
		else
		{
			st->y += increment_xy->y;
			discriminant += (2 * h - 2 * w);
		}
		ft_draw_dot(img, (t_xy){st->x, st->y},
			ft_cal_color((st->z + (i * (en->z - st->z)) / w), max_z));
		st->x += increment_xy->x;
	}
	free(increment_xy);
}
