/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:16:35 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 01:52:23 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*open_window(int width, int height, char *title)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->win_ptr)
		return (close_window(data), NULL);
	data->height = height;
	data->width = width;
	data->event_connections = NULL;
	data->sprite_ptrs = NULL;
	data->animations = NULL;
	data->img_ptrs = NULL;
	return (data);
}

int	close_window(t_data *data)
{
	if (data)
	{
		free_events(data);
		free_sprites(data);
		free_images(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
	}
	exit(EXIT_SUCCESS);
}
