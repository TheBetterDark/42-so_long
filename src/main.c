/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 03:12:36 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_image		*background;
	t_sprite	*sprite;
	t_data		*data;

	data = open_window(300, 300, "so_long");
	if (!data->mlx_ptr || !data->win_ptr)
		return (EXIT_FAILURE);
	background = render_background(data, create_rgb(0, 0, 0));
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	close_window(data);
}
