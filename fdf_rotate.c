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
					- ((*(*(map->map + i) + j)).vz) * sin(angle);
			(*(*(map->map + i) + j)).vz
					= ((*(*(map->map + i) + j)).vz) * cos(angle)
					+ ((*(*(map->map + i) + j)).vy) * sin(angle);
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

void	ft_rotate_isometric(t_map *map)
{
	ft_rotate_roll(map, 0);
//	ft_rotate_roll(map, M_PI_4);
//	ft_rotate_roll(map, M_PI / 4);
//	ft_rotate_pitch(map, atan(1 / sqrt(2)));
	printf("%f\n", atan(1 / sqrt(2)));
	printf("%f\n", 35.264 * M_PI / 180);
}
