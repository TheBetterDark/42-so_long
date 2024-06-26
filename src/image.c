/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:13:02 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:51:20 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	create_image(t_window *mlx_window, int w, int h)
{
	t_image	image;

	image.img_ptr = mlx_new_image(mlx_window->mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, &image.line_len,
			&image.endian);
	image.h = h;
	image.w = w;
	return (image);
}

void	destroy_image(t_image *image)
{
	mlx_destroy_image(image->win.mlx_ptr, image->img_ptr);
}
