/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:04:16 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:41:58 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

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
					ft_xyz(*(map->map + i + 1) + j, map->scale),
					img, map->max_z);
			if (j + 1 < map->row)
				ft_draw_line(ft_xyz(*(map->map + i) + j, map->scale),
					ft_xyz(*(map->map + i) + j + 1, map->scale),
					img, map->max_z);
		}
	}
	ft_put_image(img, mlx);
}

void	ft_draw_dot_map(t_map *map, t_img *img, t_mlx *mlx)
{
	int		i;
	int		j;

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
