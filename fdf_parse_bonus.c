/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:17:41 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_free_line_and_words(char *line, char **words)
{
	int	i;

	if (line)
		free(line);
	if (words)
	{
		i = -1;
		while (*(words + (++i)))
		{
			free(*(words + i));
			*(words + i) = NULL;
		}
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
	while (*(words + (++i)))
	{
		free(*(words + i));
		*(words + i) = NULL;
	}
	free(words);
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
	map->row = ft_count_word_in_line(line);
	free(line);
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		if (ft_count_word_in_line(line) != map->row)
			exit (5);
		free(line);
		line = get_next_line(fd);
		++i;
	}
	map->col = i;
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
	while (++i < map->col)
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

void	ft_parse(t_map *map, char *filename)
{
	int	i;

	ft_width_height_check(map, filename);
	map->map = (t_data **) malloc(sizeof (t_data *) * map->col);
	if (!map->map)
		exit (4);
	i = -1;
	while (++i < map->col)
	{
		*(map->map + i) = (t_data *) malloc(sizeof(t_data) * map->row);
		if (!*(map->map + i))
			exit (4);
	}
	ft_read_line(map, filename);
}
