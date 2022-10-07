/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:40:58 by rjeong            #+#    #+#             */
/*   Updated: 2022/10/06 21:42:14 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_adjustment_value.h"

void	ft_img_init(t_img *img, t_mlx *mlx)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, VW, VH);
	img->img_adr = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->width, &img->endian);
}

void	ft_img_reset(t_img *img, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	ft_img_init(img, mlx);
}

void	ft_put_img(t_img *img, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}
