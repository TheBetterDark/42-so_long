/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:16:35 by muabdi            #+#    #+#             */
/*   Updated: 2024/06/06 19:56:07 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_data	*open_window(int width, int height, char *title, void *f)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->error_handler = f;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (close_window(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
	if (!data->win_ptr)
		return (close_window(data), NULL);
	data->height = height;
	data->width = width;
	return (data);
}

int	close_window(t_data *data)
{
	if (!data)
		return (-1);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	return (0);
}
