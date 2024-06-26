/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:16:35 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/28 22:04:46 by muabdi           ###   ########.fr       */
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
		return (exit(1), NULL);
	data->height = height;
	data->width = width;
	data->event_connections = NULL;
	data->texture_ptrs = NULL;
	data->img_ptrs = NULL;
	data->stop_loop = false;
	return (data);
}

int	close_window(t_data *data)
{
	if (data)
	{
		data->stop_loop = true;
		free_events(data);
		free_textures(data);
		free_images(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
	}
	exit(EXIT_SUCCESS);
}
