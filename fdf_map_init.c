/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:21:15 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:26 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_adjustment_value.h"
#include <math.h>

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_cal_scale(t_map *map)
{
	int		i;
	int		j;
	double	max_h;
	double	max_w;

	max_h = 0;
	max_w = 0;
	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
		{
			max_h = ft_max(max_h, fabs((*(*(map->map + i) + j)).vz));
			max_w = ft_max(max_w, fabs((*(*(map->map + i) + j)).vx));
		}
	}
	map->init_scale = VIEW_SCALE * ft_min((VH / max_h / 2), (VW / max_w / 2));
	map->scale = map->init_scale;
}

void	ft_cal_max_min_z(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->max_z = 0;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
		{
			if (abs((*(*(map->map + i) + j)).z) > map->max_z)
				map->max_z = (*(*(map->map + i) + j)).z;
		}
	}
}

void	ft_init_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
		{
			(*(*(map->map + i) + j)).x = j - (map->row / 2);
			(*(*(map->map + i) + j)).y = i - (map->col / 2);
			(*(*(map->map + i) + j)).vx = (*(*(map->map + i) + j)).x;
			(*(*(map->map + i) + j)).vy = (*(*(map->map + i) + j)).y;
			(*(*(map->map + i) + j)).vz = (*(*(map->map + i) + j)).z;
		}
	}
	ft_rotate_isometric(map);
	ft_cal_scale(map);
	ft_cal_max_min_z(map);
}
