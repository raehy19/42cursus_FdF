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

int	ft_free_line_and_words(char *line, char **words, int flag)
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
	return (flag);
}

int	ft_count_word_in_line(char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (ft_free_line_and_words(line, words, -1));
	i = -1;
	while (*(words + (++i)) != NULL)
		free(*(words + i));
	return (i);
}

int	ft_width_height_check(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	map->width = ft_count_word_in_line(line);
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		if (ft_count_word_in_line(line) != map->width)
			return (ft_free_line_and_words(line, NULL, -1));
		free(line);
		line = get_next_line(fd);
		++i;
	}
	map->height = i;
	close(fd);
	return (0);
}

int	ft_read_line(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	char	**words;
	int		i;
	int		j;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (-1);
	i = -1;
	while (++i < map->height)
	{
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		j = -1;
		while (*(words + (++j)) != NULL)
		{
			if (!ft_isdigit(*(*(words + j))))
				return (ft_free_line_and_words(line, words, -1));
			*(*(map->map + i) + j) = ft_atoi(*(words + j));
		}
		ft_free_line_and_words(line, words, 0);
	}
	close(fd);
	return (0);
}

int	ft_parse(t_map *map, char *filename)
{
	int	i;

	if (ft_width_height_check(map, filename) < 0)
		return (-1);
	map->map = (int **) malloc(sizeof (int *) * map->height);
	if (!map->map)
		return (-1);
	i = -1;
	while (++i < map->height)
	{
		*(map->map + i) = (int *) malloc(sizeof(int) * map->width);
		if (!*(map->map + i))
			return (-1);
	}
	if (ft_read_line(map, filename) < 0)
		return (-1);
	return (0);
}
