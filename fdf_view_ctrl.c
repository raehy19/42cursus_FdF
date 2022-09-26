/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:18:07 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/26 09:18:09 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_cal_scale(t_map *map)
{
	int	i;
	int	j;
	int	max_z;

	max_z = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (max_z < abs((*(*(map->map + i) + j)).z))
				max_z = abs((*(*(map->map + i) + j)).z);
		}
	}
	map->scale = (double)(VW + VH) / (double)(map->width + map->height + 3 * max_z);
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

void	ft_rotate_reset(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			(*(*(map->map + i) + j)).vx = (*(*(map->map + i) + j)).x;
			(*(*(map->map + i) + j)).vy = (*(*(map->map + i) + j)).y;
			(*(*(map->map + i) + j)).vz = (*(*(map->map + i) + j)).z;
		}
	}
}

void	ft_rotate_roll(t_map *map, double angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			(*(*(map->map + i) + j)).vx
				= ((*(*(map->map + i) + j)).vx) * cos(angle)
				- ((*(*(map->map + i) + j)).vy) * sin(angle);
			(*(*(map->map + i) + j)).vy
				= ((*(*(map->map + i) + j)).vy) * cos(angle)
				+ ((*(*(map->map + i) + j)).vx) * sin(angle);
		}
	}
}

void	ft_rotate_pitch(t_map *map, double angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			(*(*(map->map + i) + j)).vy
					= ((*(*(map->map + i) + j)).vy) * cos(angle)
					  + ((*(*(map->map + i) + j)).vz) * sin(angle);
			(*(*(map->map + i) + j)).vz
					= ((*(*(map->map + i) + j)).vz) * cos(angle)
					  - ((*(*(map->map + i) + j)).vy) * sin(angle);
		}
	}
}

void	ft_rotate_yaw(t_map *map, double angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			(*(*(map->map + i) + j)).vx
					= ((*(*(map->map + i) + j)).vx) * cos(angle)
					  - ((*(*(map->map + i) + j)).vz) * sin(angle);
			(*(*(map->map + i) + j)).vz
					= ((*(*(map->map + i) + j)).vz) * cos(angle)
					  + ((*(*(map->map + i) + j)).vx) * sin(angle);
		}
	}
}
