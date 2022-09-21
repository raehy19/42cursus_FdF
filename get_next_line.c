/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_one_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:13:49 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/21 17:13:53 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 64

typedef struct s_data
{
	char	*str;
	ssize_t	size;
}	t_data;

void	ft_str_move(char *dst, char *src, ssize_t len)
{
	ssize_t	i;

	if (dst > src)
	{
		i = len;
		while (--i > -1)
			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
	}
	else
	{
		i = -1;
		while (++i < len)
			*(((unsigned char *) dst) + i) = *(((unsigned char *) src) + i);
	}
	return ;
}

int	ft_data_join(t_data *data, char *src, ssize_t len)
{
	char	*temp;

	if (len == 0)
		return (0);
	temp = (char *) malloc(sizeof(char) * (data->size + len + 1));
	if (!temp)
		return (-1);
	if (data->size > 0)
		ft_str_move(temp, data->str, data->size);
	if (len > 0)
		ft_str_move((temp + (data->size)), src, len);
	*(temp + data->size + len) = '\0';
	if (data->str)
		free(data->str);
	data->str = temp;
	data->size += len;
	return (0);
}

void	ft_check_remain(t_data *remain, t_data *buff, int fd)
{
	if (remain->size > 0)
	{
		ft_str_move(buff->str, remain->str, remain->size);
		buff->size = remain->size;
		free(remain->str);
		remain->str = NULL;
		remain->size = 0;
	}
	else
		buff->size = read(fd, buff->str, BUFFER_SIZE);
	return ;
}

int	ft_check_buff(t_data *buff, t_data *result, t_data *remain)
{
	ssize_t	i;

	i = 0;
	while (i < buff->size && *(buff->str + i) != '\n')
		++i;
	if (i < buff->size)
	{
		if (ft_data_join(remain, buff->str + i + 1, buff->size - i - 1))
			return (-1);
		if (ft_data_join(result, buff->str, i + 1))
		{
			if (result->str)
				free(result->str);
			result->str = NULL;
			return (-1);
		}
		return (1);
	}
	else
		if (ft_data_join(result, buff->str, buff->size))
			return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	remain;
	t_data			result;
	t_data			buff;

	if (fd < 0)
		return (NULL);
	result = (t_data){NULL, 0};
	buff.str = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buff.str)
		return (NULL);
	ft_check_remain(&remain, &buff, fd);
	while (buff.size > 0)
	{
		if (ft_check_buff(&buff, &result, &remain))
			break ;
		buff.size = read(fd, buff.str, BUFFER_SIZE);
	}
	free(buff.str);
	return (result.str);
}
