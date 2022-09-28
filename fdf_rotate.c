/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:18:07 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/27 11:51:47 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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
	ft_rotate_isometric(map);
}

void	ft_rotate_roll(t_map *map, double angle)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			tmp_x = (*(*(map->map + i) + j)).vx;
			tmp_y = (*(*(map->map + i) + j)).vy;
			(*(*(map->map + i) + j)).vx
					= tmp_x * cos(angle) - tmp_y * sin(angle);
			(*(*(map->map + i) + j)).vy
					= tmp_y * cos(angle) + tmp_x * sin(angle);
		}
	}
}

void	ft_rotate_pitch(t_map *map, double angle)
{
	int		i;
	int		j;
	double	tmp_y;
	double	tmp_z;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			tmp_y = (*(*(map->map + i) + j)).vy;
			tmp_z = (*(*(map->map + i) + j)).vz;
			(*(*(map->map + i) + j)).vy
					= tmp_y * cos(angle) - tmp_z * sin(angle);
			(*(*(map->map + i) + j)).vz
					= tmp_z * cos(angle) + tmp_y * sin(angle);
		}
	}
}

void	ft_rotate_yaw(t_map *map, double angle)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_z;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			tmp_x = (*(*(map->map + i) + j)).vx;
			tmp_z = (*(*(map->map + i) + j)).vz;
			(*(*(map->map + i) + j)).vx
					= tmp_x * cos(angle) - tmp_z * sin(angle);
			(*(*(map->map + i) + j)).vz
					= tmp_z * cos(angle) + tmp_x * sin(angle);
		}
	}
}

void	ft_rotate_isometric(t_map *map)
{
	ft_rotate_pitch(map, M_PI);
	ft_rotate_roll(map, -M_PI_4);
	ft_rotate_pitch(map, -atan(1 / sqrt(2)));
}
