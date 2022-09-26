/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:46 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/21 17:36:48 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "printf.h"
# include "./libft/libft.h"


typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_argb
{
	char	a;
	char	r;
	char	g;
	char	b;
}	t_argb;

typedef struct s_data
{
	int		x;
	int		y;
	int		z;
	double	vx;
	double	vy;
	double	vz;
}	t_data;

typedef struct s_map
{
	int		width;
	int		height;
	t_data	**map;
}	t_map;

typedef struct s_param
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;
}	t_param;

void	ft_parse(t_map *map, char *filename);
void	ft_init_map(t_map *map);

int ft_key_handler(int keycode, void *param);


#endif
