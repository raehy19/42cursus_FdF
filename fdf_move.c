/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:50:54 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/27 11:50:57 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MOVE_VALUE 20

void	ft_move_right(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			(*(*(map->map + i) + j)).vx += MOVE_VALUE / map->scale;
	}
}

void	ft_move_left(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			(*(*(map->map + i) + j)).vx -= MOVE_VALUE / map->scale;
	}
}

void	ft_move_down(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			(*(*(map->map + i) + j)).vz += MOVE_VALUE / map->scale;
	}
}

void	ft_move_up(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			(*(*(map->map + i) + j)).vz -= MOVE_VALUE / map->scale;
	}
}
