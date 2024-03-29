/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:50:54 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:32 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "fdf_adjustment_value_bonus.h"

void	ft_move_right(t_map *map)
{
	int	i;
	int	j;

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
	int	i;
	int	j;

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
	int	i;
	int	j;

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
	int	i;
	int	j;

	i = -1;
	while (++i < map->col)
	{
		j = -1;
		while (++j < map->row)
			(*(*(map->map + i) + j)).vz -= MOVE_VALUE / map->scale;
	}
}
