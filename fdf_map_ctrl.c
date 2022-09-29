/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:21:15 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/27 10:21:18 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (max_h < fabs((*(*(map->map + i) + j)).vz))
				max_h = fabs((*(*(map->map + i) + j)).vz);
			if (max_w < fabs((*(*(map->map + i) + j)).vx))
				max_w = fabs((*(*(map->map + i) + j)).vx);
		}
	}
	printf("%f %f", max_h, max_w);
	map->initial_scale = 0.96 * ft_min((VH / max_h / 2), (VW / max_w / 2));
	map->scale = map->initial_scale;
}

void	ft_init_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			(*(*(map->map + i) + j)).x = j - (map->width / 2);
			(*(*(map->map + i) + j)).y = i - (map->height / 2);
			(*(*(map->map + i) + j)).vx = (*(*(map->map + i) + j)).x;
			(*(*(map->map + i) + j)).vy = (*(*(map->map + i) + j)).y;
			(*(*(map->map + i) + j)).vz = (*(*(map->map + i) + j)).z;
		}
	}
	map->initial_scale = map->scale;
}
