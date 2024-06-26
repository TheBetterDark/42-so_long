/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:48:31 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/23 01:00:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_image	*background;
	t_data	*data;

	data = open_window(300, 300, "so_long");
	if (!data->mlx_ptr || !data->win_ptr)
		return (EXIT_FAILURE);
	background = render_background(data, create_rgb(255, 0, 0));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, background->img_ptr,
		0, 0);
	connect_event(KEY_EVENT, KEY_ESC, escape_pressed, data);
	connect_event(KEY_EVENT, KEY_W, w_pressed, data);
	connect_event(KEY_EVENT, KEY_A, a_pressed, data);
	connect_event(KEY_EVENT, KEY_S, s_pressed, data);
	connect_event(KEY_EVENT, KEY_D, d_pressed, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_key_event, data);
	// mlx_mouse_hook(data->win_ptr, on_mouse_event, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, close_window, data);
	mlx_loop(data->mlx_ptr);
	close_window(data);
}
