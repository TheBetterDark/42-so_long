/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:56:09 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/25 19:34:57 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	*create_texture(t_data *data, char *file_name, t_vector2 position)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_name,
			&texture->width, &texture->height);
	if (!texture->xpm_ptr)
		return (close_window(data), NULL);
	texture->addr = mlx_get_data_addr(texture->xpm_ptr, &texture->bpp,
			&texture->line_len, &texture->endian);
	texture->mlx_ptr = data->mlx_ptr;
	texture->win_ptr = data->win_ptr;
	ft_lstadd_back(&data->texture_ptrs, ft_lstnew(texture));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture->xpm_ptr,
		position.x, position.y);
	return (texture);
}

void	free_textures(t_data *data)
{
	ft_lstclear(&data->texture_ptrs, (void *)free_texture);
	data->texture_ptrs = NULL;
}

void	*free_texture(t_texture *texture)
{
	if (texture->xpm_ptr)
		mlx_destroy_image(texture->mlx_ptr, texture->xpm_ptr);
	free(texture);
	texture = NULL;
	return (NULL);
}
