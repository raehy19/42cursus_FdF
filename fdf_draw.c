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

t_argb	*ft_cal_color(int z, int max_z)
{
	z = z * 255 /max_z;
	if (z < -255 || z > 255)
		return (&(t_argb) {0, 0, 0, 0});
	if (z < -127)
		return (&(t_argb) {0, 0, 255 - 2 * ((-z) - 128), 255});
	else if (z < 0)
		return (&(t_argb) {0, 255 - 2 * (-z), 255, 255});
	else if (z < 128)
		return (&(t_argb) {0, 255, 255, 255 - 2 * z});
	else
		return (&(t_argb) {0, 255, 255 - 2 * (z - 128), 0});
}

void	ft_draw_dot(t_img *img, t_xy *dot, t_argb *color)
{
	if (dot->x < 0 || dot->x >= VW || dot->y < 0 || dot->y >= VH)
		return ;
	if (img->endian == 0)
	{
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 0) = color->b;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 1) = color->g;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 2) = color->r;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 3) = color->a;
	}
	else if (img->endian == 1)
	{
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 0) = color->a;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 1) = color->r;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 2) = color->g;
		*(img->img_adr + (img->width * dot->y) + (4 * dot->x) + 3) = color->b;
	}
}

t_xy	ft_cal_discriminant(t_xyz start, t_xyz end)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (start.x > end.x)
		x = -1;
	if (start.y > end.y)
		y = -1;
	return ((t_xy){x, y});
}

void	ft_draw_line_low(t_xyz start, t_xyz end, t_img *img, int max_z)
{
	int		width;
	int		height;
	t_xy	increment_xy;
	int		discriminant;
	int		i;

	width = abs(start.x - end.x);
	height = abs(start.y - end.y);
	increment_xy = ft_cal_discriminant(start, end);
	discriminant = 2 * height - width;
	i = -1;
	while (++i < width)
	{
		if (discriminant < 0)
			discriminant += 2 * width;
		else
		{
			start.y += increment_xy.y;
			discriminant += 2 * width - 2 * height;
		}
		ft_draw_dot(img, &(t_xy){start.x, start.y},
			ft_cal_color(round(start.z + i * (end.z - start.z) / (double)width), max_z));
		start.x += increment_xy.x;
	}
}

void	ft_select_line(t_xyz start, t_xyz end, t_img *img, int max_z)
{
	if (abs(start.x - end.x) < abs(start.y - end.y))
		ft_draw_line_low(start, end, img, max_z);
	else
		ft_draw_line_low(start, end, img, max_z);
}

void	ft_draw_line_map(t_map *map, t_img *img, t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i + 1 < map->col)
	{
		j = -1;
		while (++j + 1 < map->row)
//			ft_select_line();
			;
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
				&(t_xy){round(VW / 2
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

	if (change_type)
	{
		if (draw_type == 0)
			draw_type = 1;
		else if (draw_type == 1)
			draw_type = 0;
	}
	printf("draw type : %d\n", draw_type);
	if (draw_type == 0)
		ft_draw_line_map(param->map, param->img, param->mlx);
	else if (draw_type == 1)
		ft_draw_dot_map(param->map, param->img, param->mlx);
}
