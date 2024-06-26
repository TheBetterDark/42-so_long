/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/21 22:36:04 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_image	*bgd;
	t_mlx	*mlx;

	mlx = open_window(300, 300, "so_long");
	if (!mlx->mlx_ptr || !mlx->win_ptr)
		return (1);
	bgd = render_background(mlx, create_rgb(255, 255, 255));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, bgd->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
