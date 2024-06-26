/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:41:50 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/21 22:38:05 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*render_background(t_mlx *mlx, int colour)
{
	t_image	*image;
	int		x;
	int		y;

	y = 0;
	image = create_image(mlx, mlx->width, mlx->height);
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			set_pixel_in_image(image, x, y, colour);
			x++;
		}
		y++;
	}
	return (image);
}
