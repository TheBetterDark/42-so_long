/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/17 21:45:49 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_window	mlx_window;
	t_image		image;

	mlx_window = open_window(1280, 900, "so_long");
	if (!mlx_window.mlx_ptr || !mlx_window.win_ptr)
		return (1);
	{
		image = create_image(&mlx_window, 1280, 900);
		mlx_destroy_image(mlx_window.mlx_ptr, image.img_ptr);
	}
	mlx_hook(mlx_window.win_ptr, 17, 0, close_window, &mlx_window);
	mlx_loop(mlx_window.mlx_ptr);
	return (0);
}
