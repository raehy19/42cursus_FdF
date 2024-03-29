/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:46 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:43:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "./libft/libft.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_adr;
	int		bits_per_pixel;
	int		width;
	int		endian;
}	t_img;

typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_xyz
{
	int	x;
	int	y;
	int	z;
}	t_xyz;

typedef struct s_argb
{
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
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
	int		row;
	int		col;
	double	scale;
	double	init_scale;
	int		max_z;
	t_data	**map;
}	t_map;

typedef struct s_param
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;
}	t_param;

void	ft_parse(t_map *map, char *filename);

void	ft_img_reset(t_img *img, t_mlx *mlx);
void	ft_img_init(t_img *img, t_mlx *mlx);
void	ft_put_img(t_img *img, t_mlx *mlx);

void	ft_init_map(t_map *map);

int		ft_key_handler(int keycode, void *param);

void	ft_draw_map(t_param *param, int change_type);

void	ft_draw_dot(t_img *img, t_xy dot, t_argb color);
void	ft_draw_line_high(t_xyz *st, t_xyz *en, t_img *img, int max_z);
void	ft_draw_line_low(t_xyz *st, t_xyz *en, t_img *img, int max_z);
t_argb	ft_cal_color(double z, int max_z);

void	ft_coordinate_reset(t_map *map);
void	ft_rotate_roll(t_map *map, double angle);
void	ft_rotate_pitch(t_map *map, double angle);
void	ft_rotate_yaw(t_map *map, double angle);
void	ft_rotate_isometric(t_map *map);

void	ft_move_right(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_up(t_map *map);

#endif
