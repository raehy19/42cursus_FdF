/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:17:41 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/22 14:17:43 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_line_and_words(char *line, char **words)
{
	int	i;

	if (line)
		free(line);
	i = -1;
	if (words)
	{
		while (*(words + (++i)))
			free(*(words + i));
		free(words);
	}
}

int	ft_count_word_in_line(char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, " \n");
	if (!words)
		exit (4);
	i = -1;
	while (*(words + (++i)) != NULL)
		free(*(words + i));
	return (i);
}

void	ft_width_height_check(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		exit (2);
	line = get_next_line(fd);
	map->width = ft_count_word_in_line(line);
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		if (ft_count_word_in_line(line) != map->width)
			exit (5);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	map->height = i;
	close(fd);
	close(fd);
}

void	ft_read_line(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	**words;
	int		i;
	int		j;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		exit (2);
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		words = ft_split(line, " \n");
		j = -1;
		while (*(words + (++j)) != NULL)
			(*(*(map->map + i) + j)).z = ft_atoi(*(words + j));
		ft_free_line_and_words(line, words);
	}
	close(fd);
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
			(*(*(map->map + i) + j)).x = j;
			(*(*(map->map + i) + j)).y = i;
			(*(*(map->map + i) + j)).view_x = j;
			(*(*(map->map + i) + j)).view_y = i;
			(*(*(map->map + i) + j)).view_z = (*(*(map->map + i) + j)).z;
		}
	}
}

void	ft_parse(t_map *map, char *filename)
{
	int	i;

	ft_width_height_check(map, filename);
	map->map = (int **) malloc(sizeof (int *) * map->height);
	if (!map->map)
		exit (4);
	i = -1;
	while (++i < map->height)
	{
		*(map->map + i) = (int *) malloc(sizeof(int) * map->width);
		if (!*(map->map + i))
			exit (4);
	}
	ft_read_line(map, filename);
	ft_init_map(map);
}
