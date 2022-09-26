/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_ctrl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:40:58 by rjeong            #+#    #+#             */
/*   Updated: 2022/09/26 12:40:59 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image_init(t_img *img, t_mlx *mlx)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, VW, VH);
	img->img_addr = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->size_line, &img->endian);
}
