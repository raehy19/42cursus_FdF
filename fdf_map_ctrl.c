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

void	ft_cal_scale(t_map *map)
{
	int		i;
	int		j;
	double	max_z;

	max_z = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (max_z < fabs((*(*(map->map + i) + j)).vz))
				max_z = fabs((*(*(map->map + i) + j)).vz);
		}
	}
	map->scale = (VW + VH) / (map->width + map->height + 3 * max_z);
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
	ft_cal_scale(map);
}
