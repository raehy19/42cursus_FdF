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

t_argb	ft_cal_color(double z, int max_z)
{
	if (max_z)
		z = z * 255 / max_z;
	if (z < -255 || z > 255)
		return ((t_argb) {0, 0, 0, 0});
	if (z < -127)
		return ((t_argb) {0, 255, 255 - 2 * ((-z) - 128), 0});
	else if (z < 0)
		return ((t_argb) {0, 255, 255, 255 - 2 * (-z)});
	else if (z < 128)
		return ((t_argb) {0, 255 - 2 * (z), 255, 255});
	else
		return ((t_argb) {0, 0, 255 - 2 * ((z) - 128), 255});
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
	int		h;
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
			ft_cal_color((st->z + (i * (en->z - st->z)) / (double)h),
				 max_z));
		st->y += increment_xy->y;
	}
	free(increment_xy);
}
void	ft_draw_line_low(t_xyz *st, t_xyz *en, t_img *img, int max_z)
{
	int		w;
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
			ft_cal_color((st->z + (i * (en->z - st->z)) / (double)w),
				 max_z));
		st->x += increment_xy->x;
	}
	free(increment_xy);
}

void	ft_draw_line(t_xyz *st, t_xyz *en, t_img *img, int max_z)
{
	if (abs(st->x - en->x) < abs(st->y - en->y))
		ft_draw_line_high(st, en, img, max_z);
	else
		ft_draw_line_low(st, en, img, max_z);
	free(st);
	free(en);
}

t_xyz	*ft_xyz(t_data *data, double scale)
{
	t_xyz	*xyz;

	xyz = malloc(sizeof(t_xyz));
	xyz->x = round(VW / 2 + scale * data->vx);
	xyz->y = round(VH / 2 + scale * data->vz);
	xyz->z = data->z;
	return (xyz);
}

void	ft_draw_line_map(t_map *map, t_img *img, t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
		{
			if (i + 1 < map->col)
				ft_draw_line(ft_xyz(*(map->map + i) + j, map->scale),
							 ft_xyz(*(map->map + i + 1) + j, map->scale), img, map->max_z);
			if (j + 1 < map->row)
				ft_draw_line(ft_xyz(*(map->map + i) + j, map->scale),
					ft_xyz(*(map->map + i) + j + 1, map->scale), img, map->max_z);
		}
	}
	ft_put_image(img, mlx);
}

void	ft_draw_dot_map(t_map *map, t_img *img, t_mlx *mlx)
{
	int		i;
	int		j;

	printf("print dot map\n");
	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			ft_draw_dot(img,
				(t_xy){round(VW / 2
					+ map->scale * (*(map->map + i) + j)->vx),
				round(VH / 2
					+ map->scale * (*(map->map + i) + j)->vz)},
			ft_cal_color((*(map->map + i) + j)->z, map->max_z));
	}
	ft_put_image(img, mlx);
}

void	ft_draw_map(t_param *param, int change_type)
{
	static int	draw_type;

	printf("draw map\n");
	if (change_type)
	{
		if (draw_type == 0)
			draw_type = 1;
		else if (draw_type == 1)
			draw_type = 0;
	}
	if (draw_type == 0)
		ft_draw_line_map(param->map, param->img, param->mlx);
	else if (draw_type == 1)
		ft_draw_dot_map(param->map, param->img, param->mlx);
}
