/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muabdi <muabdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:56:09 by muabdi            #+#    #+#             */
/*   Updated: 2024/05/24 00:21:09 by muabdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*create_sprite(t_data *data, char *file_name, t_vector2 position)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->xpm_ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_name,
			&sprite->width, &sprite->height);
	if (!sprite->xpm_ptr)
		return (close_window(data), NULL);
	sprite->addr = mlx_get_data_addr(sprite->xpm_ptr, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
	sprite->mlx_ptr = data->mlx_ptr;
	sprite->win_ptr = data->win_ptr;
	ft_lstadd_back(&data->sprite_ptrs, ft_lstnew(sprite));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite->xpm_ptr,
		position.x, position.y);
	return (sprite);
}

void	free_sprites(t_data *data)
{
	ft_lstclear(&data->sprite_ptrs, (void *)free_sprite);
	data->sprite_ptrs = NULL;
}

void	*free_sprite(t_sprite *sprite)
{
	if (sprite->xpm_ptr)
		mlx_destroy_image(sprite->mlx_ptr, sprite->xpm_ptr);
	free(sprite);
	sprite = NULL;
	return (NULL);
}
