/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:13 by rjeong            #+#    #+#             */
/*   Updated: 2022/07/14 20:58:55 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = -1;
	while (*(sep + (++i)))
		if (c == *(sep + i))
			return (1);
	return (0);
}

size_t	ft_count_word(const char *s, char *sep)
{
	size_t	i;
	size_t	cnt;

	if (!(*s))
		return (0);
	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		while (*(s + i) && ft_is_sep(*(s + i), sep))
			++i;
		if (!(*(s + i)))
			break ;
		++cnt;
		while (*(s + i) && !ft_is_sep(*(s + i), sep))
			++i;
	}
	return (cnt);
}

char	*ft_split_dup(const char *s, char *sep, size_t *i)
{
	char	*temp;
	int		word_size;

	word_size = 0;
	while (ft_is_sep(*(s + (*i)), sep))
		++(*i);
	while (*(s + (*i) + word_size) && !ft_is_sep(*(s + (*i) + word_size), sep))
		++word_size;
	temp = (char *) malloc(sizeof(char) * (word_size + 1));
	if (!(temp))
		exit(4);
	ft_memmove(temp, s + (*i), word_size);
	*(temp + word_size) = '\0';
	(*i) += word_size;
	return (temp);
}

char	**ft_split(char const *s, char *sep)
{
	char	**dst;
	size_t	word_total;
	size_t	word_i;
	size_t	i;

	word_total = ft_count_word(s, sep);
	dst = (char **) malloc(sizeof(char *) * (word_total + 1));
	if (!dst)
		exit(4);
	word_i = 0;
	i = 0;
	while (word_i < word_total)
	{
		*(dst + word_i) = ft_split_dup(s, sep, &i);
		if (!(*(dst + word_i)))
			exit(4);
		++word_i;
	}
	*(dst + word_total) = NULL;
	return (dst);
}
